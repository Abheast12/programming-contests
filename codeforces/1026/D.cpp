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
bool check2(vector<vector<pair<int, int>>>&adj, vector<int>&b, int n, int x){
    vector<int>dist(n+1, -1);
    dist[1] = min(b[1], x);
    for(int i=1; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            int child = adj[i][j].first;
            int w = adj[i][j].second;
            if(w > dist[i]){
                continue;
            }
            dist[child] = max(dist[child], min(x, dist[i]+b[child]));
        }
    }
    if(dist[n] == -1){
        return false;
    }
    return true;
    // vector<bool>visited(n+1, false);
    // queue<pair<int ,int>>q;
    // // vector<int>dist(n+1, 1e18);
    // vector<vector<pair<int, int>>>newadj(n+1);
    // q.push({0, 1});
    // while(!q.empty()){
    //     int d = q.front().first;
    //     int node = q.front().second;
    //     q.pop();
    //     // if(visited[node])continue;
    //     // visited[node] = true;
    //     // dist[node] = d;
    //     for(pair<int,int>x: adj[node]){
    //         int child =x.first;
    //         int w = x.second;
    //         if(d+b[node] >= w){
    //             newadj[child].push_back({node, w});
    //             q.push({d+b[node], child});
    //         }
    //         // if(!visited[child]){
    //         //     int val = d+b[child]
    //         //     q.push({-1*(d+w), child});
    //         // }
    //     }
    // }
    // return newadj;
}
bool check(vector<vector<pair<int, int>>>&adj, vector<int>&b, int x, int n){
    vector<int>dist(n+1, 1e18);
    dist[n] = 0;
    for(int i=n; i>=2; i--){
        for(int j=0; j<adj[i].size(); j++){
            int child = adj[i][j].first;
            int w = adj[i][j].second;
            dist[child] = min(dist[child], max(dist[i], w));
        }
    }
    if(dist[1] == 1e18){
        return false;
    }
    cout << dist[1] << endl;
    // vector<bool>visited(n+1, false);
    // priority_queue<pair<int ,int>>q;
    // vector<int>dist(n+1, 1e18);
    // q.push({x, n});
    // while(!q.empty()){
    //     int d = -1*q.top().first;
    //     int node = q.top().second;
    //     q.pop();
    //     if(visited[node])continue;
    //     visited[node] = true;
    //     dist[node] = d;
    //     for(pair<int,int>x: adj[node]){
    //         int child =x.first;
    //         int w = x.second;
    //         if(!visited[child]){
    //             int val = max(0LL, d+w-b[child]);
    //             q.push({-1*(val), child});
    //         }
    //     }
    // }
    // if(dist[1] == 0){
    //     return true;
    // }
    // return false;
    return true;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int>b(n+1);
        vector<vector<pair<int, int>>>adj(n+1);
        for(int i=1; i<=n; i++){
            cin >> b[i];
        }
        for(int i=0; i<m; i++){
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            // adj[y].push_back({x, z});
        }
        // vector<vector<pair<int, int>>>newadj = check2(adj, b, n);
        // bool ok = check(newadj, b, 0, n);
        // if(!ok){
        //     cout << -1 << endl;
        // }

        int l = 0;
        int r = 1e18;
        int ans = -1;
        while(l <= r){
            int mid = (l+r)/2;
            if(check2(adj, b, n, mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        cout << ans << endl;

    }
}