#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long dp[1000002];
    long long mod = 1e9+7;

    for(int i=0; i<1000002; i++){
        dp[i] = 0;
    }
    int n;
    cin >> n;
    vector<long long>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        // dp[1]++;
        vector<long long>factors;
        for(long long j=1; j*j<=v[i]; j++){
            if(v[i]%j==0){
                factors.push_back(j);
                if(j*j!=v[i]){
                    factors.push_back(v[i]/j);
                }
            }
            // if(j==1){
            //     dp[j]++;
            //     if(v[i]!=1){
            //         if(v[i]-1!=1) dp[v[i]]+= dp[v[i]-1];
            //         else dp[v[i]]+= dp[v[i]-1]-1;
            //     }
            //     dp[j]%=mod;
            //     dp[v[i]]%=mod;
            //     continue;
            // }
            // if(v[i]%j==0){
            //     if(v[i]%(v[i]/j-1)!=0){
            //         dp[v[i]/j] += dp[v[i]/j-1];
            //     }
            //     else{
            //         dp[v[i]/j] += dp[v[i]/j-1]-1;
            //     }
            //     // dp[v[i]/j] += dp[v[i]/j-1];
            //     dp[v[i]/j]%=mod;

            //     if(j*j!=v[i]){
            //         if(v[i]%(j-1)!=0){
            //             dp[j] += dp[j-1];
            //         }
            //         else{
            //             dp[j] += dp[j-1]-1;
            //         }
            //         dp[j] = max(dp[j], 0LL);
            //         // dp[j] += dp[j-1];
            //         dp[j]%=mod;
            //     }
            // }
        }
        sort(factors.begin(), factors.end());
        for(int j=factors.size()-1; j>=0; j--){
            
            dp[factors[j]]+=dp[factors[j]-1];
            dp[factors[j]]%=mod;
            if(factors[j]==1){
                dp[1]++;
                dp[1]%=mod;
            }
        }
        factors.clear();
    }
    long long ans = 0;
    for(int i=1; i<=1000000; i++){
        // cout << dp[i] << " ";
        ans = (ans+dp[i])%mod;
    }
    cout << ans << endl;
    
}