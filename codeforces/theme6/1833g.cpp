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
int dfs(int u, int p, vector<vector<pair<int, int>>>&adj, vector<int>&ans){
    // -1 not possible, 0 leaf, 1 cut edge, 2 degenerate
    vector<int>leaves;
    // cout << u << endl;
    vector<int>deg;
    for(auto [v, i]: adj[u]){
        if(v == p) continue;
        int res = dfs(v, u, adj, ans);
        // cout << u << " " << v << " " << res << endl;
        if(res == -1) return -1;
        else if(res == 0){
            leaves.push_back(i);
        }
        else if(res == 2){
            deg.push_back(i);
        }
        else{
            ans.push_back(i);
        }
    }
    // if(adj[u].size() == 1 && u != 0){
    //     return 0;
    // }
    if((deg.size()>0 && leaves.size() > 0) || deg.size() > 1){
        return -1;
    }
    else if(deg.size() == 1){
        return 1;
    }
    if(leaves.size() == 2){
        return 1;
    }
    if(leaves.size() == 1){
        return 2;
    }
    if(leaves.size() == 0){
        return 0;
    }
    return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<pair<int ,int>>>adj(n);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back({v, i+1});
            adj[v].push_back({u, i+1});
        }
        vector<int>ans;
        int res = dfs(0, -1, adj, ans);
        if(res == -1 || n%3 != 0){
            cout << -1 << endl;
        }
        else{
            cout << ans.size() << endl;
            for(int i=0; i<ans.size(); i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }
}