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
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        int dif = 2;
        while(dif <=n-1){
            for(int i=1; i+dif<=n; i++){
                int mx1 = 0;
                for(int j=i; j<i+dif; j++){
                    mx1= max(mx1, dp[i][j]+dp[j+1][i+dif]);
                }
                int mx2 = 0;
                for(int j=i+1; j<i+dif; j++){
                    int tmp = v[i]*v[j]*v[i+dif];
                    if(j-1-i-1>=2){
                        tmp+=dp[i+1][j-1];
                    }
                    if(i+dif-1-j-1>=2){
                        tmp+=dp[j+1][i+dif-1];
                    }
                    mx2 = max(mx2, tmp);
                }
                dp[i][i+dif] = max(mx1, mx2);
            }
            dif++;
        }
        cout << dp[1][n] << endl;
    }
}