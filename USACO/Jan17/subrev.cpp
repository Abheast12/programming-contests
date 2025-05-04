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

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int32_t main(){
    setIO("subrev");
    
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<vector<vector<vector<int>>>>dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(51, vector<int>(51, 0))));
    for(int i=0; i<n; i++){
        for(int k=1; k<=50; k++){
            for(int l=1; l<=50; l++){
                if(v[i]>=k && v[i]<=l){
                    dp[i][i][k][l] = 1;
                }
            }
        }
    }
    for(int i=2; i<=n; i++){
        for(int j=0;j<n; j++){
            if(j+i-1>=n) continue;
            for(int k=1; k<=50; k++){
                for(int l=k; l<=50; l++){
                    // if(i>2){
                    //     dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], dp[j+1][j+i-2][k][l]);
                    // }
                    dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], dp[j+1][j+i-1][k][l]);
                    dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], dp[j][j+i-2][k][l]);
                    if(v[j]>=k && v[j]<=l) dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], 1+dp[j+1][j+i-1][v[j]][l]);
                    if(v[j+i-1]<=l && v[j+i-1] >=k) dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], 1+dp[j][j+i-2][k][v[j+i-1]]);
                    if(v[j]<=l && v[j]>=k){
                        dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], 1+dp[j+1][j+i-2][k][v[j]]);
                    }
                    if(v[j+i-1]>=k && v[j+i-1]<=l){
                        dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], 1+dp[j+1][j+i-2][v[j+i-1]][l]);
                    }
                    if(v[j]<=l && v[j+i-1]>=k && v[j+i-1]<=v[j]){
                        dp[j][j+i-1][k][l] = max(dp[j][j+i-1][k][l], 2+dp[j+1][j+i-2][v[j+i-1]][v[j]]);
                    }
                }
            }
        }
    }
    cout << dp[0][n-1][1][50] << endl;
    
}
