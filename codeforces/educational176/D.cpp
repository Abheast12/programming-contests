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

    vector<vector<vector<int>>>dp(61, vector<vector<int>>(61, vector<int>(61, 1e18)));
    dp[0][0][0] = 0;
    // int cur = 1;
    // queue<pair<int, pair<int, int>>>q;
    // q.push({0, {0, 0}});
    // while(cur <=60 && !q.empty()){
    //     int x = q.front().first;
    //     int y = q.front().second.first;
    //     int z = q.front().second.second;
    //     cout << x << " " << y << " " << z << endl;
    //     q.pop();
    //     if(x == cur){
    //         cur++;
    //     }
    //     if(y+cur <=60){
    //         dp[cur][y+cur][z] = min(dp[cur][y+cur][z], dp[x][y][z] + (1<<cur));
    //         dp[cur][y+cur][z] = min(dp[cur][y+cur][z], dp[x][y+cur][z]);
    //         q.push({cur, {y+cur, z}});
    //     }
    //     if(z+cur <=60){
    //         dp[cur][y][z+cur] = min(dp[cur][y][z+cur], dp[x][y][z] + (1<<cur));
    //         dp[cur][y][z+cur] = min(dp[cur][y][z+cur], dp[x][y][z+cur]);
    //         q.push({cur, {y, z+cur}});
    //     }
    // }
    for(int i=1; i<=60; i++){
        dp[i][0][0] = 0;
        for(int j=0; j<=60; j++){
            for(int k=0; k<=60; k++){
                if(dp[i-1][j][k] == 1e18)continue;
                dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
                if(i+j<=60){
                    dp[i][i+j][k] = min(dp[i][i+j][k], dp[i-1][j][k] + (1LL<<i));
                    dp[i][i+j][k] = min(dp[i][i+j][k], dp[i-1][i+j][k]);
                }
                if(i+k<=60){
                    dp[i][j][i+k] = min(dp[i][j][i+k], dp[i-1][j][k] + (1LL<<i));
                    // if(dp[i-1][j][k] + (1LL<<i)<0){
                    //     cout << i << " " << j << " " << k << " " << dp[i-1][j][k] << " " << (1LL<<i) << endl;
                    // }
                    dp[i][j][i+k] = min(dp[i][j][i+k], dp[i-1][j][i+k]);
                }
                // if(i <=2 && j <= 2 && k <= 2){
                //     cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
                // }
            }
        }
    }
    // cout << dp[60][0][1] << " " << dp[60][1][0] << " " << dp[60][1][1] << endl;
    while(t--){
        int a, b;
        cin >> a >> b;
        
        int ans = 2e18;
        for(int i=0; i<=60; i++){
            for(int j=0; j<=60; j++){
                if(a/(1LL<<i) == b/(1LL<<j)){
                    // cout << i << " " << j << endl;
                    // cout << i << " " << j << " " << dp[60][i][j] << endl;
                    ans = min(ans, dp[60][i][j]);
                }
            }
        }
        cout << ans << endl;
    }
}