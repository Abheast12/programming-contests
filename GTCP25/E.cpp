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
        int n, m, k;
        cin >> n >> m >> k;
        // vector<int>v(n);
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        vector<int>flights(n+1);
        for(int i=1; i<=n; i++){
            cin >> flights[i];
        }
        vector<int>dist(n+1, 1e18);
        vector<int>vis(n+1, 0);
        // dist[1] = 0;
        priority_queue<pair<int, int>>pq;
        pq.push({0, n});
        while(!pq.empty()){
            int a = pq.top().second;
            int b = pq.top().first;
            pq.pop();
            if(vis[a]){
                continue;
            }
            vis[a] = 1;
            dist[a] = -1*b;
            for(int i=0; i<adj[a].size(); i++){
                if(!vis[adj[a][i].first]){
                    int newdist = -1*b + adj[a][i].second;
                    pq.push({-1*newdist, adj[a][i].first});
                }
            }
        }
        if(k==0){
            cout << dist[1] << endl;
        }
        else{
            int ans = dist[1];
            for(int i=1; i<=n; i++){
                int tmp = dist[i] + abs(flights[i] - flights[1]);
                ans = min(ans, tmp);
            }
            cout << ans << endl;
        }


    }
}