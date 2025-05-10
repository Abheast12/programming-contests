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

int runBFS(int cur, vector<vector<int>>&adj, vector<int>&vis){
    queue<pair<int, int>>q;
    q.push({cur, 0});
    int nd = -1;
    int best = -1;
    vector<int>tmpvis = vis;
    
    while(!q.empty()){
        // cout << q.front().first << " " << q.front().second << endl;
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(tmpvis[node] == 1){
            continue;
        }
        if(dist > best){
            best = dist;
            nd = node;
        }
        else if(dist == best){
            nd = max(nd, node);
        }
        tmpvis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            // cout << node << " " << adj[node][i] << endl;
            if(tmpvis[adj[node][i]] == 0){
                q.push({adj[node][i], dist+1});
            }
        }
    }
    return nd;
}

bool runDFS(int cur, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path, int dest){
    
    vis[cur] =1;
    path.push_back(cur);
    if(cur == dest){
        return true;
    }
    for(int i=0; i<adj[cur].size(); i++){
        if(vis[adj[cur][i]] == 0){
            
            bool gg = runDFS(adj[cur][i], adj, vis, path, dest);
            if(gg){
                return true;
            }
            else{
                path.pop_back();
            }
        }
    }
    vis[cur] = 0;
    return false;
}

vector<int> getDiameter(vector<vector<int>>&adj, vector<int>&vis){
    int cur =-1;
    for(int i=1; i<=adj.size(); i++){
        if(vis[i] == 0){
            cur = i;
            break;
        }
    }
    // cout << cur << endl;
    int n1 = runBFS(cur, adj, vis);
    int n2 = runBFS(n1, adj, vis);
    // cout  << n1 << " " << n2 << endl;
    if(n2 > n1){
        swap(n1, n2);
    }
    // vector<int>diameter;
    vector<int>path;
    runDFS(n1, adj, vis, path, n2);
    return path;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        for(int i=0; i<n-1; i++){
            int u,v;
            cin >> u >>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // for(auto it: adj[1]){
        //     cout << it << " ";
        // }
        // cout << endl;

        int ct =0;
        vector<int>vis(n+1, 0);
        vector<int>ans;
        
        while(ct < n){
            vector<int>diameter = getDiameter(adj, vis);
            ans.push_back(diameter.size());
            ans.push_back(diameter[0]);
            ans.push_back(diameter[diameter.size()-1]);
            for(int i=0; i<diameter.size(); i++){
                vis[diameter[i]] = 1;
            }
            ct += diameter.size();
        }
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        
        

    }
}