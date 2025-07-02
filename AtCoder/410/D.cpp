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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }    
    int ans = 1e5;
    queue<pair<int, int>>q;
    map<pair<int,int>, int>vis;
    q.push({1, 0});
    while(!q.empty()){
        
        int u = q.front().first;
        int d = q.front().second;
        // cout << u << " " << d << endl;
        q.pop();
        if(vis[{d, u}]){
            continue;
        }
        else vis[{d, u}] = 1;
        if(u == n){
            ans = min(ans, d);
        }
        for(pair<int, int> p : adj[u]){
            int v = p.first;
            int w = p.second;
            if(!vis[{(d^w), v}]){
                q.push({v, (d^w)});
            }
        }
    }
    if(ans == 1e5){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }

}