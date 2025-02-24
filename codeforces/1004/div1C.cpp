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
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<int>pre(n+1, 0);
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] ^ v[i];
        }
        
        int mod = 1e9+7;
        int ans = 0;
        
       
        map<int, int>dp;
        dp[0] = 1;
        for(int i=1; i<=n ;i++){
            dp[pre[i-1]] = 3*dp[pre[i-1]];
            dp[pre[i-1]] %= mod;
            dp[pre[i-1]] += 2*dp[pre[i]];
            dp[pre[i-1]] %= mod;
            
        }
        for(auto it: dp){
            ans += it.second;
            ans %= mod;
        }
        cout << ans << endl;
    }
}