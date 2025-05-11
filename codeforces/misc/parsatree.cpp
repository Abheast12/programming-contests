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

void dfs(int node, int parent, vector<vector<int>>&adj, vector<pair<int, int>>&v, vector<vector<int>>&dp){
    // int mod = 1e9 + 7;
    bool isLeaf = true;
    int tot1 =0, tot2=0;
    for(auto child: adj[node]){
        if(child == parent) continue;
        isLeaf = false;
        dfs(child, node, adj, v, dp);
        tot1 += max(abs(v[node].first - v[child].first) + dp[child][0], abs(v[node].first - v[child].second) + dp[child][1]);
        tot2 += max(abs(v[node].second - v[child].first) + dp[child][0], abs(v[node].second - v[child].second) + dp[child][1]);
    }
    if(isLeaf){
        dp[node][0] = 0;
        dp[node][1] = 0;
        return;
    }
    dp[node][0] = tot1;
    dp[node][1] = tot2;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i].first >> v[i].second;
        }
        vector<vector<int>>adj(n+1);
        for(int i=0; i<n-1; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        dfs(1, -1, adj, v, dp);
        // int mod = 1e9 + 7;
        int ans = max(dp[1][0], dp[1][1]);
        cout << ans << endl;
    }
    
}