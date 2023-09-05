#include<iostream>
#include<cmath>
using namespace std;
long long dp[100100];

int main(){
    int n, k;
    cin >> n >> k;
    long long sum = 1;
    dp[1] = 1;
    for(int i=2; i<=k; i++){
        dp[i] = (dp[i-1] + dp[i-1]) % (long long)998244353;
        sum = (dp[i] + sum) % (long long)998244353;
    }
    if(n<=k) cout << dp[n] << endl;
    else{
        dp[k+1] = sum;
        if(n==k+1){
            // while(true)
            cout << sum << endl;
        }
        else{
        for(int i=k+2; i<=n; i++){
            sum = (sum + dp[i-1])%(long long)998244353;
            sum = (sum - dp[i-k-1])%(long long)998244353;
            
            dp[i] = sum % (long long)998244353;
        }
        
        cout << dp[n] % (long long)998244353<< endl;
        }
    }
    
}