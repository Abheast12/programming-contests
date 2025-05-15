#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;  

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>>v(n);
        vector<vector<int>>adj(n+1);
        int lidx =-1;
        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v[i] = {i, a};
            if(a==-1){
                lidx = i;
            }
        }
        int ct = 1;
        int l = 1, r = n;
        vector<int>ans(n);
        while(l<r){
            if(ct%2==1){
                for(int i=0; i<lidx; i++){
                    if(v[i].second == ct){
                        ans[v[i].first] = r;
                        r--;
                    }
                }
                for(int i=n-1; i>lidx; i--){
                    if(v[i].second == ct){
                        ans[v[i].first] = r;
                        r--;
                    }
                }
            }
            else{
                for(int i=0; i<lidx; i++){
                    if(v[i].second == ct){
                        ans[v[i].first] = l;
                        l++;
                    }
                }
                for(int i=n-1; i>lidx; i--){
                    if(v[i].second == ct){
                        ans[v[i].first] = l;
                        l++;
                    }
                }
            }
            ct++;
        }
        ans[lidx] = l;
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        // map<int, int>mp;
        // while(v.size() > 1){
        //     vector<pair<int, int>>temp;
        //     for(int i=0; i<v.size(); i++){
        //         if(ct%2==1){
        //             if(v[i].second != ct){
        //                 if(i-1>=0){
        //                     adj[v[i-1].first].push_back(v[i].first);
        //                     mp[v[i].first] = 1;
        //                 }
        //                 if(i+1<v.size()){
        //                     adj[v[i+1].first].push_back(v[i].first);
        //                     mp[v[i].first] = 1;
        //                 }
        //                 temp.push_back(v[i]);
        //             }
        //             else if(i==0 && v[i].second == ct){
        //                 adj[v[i].first].push_back(v[i+1].first);
        //                 mp[v[i+1].first] = 1;
        //             }
        //             else if(i==v.size()-1 && v[i].second == ct){
        //                 adj[v[i].first].push_back(v[i-1].first);
        //                 mp[v[i-1].first] = 1;
        //             }
        //         }
        //         else{
        //             if(v[i].second != ct){
        //                 if(i-1>=0){
        //                     adj[v[i].first].push_back(v[i-1].first);
        //                     mp[v[i-1].first] = 1;
        //                 }
        //                 if(i+1<v.size()){
        //                     adj[v[i].first].push_back(v[i+1].first);
        //                     mp[v[i+1].first] = 1;
        //                 }
        //                 temp.push_back(v[i]);
        //             }
        //             else if(i==0 && v[i].second == ct){
        //                 adj[v[i+1].first].push_back(v[i].first);
        //                 mp[v[i].first] = 1;
        //             }
        //             else if(i==v.size()-1 && v[i].second == ct){
        //                 adj[v[i-1].first].push_back(v[i].first);
        //                 mp[v[i].first] = 1;
        //             }
        //         }
        //     }
        //     v = temp;
        //     ct++;
        // }
        // map<int, int>depths;
        // queue<pair<int, int>>q;
        // for(int i=0;i<n; i++){
        //     if(mp[i] == 0){
        //         q.push({i, 0});
        //         depths[i] = 0;
        //     }
        // }
        // while(!q.empty()){
        //     auto [node, depth] = q.front();
        //     q.pop();
        //     depths[node] = depth;
        //     for(auto child: adj[node]){
        //         q.push({child, depth + 1});
        //     }
        // }
        // vector<pair<int, int>>ans;
        // for(auto [node, depth]: depths){
        //     ans.push_back({depth, node});
        // }
        // sort(ans.begin(), ans.end());
        // int cur = n;
        // vector<int>final(n);
        // for(int i=0; i<ans.size(); i++){
        //     final[ans[i].second] = cur;
        //     cur--;
        // }
        // for(int i=0; i<n; i++){
        //     cout << final[i] << " ";
        // }
        // cout << endl;

    }
}