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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<vector<int>>dp(n+1, vector<int>(k+1, 1e18));
        // vector<vector<int>>dp2(n+1, vector<int>(k+1, 1e18));
        int sm = 0;
        for(int i=0; i<=k; i++){
            dp[0][i] = 0;
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<=k; j++){
                int mn = 1e18;
                for(int l = i; l>=i-j; l--){
                    mn = min(mn, v[l]);
                    if(l == 0){
                        break;
                    }
                    dp[i][j] = min(dp[i][j], dp[l-1][j-(i-l)]+mn*(i-l+1));
                }
            }
        }
        cout << dp[n][k] << endl;

        // for(int i=1; i<=n; i++){
        //     sm+=v[i];
        //     dp[i][0] = sm;
        //     // dp2[i][0] = v[i];
        // }

        // // cout << "here" << endl;
        // for(int i=1; i<=k; i++){
        //     for(int j=1; j<=n; j++){
        //         // cout << j << " " << i << endl;
        //         dp2[j][i] = v[j];
        //         dp[j][i] = min(dp[j][i-1], dp[j-1][i]+v[j]);
        //         if(j>1){
        //             // int newval = min(dp2[j-1][i-1], v[j]);
        //             if(dp2[j-1][i-1] > v[j]){
        //                 dp[j][i] = min(dp[j][i], dp[j-1][i-1]-dp2[j-1][i-1]+2*v[j]);
        //                 dp2[j][i] = v[j];
        //             }
        //             else{
        //                 if(dp[j-1][i-1]+dp2[j-1][i-1] < dp[j][i]){
        //                     dp2[j][i] = dp2[j-1][i-1];
        //                     dp[j][i] = dp[j-1][i-1]+dp2[j-1][i-1];
        //                 }
        //                 // dp[j][i] = min(dp[j][i], dp[j-1][i-1]+dp2[j-1][i-1]);
                        
        //             }
        //             // dp[j][i] = min(dp[j][i], dp[j-1][i-1]+)
        //         }
        //     }
        //     // cout << "completed" << endl;    
        // }
        // // for(int i=1; i<=n; i++){
        // //     for(int j=0; j<=k; j++){
        // //         cout << dp2[i][j] << " ";
        // //     }
        // //     cout << endl;
        // // }
        // for(int i=1; i<=n; i++){
        //     for(int j=0; j<=k; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << dp[n][k] << endl;
    }
}