#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<cmath>
#define int long long
using namespace std;  

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>v(3, vector<int>(n+1, 0));
        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++){
                cin >> v[i][j];
            }
        }
        vector<vector<int>>dp(1<<3, vector<int>(n+1, 0));
        for (int x = 0; x < 3; x++) {
            dp[1<<x][0] = v[x][0];
        }
        for (int d = 1; d < n; d++) {
            for (int s = 0; s < (1<<3); s++) {
                dp[s][d] = dp[s][d-1];
                for (int x = 0; x < 3; x++) {
                    if (s&(1<<x)) {
                        dp[s][d] = max(dp[s][d],dp[s^(1<<x)][d-1]+v[x][d]);
                    }
                }
            }
        }
        // for(int i=1; i<=n; i++){
        //     for(int mask=0; mask<(1<<3); mask++){
        //         dp[mask][i] = max(dp[mask][i], dp[mask][i-1]);
        //         for(int j=0; j<3; j++){
        //             if(mask & (1<<j)){
        //                 dp[mask][i] = max(dp[mask][i], dp[mask^(1<<j)][i] + v[j][i]);
        //             }
        //         }
        //     }
        // }
        // for(int i=0; i<8; i++){
        //     for(int j=1; j<=n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[7][n-1] << endl;
    }
}