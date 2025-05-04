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
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        vector<vector<int>>dp(n, vector<int>(n, 1e9));

        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        for(int i=2; i<=n; i++){
            for(int j=0; j<=n-i; j++){
                vector<int>tmp;
                int mn = 1e9;
                for(int k=j+2; k<=j+i-1; k++){
                    if(v[k] == v[j]){
                        int tmp = 0;
                        tmp+=dp[j+1][k-1];
                        if(j+i-1-k >= 1){
                            tmp+=dp[k+1][j+i-1];
                        }
                        mn = min(mn, tmp);
                    }
                    // tmp.push_back(v[k]);
                    // mn = min(mn, dp[j][k]+dp[k+1][j+i-1]);
                }
                dp[j][j+i-1] = min(mn, 1+dp[j+1][j+i-1]);
                if(v[j] == v[j+1]){
                    int val = 0;
                    if(i-1>=2){
                        val = dp[j+2][j+i-1];
                    }
                    
                    dp[j][j+i-1] = min(dp[j][j+i-1], 1+val);
                }
                // tmp.push_back(v[j+i-1]);
                // vector<int>rev = tmp;
                // reverse(rev.begin(), rev.end());
                // if(rev == tmp){
                //     dp[j][j+i-1] = 1;
                // }
                // else{
                //     dp[j][j+i-1] = mn;
                // }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[0][n-1] << endl;
    // }
}