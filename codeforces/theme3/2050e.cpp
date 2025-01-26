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
    int t;
    cin >> t;
    while(t--){
        string a, b, c;
        cin >> a >> b >> c;
        vector<vector<int>>dp(a.length()+1, vector<int>(b.length()+1, 1e18));
        dp[0][0] = 0;
        for(int i=1; i<=a.length()+b.length(); i++){
            for(int j=0; j<=i; j++){
                if(j > a.length() || i-j > b.length()){
                    continue;
                }
                if(j > 0){
                    dp[j][i-j] = min(dp[j][i-j], dp[j-1][i-j] + (a[j-1] != c[i-1]));
                }
                if(i-j > 0){
                    dp[j][i-j] = min(dp[j][i-j], dp[j][i-j-1] + (b[i-j-1] != c[i-1]));
                }
            }
        }
        cout << dp[a.length()][b.length()] << endl;
    }
}