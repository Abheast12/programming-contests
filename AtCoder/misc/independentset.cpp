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

void dfs(int node, int parent, vector<vector<int>>&adj, vector<vector<int>>&dp){
    int mod = 1e9 + 7;
    bool isLeaf = true;
    int tot1 =1, tot2=1;
    for(auto child: adj[node]){
        if(child == parent) continue;
        isLeaf = false;
        dfs(child, node, adj, dp);
        tot1 = (tot1*dp[child][0])%mod;
        tot2 = (tot2*(dp[child][0] + dp[child][1]))%mod;
    }
    if(isLeaf){
        dp[node][0] = 1;
        dp[node][1] = 1;
        return;
    }
    dp[node][0] = tot2;
    dp[node][1] = tot1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>>dp(n+1, vector<int>(2, 0));
    dfs(1, -1, adj, dp);
    int mod = 1e9 + 7;
    int ans = (dp[1][0] + dp[1][1])%mod;
    cout << ans << endl;
}