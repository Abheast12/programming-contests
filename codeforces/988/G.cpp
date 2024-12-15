#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<unordered_map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector<bool> isPrime(1e6 + 1, true);
    vector<vector<int>> factors(1e6 + 1);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 1e6; i++) {
        if (isPrime[i]) {
            factors[i].push_back(i);
            for (int j = i * 2; j <= 1e6; j += i) {
                isPrime[j] = false;
                factors[j].push_back(i);
            }
        }
    }
    int mod = 998244353;
    map<int, int>dp;
    for(int j=1; j<pow(2, factors[a[0]].size()); j++){
        int prod = 1;
        for(int k=0; k<factors[a[0]].size(); k++){
            if(j & (1<<k)){
                prod*=factors[a[0]][k];
            }
        }
        dp[prod] = 1;
    }
    for(int i=1; i<n; i++){
        vector<int> curr_factors = factors[a[i]];
        int m = curr_factors.size();
        int sum = 0;

        for(int j = 1; j <(1<<m); j++) {
            int prod = 1;
            int tot_bits = __builtin_popcount(j);
            for(int k = 0; k < m; k++) {
                if(j & (1<<k)) {
                    prod *= curr_factors[k];
                }
            }
            if(tot_bits % 2 == 1){
                sum = (sum + dp[prod]) % mod;
            }
            else{
                sum = (sum - dp[prod] + mod) % mod;
            }
        }

        
        if(i==n-1){
            cout << sum << endl;
            return 0;
        }
        for(int j=1; j<(1<<m); j++){
            int prod = 1;
            for(int k=0; k<m; k++){
                if(j & (1<<k)){
                    prod*=factors[a[i]][k];
                }
            }
            dp[prod] = (dp[prod] + sum) % mod;
        }
    }
}