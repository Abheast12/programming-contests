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
    
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<vector<int>>dp(n, vector<int>(n, 1e9));
    map<pair<int, int>, int>mp;
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
        mp[{i, i}] = v[i];
    }
    for(int i=2; i<=n; i++){
        for(int j=0; j<=n-i; j++){
            for(int k=j+1; k<=j+i-1; k++){
                if(dp[j][k-1] == 1 && dp[k][j+i-1] == 1){
                    if(mp[{j, k-1}] == mp[{k, j+i-1}]){
                        dp[j][j+i-1] = 1;
                        mp[{j, j+i-1}] = 1+mp[{j, k-1}];
                        break;
                    }
                }
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    vector<int>dp2(n, 1e9);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(dp[j][i] == 1){
                if(j != 0) dp2[i] = min(dp2[i], 1+dp2[j-1]);
                else dp2[i] = 1;
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     cout << dp2[i] << " ";
    // }
    // cout << "\n";
    cout << dp2[n-1] << "\n";
    return 0;
}