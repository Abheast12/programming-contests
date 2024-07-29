#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        if(k%2!=0){
            cout << "NO" << endl;
        }
        else{
            bool flag = false;
            // long long dif = 0;
            vector<int>ans(n);
            for(int i=0; i<n; i++){
                ans[i] = i+1;
            }
            // set<pair<int ,int>>s;
            // vector<pair<int,int>>v;
            // for(int i=n-1; i>=n/2+1; i--){
            //     if(k>=v[i])
            // }
            for(int i=1; i<=(n/2)+1; i++){
                long long ed = n-i+1;
                if(k/2+i<=ed){
                    swap(ans[i-1], ans[i-1+k/2]);
                    k = 0;
                    break;
                }
                long long dif = 2*(n-2*i+1);
                if(k>dif){
                    k-=dif;
                    swap(ans[i-1], ans[ed-1]);
                }
                else if(k==dif){
                    swap(ans[i-1], ans[ed-1]);
                    k-=dif;
                    break;
                }
                else{
                    break;
                }
            }
            if(k==0){
                cout << "YES" << endl;
                for(int i=0; i<n; i++){
                    cout << ans[i] << " ";
                }
                cout << endl;
            }
            else{
                cout << "NO" << endl;
            }
            // while(k>0){
            //     if(s.empty()){
            //         break;
            //     }
            //     auto it = lower_bound(s.begin(), s.end(), make_pair(k, -1));
            //     if(it == s.end()){
            //         it--;
            //         k-=(*it).first;
            //         swap(ans[(*it).second], ans[n-((*it).second+1)]);
            //         s.erase(it);
            //     }
            //     else if((*it).first > k){
            //         if(it == s.begin()){
            //             break;
            //         }
            //         else{
            //             it--;
            //             k-=(*it).first;
            //             swap(ans[(*it).second], ans[n-((*it).second+1)]);
            //             s.erase(it);
            //         }
            //     }
            //     else{
            //         flag = true;
            //         k-=(*it).first;
            //         swap(ans[(*it).second], ans[n-((*it).second+1)]);
            //     }
            // }
            // for(int i=0; i<n; i++){
            //     long long dif = 2*i*(n-i);
            //     if(dif == k){
            //         cout << "YES" << endl;
            //         for(int j=0; j<n; j++){
            //             cout << (j+i)%n+1 << " ";
            //         }
            //         cout << endl;
            //         flag = true;
            //         break;
            //     }
                
            // }
            // if(!flag){
            //     cout << "NO" << endl;
            // }
            // else{
            //     cout << "YES" << endl;
            //     for(int i=0; i<n; i++){
            //         cout << ans[i] << " ";
            //     }
            //     cout << endl;
            // }
            ans.clear();
            // s.clear();
        }
    }
}