#include<iostream>
using namespace std;
int dp[100100];
int main(){
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 1;
    for(int i=1; i<=n-1; i++){
        dp[i+1]+=dp[i];
        dp[i+1]%=998244353;
        dp[i+2]+=dp[i];
        dp[i+2]%=998244353;
    }
    cout << dp[n] << endl;
}