#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define int long long
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(1<<n, vector<int>(n, 0));
    dp[1][0] = 1;
    for(int i=2; i<(1<<n); i++){
        if(!(i & 1)) continue;
        if(i & (1<<(n-1)) && i != (1<<n)-1) continue;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                for(int k : adj[j]){
                    if(i & (1<<k)){
                        dp[i][j] += dp[i^(1<<j)][k];
                        dp[i][j] %= 1000000007;
                    }
                }
                // for(int k=0; k<n; k++){
                //     if(k != j && (i & (1<<k)) && adj[k].find(j) != adj[k].end()){
                //         dp[i][j] += dp[i^(1<<j)][k];
                //         dp[i][j] %= 1000000007;
                //         // break;
                //     }
                // }
                
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << endl;
}