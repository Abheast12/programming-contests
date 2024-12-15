#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<long long>a(n);
        vector<long long>b(m);
        vector<long long>sums(n+1, 0);
        vector<vector<long long>>dp(n+1, vector<long long>(m+1, 1e18));
        vector<vector<long long>>ways(n+1, vector<long long>(m+1, 0));

        for(int i=0; i<n; i++){
            cin >> a[i];
            sums[i+1] = sums[i] + a[i];
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
            // dp[0][i] = 0;
        }
        dp[0][0] = 0;
        ways[0][0] = 1;
        long long mod = 1e9+7;
        for(int i=0; i<=n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j] < dp[i][j+1]){
                    dp[i][j+1] = dp[i][j];
                    ways[i][j+1] = ways[i][j];
                }
                else if(dp[i][j] == dp[i][j+1]){
                    ways[i][j+1] += ways[i][j];
                }
                ways[i][j+1] %= mod;
                // dp[i][j+1] = min(dp[i][j], dp[i][j+1]);

                auto it = upper_bound(sums.begin(), sums.end(), b[j]+sums[i]);
                --it;
                int idx = distance(sums.begin(), it);
                // dp[idx][j] = min(dp[idx][j], dp[i][j] + m-(j+1));
                if(idx > i){
                    cout << "idx: " << idx << " i: " << i << " j: " << j << endl;
                    if(dp[idx][j] > dp[i][j] + m-(j+1)){
                        dp[idx][j] = dp[i][j] + m-(j+1);
                        ways[idx][j] = ways[i][j];
                    }
                    else if(dp[idx][j] == dp[i][j] + m-(j+1)){
                        ways[idx][j] += ways[i][j];
                    }
                    ways[idx][j] %= mod;
                }
            }
        }

        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<=m; j++){
        //         cout << "(" << dp[i][j] << ", " << ways[i][j] << "), ";
        //     }
        //     cout << endl;
        // }

        if(dp[n][m] == 1e18) cout << -1 << endl;
        else cout << dp[n][m] << " " << ways[n][m] << endl;
        a.clear();
        b.clear();
        sums.clear();
        dp.clear();
        ways.clear();
    }
}