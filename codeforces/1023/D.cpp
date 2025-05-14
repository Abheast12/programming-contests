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

pair<int, vector<int>> runBFS(int cur, vector<vector<int>>&adj, vector<int>&tmpvis, vector<int>&vis, vector<int>&parent){
    queue<pair<int, int>>q;
    q.push({cur, 1});
    int nd = -1;
    int best = -1;
    // vector<int>tmpvis = vis;
    // vector<int>tv= tmpvis;
    // vector<int>mp(adj.size(), -1);
    parent[cur] = -1;  
    while(!q.empty()){
        // cout << q.front().first << " " << q.front().second << endl;
        int node = q.front().first;
        // int par = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        if(vis[node] == 1){
            continue;
        }
        // if(tmpvis[node] == 1){
        //     continue;
        // }
        
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
            if(adj[node][i] != parent[node] && vis[adj[node][i]] == 0){
                parent[adj[node][i]] = node;
                q.push({adj[node][i], dist+1});
            }
        }
    }
    vector<int>path;
    int cur1 = nd;
    while(cur1 != -1){
        path.push_back(cur1);
        cur1 = parent[cur1];
    }
    // if(conserve){
    //     for(int i=0; i<tmpvis.size(); i++){
    //         tmpvis[i] = tv[i];
    //     }
    // }
    return {best, path};
}

// bool runDFS(int cur, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path, int dest){
    
//     vis[cur] =1;
//     path.push_back(cur);
//     if(cur == dest){
//         return true;
//     }
//     for(int i=0; i<adj[cur].size(); i++){
//         if(vis[adj[cur][i]] == 0){
            
//             bool gg = runDFS(adj[cur][i], adj, vis, path, dest);
//             if(gg){
//                 return true;
//             }
//             else{
//                 path.pop_back();
//             }
//         }
//     }
//     vis[cur] = 0;
//     return false;
// }

// vector<int> getDiameter(vector<vector<int>>&adj, vector<int>&vis){
//     int cur =-1;
//     vector<int>tmpvis = vis;
//     vector<pair<int, int>>dms;
//     pair<int, pair<int, int>>bt = {-1, {-1, -1}};
//     for(int i=1; i<adj.size(); i++){
//         if(tmpvis[i] == 0){
//             // cout << i << " " << adj.size() << endl;
//             cur = i;
//             int n1 = runBFS(cur, adj, tmpvis, true).second;
//             pair<int, int>p = runBFS(n1, adj, tmpvis);
//             int n2 = p.second;
//             int dt = p.first;

//             // cout  << n1 << " " << n2 << endl;
//             if(n2 > n1){
//                 swap(n1, n2);
//             }
            
//             // dms.push_back({n1, n2});
//             pair<int, pair<int, int>>p1 = {dt, {n1, n2}};
//             if(p1> bt){
//                 bt = {dt, {n1, n2}};
//             }
//             // cout << n1 << " " << n2 << endl;
//         }
//     }
//     // sort(dms.begin(), dms.end());
//     // int n1 = dms[dms.size()-1].first;
//     // int n2 = dms[dms.size()-1].second;
//     // cout << cur << endl;
//     // cout << n1 << " " << n2 << endl;
//     // vector<int>diameter;
//     vector<int>path;
//     runDFS(bt.second.first, adj, vis, path, bt.second.second);
//     return path;

// }

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
        vector<int>tmpvis(n+1, 0);
        vector<pair<int, pair<int, int>>>ans;
        vector<int>parent(n+1, -1);
        while(ct < n){
            // vector<int>diameter = getDiameter(adj, vis);
            tmpvis.assign(n+1, 0);
            for(int i=1; i<=n; i++){
                if(vis[i] == 0 && tmpvis[i] ==0){
                    pair<int, vector<int>>p1 = runBFS(i, adj, tmpvis, vis, parent);
                    pair<int, vector<int>>p2 = runBFS(p1.second[0], adj, tmpvis, vis, parent);
                    // cout << p2.first << " " << p2.second[0] << " " << p2.second[p2.second.size()-1] << endl;
                    for(auto it: p2.second){
                        vis[it] = 1;
                    }
                    // ans.push_back(p2.first);
                    // ans.push_back(max(p2.second[0], p2.second[p2.second.size()-1]));
                    // ans.push_back(min(p2.second[0], p2.second[p2.second.size()-1]));
                    ans.push_back({p2.first, {max(p2.second[0], p2.second[p2.second.size()-1]), min(p2.second[0], p2.second[p2.second.size()-1])}});
                    ct+=p2.first;
                }
            }
            // ans.push_back(diameter.size());
            // ans.push_back(diameter[0]);
            // ans.push_back(diameter[diameter.size()-1]);
            // for(int i=0; i<diameter.size(); i++){
            //     vis[diameter[i]] = 1;
            // }
            // ct += diameter.size();
        }
        sort(ans.begin(), ans.end(), greater<pair<int, pair<int, int>>>());
        for(int i=0; i<ans.size(); i++){
            cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << " ";
        }
        cout << endl;
        
        

    }
}