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
int tot;
void dfs(int cur, int par, vector<vector<int>>&adj, vector<int>&dp, vector<pair<int, int>>&v){
    int tmp = 0;
    for(auto x: adj[cur]){
        if(x != par){
            dfs(x, cur, adj, dp, v);
            tmp = max(dp[x], tmp);
        }
    }
    tmp = max(tmp, v[cur].first);
    dp[cur] = min(tmp, v[cur].second);
}
void dfs2(int cur, int par, vector<vector<int>>&adj, vector<int>&dp){
    
    for(auto x: adj[cur]){
        if(x != par){
            dfs2(x, cur, adj, dp);
            if(dp[x] > dp[cur]){
                tot+=dp[x]-dp[cur];
            }
        }
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        vector<pair<int, int>>v(n+1);
        for(int i=1; i<=n; i++){
            int l,r;
            cin >> l >> r;
            v[i] = {l, r};
        }
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;  
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>dp(n+1, 0);
        dfs(1, 0, adj, dp, v);
        tot = dp[1];
        dfs2(1, 0, adj, dp);
        cout << tot << endl;
    }
}