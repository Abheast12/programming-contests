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
long long modinv(long long x, long long m){
    long long res = 1;
    long long pow = m-2;
    while(pow> 0){
        if(pow%2){
            res = (res*x)%m;
        }
        x = (x*x)%m;
        pow=(pow>>1);
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, l, k;
        cin >> n >> l >> k;
        vector<vector<int>>dp(l+1, vector<int>(n, 0));
        dp[0][n-1] = 1;
        int md = 1e9+7;
        for(int i=1; i<=l; i++){
            int inv = modinv(l-i+1,md);
            for(int j=0; j<n; j++){
                int prev = dp[i-1][j];
                for(int k=j+1; k<=j+n; k++){
                    int val = (l-i+1)/n;
                    int dif = (k-(j+1));
                    if(dif < (l-i+1)%n){
                        val++;
                    }
                    int tmp = (prev*val)%md;
                    tmp = (tmp*inv)%md;
                    dp[i][k%n] += tmp;
                    dp[i][k%n] %= md;
                }
            }
        }
        for(int i=0; i<n; i++){
            int sm = 0;
            for(int j=1; j<=l; j++){
                sm+= dp[j][i];
                sm%=md;
            }
            cout << sm << " ";
        }
        cout << endl;

    }
}