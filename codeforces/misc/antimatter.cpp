#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin >>n;
    vector<int>a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long dp[1001][20002];
    memset(dp, 0, sizeof(dp));
    // cout << "hi" << endl;
    long long mod = 1e9+7;
    long long ans = 0;
    for(int i=0; i<n; i++){
        // cout << i << endl;
        for(int j=0; j<20002; j++){
            if(i!=0 && dp[i-1][j] > 0){
                dp[i][j+a[i]] += dp[i-1][j];
                dp[i][j-a[i]]+= dp[i-1][j];
                dp[i][j+a[i]]%=mod;
                dp[i][j-a[i]]%=mod;
            }
        }
        
        dp[i][10000 + a[i]]++;
        dp[i][10000 + a[i]]%=mod;
        dp[i][10000 - a[i]]++;
        dp[i][10000 - a[i]]%=mod;
    }
    for(int i=0; i<n; i++){
        ans+=dp[i][10000];
        ans%=mod;
    }
    cout << ans << endl;
    // cout << "hi" << endl;
    // cout << dp[10000]%mod << endl;
}