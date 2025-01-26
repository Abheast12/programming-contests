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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        vector<int>b(n+1);
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=1; i<=n; i++){
            cin >> b[i];
            adj[i].push_back({b[i], a[i-1]});
        }
        for(int i=2; i<=n; i++){
            adj[i].push_back({i-1, 0});
        }
        vector<int>dist(n+1, 1e18);
        dist[1] = 0;  
        map<int, int>vis; 
        priority_queue<pair<int, int>>pq;
        pq.push({0, 1});
        while(!pq.empty()){
            int d = -1*pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]){
                continue;
            }
            vis[node] = 1;
            dist[node] = d;
            for(auto x: adj[node]){
                int next = x.first;
                int w = x.second;
                if(!vis[next]){
                    pq.push({-1*(d+w), next});
                }
            }
        }
        vector<int>pre(n+1, 0);
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] + a[i-1];
        }
        int ans =0;
        for(int i=1; i<=n; i++){
            ans = max(ans, pre[i] - dist[i]);
        }
        cout << ans << endl;
    }
}