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
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, pair<int, int>>>v(n);
    for(int i=0; i<n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        v[i] = {z, {y, x}};
    }
    vector<vector<int>>dp(n+1, vector<int>(a+b+1, 0));
    sort(v.begin(), v.end());
    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        // cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;
        for(int j=0; j<=a+b; j++){
            // if(dp[i][j] == -1) continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(j<b){
                int left = b-j;
                int val = v[i].first * v[i].second.first;
                if(val > left){
                    int ct = v[i].second.first-(left/v[i].first);
                    if(b+ct <= a+b) dp[i+1][b+ct] = max(dp[i+1][b+ct], dp[i][j] + v[i].second.second);
                }
                else{
                    dp[i+1][j+val] = max(dp[i+1][j+val], dp[i][j] + v[i].second.second);
                }
            }
            else{
                if(j+v[i].second.first > a+b) continue;
                dp[i+1][j+v[i].second.first] = max(dp[i+1][j+v[i].second.first], dp[i][j] + v[i].second.second);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=a+b; j++){
            // if(dp[i][j] == -1) continue;
            // cout << dp[i][j] << " ";
            ans = max(ans, dp[i][j]);
        }
        // cout << endl;
    }
    cout << ans << endl;
}