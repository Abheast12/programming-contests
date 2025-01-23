#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    int m = 1e5;
    // vector<bool> isPrime(m+1, true);
    // isPrime[0] = isPrime[1] = false;
    vector<vector<int>> factors(m+1);
    factors[2].push_back(2);
    factors[3].push_back(3);
    for (int i = 4; i <= m; i++) {
        for(int j=2; j*j<=i; j++){
            if(i%j == 0){
                factors[i].push_back(j);
                if(j*j != i){
                    factors[i].push_back(i/j);
                }
            }
        }
    }
    int mod = 998244353;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>>dp(n+1, vector<int>(17, 0));
        for(int i=1; i<=n; i++){
            dp[i][1] = 1;
        }
        for(int i=2; i<=16; i++){
            for(int j=2; j<=n; j++){
                for(int x: factors[j]){
                    dp[j][i] += dp[j/x][i-1];
                    dp[j][i] %= mod;
                }
            }
        }
    }
}