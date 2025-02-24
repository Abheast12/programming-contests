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
        int n, k;
        cin >> n >> k;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        map<int, int>fr;
        for(int i=0; i<k; i++){
            int x;
            cin >> x;
            fr[x] = 1;
        }
        vector<vector<int>>adj(n+1);
        vector<vector<int>>adj2(n+1);
        map<int, int>ct;
        for(int i=1; i<=n; i++){
            int x;
            cin >> x;
            ct[i] = x;
            if(fr[i]) ct[i] = 0;
            for(int j=0; j<x; j++){
                int y;
                cin >> y;
                adj[y].push_back(i);
                adj2[i].push_back(y);
            }
        }
        // vector<pair<int, int>>tt;
        // for(int i=1; i<=n; i++){
        //     tt.push_back({ct[i], i});
        // }
        queue<int>q;
        for(int i=1; i<=n; i++){
            if(fr[i]){
                q.push(i);
            }
            else if(ct[i] == 0){
                q.push(i);
            }
        }
        // sort(tt.begin(), tt.end());
        vector<int>dist(n+1, 1e11);
        vector<int>vis(n+1, 0);
        while(!q.empty()){
            // int u = tt[i].second;
            
            int u = q.front();
            // cout << u << endl;
            q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            if(fr[u]){
                dist[u] = 0;
            }
            else {
                dist[u] = v[u];
            }
            for(auto x: adj[u]){
                ct[x]--;
                if(ct[x] == 0){
                    q.push(x);
                }
            }
            if(adj2[u].size() == 0) continue;   
            int tot = 0;
            for(auto x: adj2[u]){
                tot+=dist[x];
            }
            
            dist[u] = min(dist[u], tot);
        }
        // for(int i=1; i<=n; i++){
        //     if(fr[i]){
        //         pq.push({0, i});
        //         dist[i] = 0;
        //     }
        //     else {
        //         pq.push({-1*v[i], i});
        //         dist[i] = v[i];
        //     }
        // }
        // while(!pq.empty()){
        //     int d = pq.top().first;
        //     int u = pq.top().second;
        //     cout << u << " " << d << endl;
        //     d*=-1;
        //     pq.pop();
        //     if(vis[u]) continue;
        //     vis[u] = 1;
        //     dist[u] = min(dist[u], d);
        //     for(auto x: adj[u]){
        //         if(!vis[x]){
        //             pq.push({-1*(dist[u]+v[x]), x});
        //         }
        //     }
        // }
        for(int i=1; i<=n; i++){
            cout << dist[i] << " ";
        }
        cout << endl;

    }
}