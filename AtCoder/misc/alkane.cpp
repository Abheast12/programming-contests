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
void dfs(int cur, int par, vector<vector<int>>&adj, vector<vector<int>>&dp){
    vector<int>child;
    vector<int>child2;
    for(auto x:adj[cur]){
        if(x == par) continue;
        dfs(x, cur, adj, dp);
        child.push_back(dp[x][3]);
        child2.push_back(max(1LL, dp[x][3]));
    }
    int val = 0;
    sort(child.begin(), child.end());
    sort(child2.begin(), child2.end());
    dp[cur][0] = 1;
    if(child.size() >0){
        dp[cur][0] = child[child.size()-1]+1;
    }
    if(child2.size()>=3){
        for(int i=0; i<3; i++){
            val += child2[child2.size()-1-i];
        }
        dp[cur][3] = val+1;
    }
    if(child2.size() >=4){
        dp[cur][4] = val+child2[child2.size()-4]+1;
    }
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>>adj(n+1);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>>dp(n+1, vector<int>(5, 0));
    dfs(1, 0, adj, dp);
    bool flag = false;
    int ans = -1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<5; j++){
            if((j==3 && i!=1) || j==4){
                if(dp[i][j] > 0){
                    flag = true;
                }
            }
            // cout << dp[i][j] << " ";
            ans = max(ans, dp[i][j]);
        }
        // cout << endl;
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;

}