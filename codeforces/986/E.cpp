#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(int i=0; i<n-1; i++){
            int x, y;
            cin >> x >> y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        vector<int>dist_top(n, -1);
        vector<int>dist_bottom(n, -1);
        queue<pair<int,int>>q;
        for(int i=1; i<n; i++){
            if(adj[i].size() == 1){
                // cout << i << endl;
                q.push({i, 0});
            }
        }
        
        vector<int>vis_bottom(n, 0);
        vector<int>vis_top(n, 0);
        while(!q.empty()){
            pair<int,int>curr = q.front();
            q.pop();
            if(vis_bottom[curr.first]){
                continue;
            }
            vis_bottom[curr.first] = 1;
            if(dist_bottom[curr.first] == -1){
                dist_bottom[curr.first] = curr.second;
            }
            
            for(int i=0; i<adj[curr.first].size(); i++){
                if(!vis_bottom[adj[curr.first][i]]){
                    q.push({adj[curr.first][i], curr.second+1});
                }
            }
        }
        vector<long long>numerator(n, 0);
        vector<long long>denominator(n, 0);
        numerator[0] = 1;
        denominator[0] = 1;
        q.push({0, -1});
        while(!q.empty()){
            pair<int, int>curr = q.front();
            q.pop();
            if(vis_top[curr.first]){
                continue;
            }
            vis_top[curr.first] = 1;
            // if(dist_top[curr.first] == -1){
            //     dist_top[curr.first] = curr.second;
            // }

            for(int i=0; i<adj[curr.first].size(); i++){
                if(!vis_top[adj[curr.first][i]]){
                    q.push({adj[curr.first][i], curr.first});
                }
            }
            if(curr.first ==0){
                continue;
            }
            if(dist_bottom[curr.first] == 0){
                numerator[curr.first] = 0;
                denominator[curr.first] = 1;
            }
            else{
                // long long dif = dist_bottom[curr.first] - 1;
                // long long temp = 1;
                // long long base = 2;
                // while(dif){
                //     if(dif%2){
                //         temp = (temp*base)%998244353;
                //     }
                //     base = (base*base)%998244353;
                //     dif = dif >> 1;
                // }
                // long long new_numerator = (numerator[curr.second]*temp)%998244353;
                // long long new_denominator = (denominator[curr.second]*(temp+1))%998244353;
                long long new_numerator = (numerator[curr.second]*dist_bottom[curr.first])%998244353;
                long long new_denominator = (denominator[curr.second]*(dist_bottom[curr.first]+1))%998244353;
                long long g = gcd(new_numerator, new_denominator);
                new_numerator = new_numerator/g;
                new_denominator = new_denominator/g;
                numerator[curr.first] = new_numerator;
                denominator[curr.first] = new_denominator;
            }
        }
        // cout << "here" << endl;
        long long mod = 998244353;
        vector<long long>ans(n, 0);
        for(int i=0; i<n; i++){
            if(i==0){
                ans[i] =1;
            }
            else if(adj[i].size()==1){
                ans[i] = 0;
            }
            else{
                long long pow = mod-2;
                long long temp = 1;
                long long qq = denominator[i];
                long long p = numerator[i];
                while(pow){
                    if(pow%2){
                        temp = (temp*qq)%mod;
                    }
                    qq = (qq*qq)%mod;
                    pow = pow >> 1;
                }
                temp = (temp*p)%mod;
                ans[i] = temp;



                // if(dist_top[i] == dist_bottom[i]){
                //     long long pow = mod-2;
                //     long long temp = 1;
                //     long long base = 2;
                //     while(pow){
                //         if(pow%2){
                //             temp = (temp*base)%mod;
                //         }
                //         base = (base*base)%mod;
                //         pow = pow >> 1;
                //     }
                //     ans[i] = temp;
                // }
                // else if (dist_top[i] < dist_bottom[i]){
                //     long long pow = mod-2;

                //     long long dif = dist_bottom[i] - dist_top[i];
                //     long long temp = 1;
                //     long long base = 2;
                //     while(dif){
                //         if(dif%2){
                //             temp = (temp*base)%mod;
                //         }
                //         base = (base*base)%mod;
                //         dif = dif >> 1;
                //     }
                //     long long p = temp;
                //     long long qq = temp+1;
                //     temp = 1;
                //     while(pow){
                //         if(pow%2){
                //             temp = (temp*qq)%mod;
                //         }
                //         qq = (qq*qq)%mod;
                //         pow = pow >> 1;
                //     }
                //     temp = (temp*p)%mod;
                //     ans[i] = temp;
                // }
                // else{
                //     long long pow = mod-2;

                //     long long dif = dist_top[i] - dist_bottom[i];
                //     long long temp = 1;
                //     long long base = 2;
                //     while(dif){
                //         if(dif%2){
                //             temp = (temp*base)%mod;
                //         }
                //         base = (base*base)%mod;
                //         dif = dif >> 1;
                //     }
                //     long long qq = temp+1;
                //     temp = 1;
                //     while(pow){
                //         if(pow%2){
                //             temp = (temp*qq)%mod;
                //         }
                //         qq = (qq*qq)%mod;
                //         pow = pow >> 1;
                //     }
                //     ans[i] = temp;
                // }
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}