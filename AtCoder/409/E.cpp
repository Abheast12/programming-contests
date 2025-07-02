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

void dfs(int cur, int par, vector<vector<pair<int, int>>>&adj, vector<pair<int, int>>&dp){
    for(pair<int, int>p : adj[cur]){
        if(p.first == par) continue;
        dfs(p.first, cur, adj, dp);
        dp[cur].first += dp[p.first].first;
        dp[cur].second += dp[p.first].second + p.second*abs(dp[p.first].first);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }    
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=0; i<n-1; i++){
        int a,b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<pair<int, int>>dp(n+1, {0, 0});
    for(int i=1; i<=n; i++){
        dp[i].first = v[i];
    }
    dfs(1, 0, adj, dp);
    cout << dp[1].second << endl;

}