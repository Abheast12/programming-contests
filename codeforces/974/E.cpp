#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;
void bfs(vector<vector<pair<int, long long>>>&adj, vector<vector<long long>>&dist, map<pair<int, int>, int>&vis, int start, vector<int>&horses){
    priority_queue<pair<pair<long long, int>, int>>pq;
    if(horses[start]){
        pq.push({{0, start}, 1});
    }
    else{
        pq.push({{0, start}, 0});
    }
    dist[start][horses[start]] = 0;
    // cout << "start: " << start << endl;
    while(!pq.empty()){
        
        long long d = -1*pq.top().first.first;
        int cur  = pq.top().first.second;
        int horse = pq.top().second;
        // cout << cur << endl;
        pq.pop();
        if(vis[{cur, horse}]) continue;
        vis[{cur, horse}] = 1;
        if(dist[cur][horse] < d) continue;
        dist[cur][horse] = d;
        // if(horses[cur]){
        //     horse =1;
        // }
        // long long min_dist = min(dist[cur][1], dist[cur][0]);
        for(auto p: adj[cur]){
            // cout << cur << " " << p.first << " " << p.second << endl;
            int next = p.first;
            long long w = p.second;
            if(horse){
                if(!vis[{next, 1}] && dist[next][1] > d + w/2){
                    long long new_dist = d + w/2;
                    pq.push({{-1*new_dist, next}, 1});
                }
            }
            else{
                if(!vis[{next, 0}] && dist[next][0] > d + w){
                    long long new_dist = d + w;
                    pq.push({{-1*new_dist, next}, 0});
                }
                if(horses[cur] == 1){
                    if(!vis[{next, 1}] && dist[next][1] > d + w/2){
                        long long new_dist = d + w/2;
                        pq.push({{-1*new_dist, next}, 1});
                    }
                }
            }
        }

    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, h;
        cin >> n >> m >> h;
        vector<int>horses(n+1);
        for(int i=0; i<h; i++){
            int tmp;
            cin >> tmp;
            horses[tmp] = 1;
        }
        vector<vector<pair<int, long long>>>adj(n+1);
        for(int i=0;i<m; i++){
            int a, b;
            long long c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        vector<vector<long long>>dist(n+1, vector<long long>(2, 1e18));
        vector<vector<long long>>dist2(n+1, vector<long long>(2, 1e18));
        
        map<pair<int, int>, int>vis;
        map<pair<int, int>, int>vis2;
        bfs(adj, dist, vis, 1, horses);
        bfs(adj, dist2, vis2, n, horses);
        long long ans = 1e18;
        for(int i=1; i<=n; i++){
            long long min_dist1 = min(dist[i][0], dist[i][1]);
            long long min_dist2 = min(dist2[i][0], dist2[i][1]);
            ans = min(ans, max(min_dist1, min_dist2));
            // cout << i << endl;
            // cout << dist[i][0] << " " << dist[i][1] << endl;
            // cout << dist2[i][0] << " " << dist2[i][1] << endl;
        }
        if(ans == 1e18) cout << -1 << endl;
        else cout << ans << endl;
    }
}