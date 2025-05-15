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
    int ct =0;
    while(t--){
        ct++;
        int n;
        cin >> n;
        string s;
        cin >> s;
        // if(ct==121) cout << s << endl;
        vector<vector<int>>dp(n+1, vector<int>(2, 0));
        if(s[0] == '1'){
            dp[0][0] = 0;
            dp[0][1] = 1;
        }
        else{
            dp[0][0] = 0;
            dp[0][1] = n-1;
        }
        int ans = max(dp[0][0], dp[0][1]);
        for(int i=1; i<n; i++){
            if(s[i] == '1' && s[i-1] == '1'){
                dp[i][0] = 0;
                dp[i][1] = 1;
            }
            else if(s[i] == '1' && s[i-1] == '0'){
                dp[i][0] = 0;
                dp[i][1] = dp[i-1][1]+1;
            }
            else if(s[i] == '0' && s[i-1] == '1'){
                dp[i][0] = dp[i-1][1]+i;
                dp[i][1] = n-i-1;
            }
            else{
                dp[i][0] = dp[i-1][0]+i;
                dp[i][1] = dp[i-1][1]+n-i-1;
            }
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        cout << ans << endl;
    }
}