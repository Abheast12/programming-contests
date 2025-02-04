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
        int n;
        cin >> n;
        vector<vector<int>>v(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> v[i][j];
            }
        }
        vector<vector<int>>suffixSum(n, vector<int>(n+1));
        multiset<int>streaks;
        for(int i=0; i<n; i++){
            bool tt = false;
            for(int j=n-1; j>=0; j--){
                
                if(v[i][j] != 1){
                    streaks.insert(n-j-1);
                    tt = true;
                    break;
                }
                
            }
            if(!tt){
                streaks.insert(n);
            }
            // suffixSum[i][n] = 0;
            // for(int j=n-1; j>=0; j--){
            //     suffixSum[i][j] = suffixSum[i][j+1] + v[i][j];
            // }
        }
        int ans =0;
        for(int i=0; i<=n; i++){
            auto it = streaks.lower_bound(i);
            if(it == streaks.end()){
                break;
            }
            streaks.erase(it);
            ans++;
        }
        cout << ans << endl;
        // vector<vector<int>>dp(n, vector<int>(n+1));
        // vector<vector<set<int>>>maxi(n, vector<set<int>>(n+1, set<int>()));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = 1;
        // }
        // for(int j=1; j<=n; j++){
        //     dp[0][j] = 0;
        // }
        // set<int>tmp;
        // for(int j=0; j<=n; j++){
        //     tmp.insert(j);
        //     maxi[0][j] = tmp;
        // }
        // for(int i=1; i<n; i++){
            
        //     for(int j=1; j<=n; j++){
        //         dp[i][j] = 0;
        //         int sm = suffixSum[i][n-j];
        //         if(maxi[i-1][j-1].find(sm-1)!=maxi[i-1][j-1].end()){
        //             dp[i][j] = sm;
        //         }
        //         else{
        //             dp[i][j] = *maxi[i-1][j-1].rbegin();
        //         }
        //     }
        //     set<int>tmp2;
        //     for(int j=0; j<=n; j++){
        //         tmp2.insert(dp[i][j]);
        //         set<int>tmp3 = maxi[i-1][j];
        //         for(auto x:tmp3){
        //             tmp2.insert(x);
        //         }
        //         maxi[i][j] = tmp2;
        //     }
        // }
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<=n; j++){
        //         ans = max(ans, dp[i][j]);
        //     }
        // }
        // cout << ans << endl;
    }
}