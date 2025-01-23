#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m, l;
        cin >> n >> m >> l;
        vector<vector<long long>> v(n, vector<ll>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        vector<vector<vector<ll>>>dp(n, vector<vector<ll>>(m, vector<ll>(m, 1e18)));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ll mn = 0;
                if(i>0){
                    mn = *min_element(dp[i-1][j].begin(), dp[i-1][j].end());
                }
                for(int k=0; k<m; k++){
                    if(i==0 && j==0){
                        dp[i][j][k] = v[i][(j+k)%m] + l*k;
                    }
                    if(i>0){
                        dp[i][j][k] = min(dp[i][j][k], mn + v[i][(j+k)%m] + l*k);
                    }
                    if(j>0){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k] + v[i][(j+k)%m]);
                    }

                }

            }
        }

        cout << *min_element(dp[n-1][m-1].begin(), dp[n-1][m-1].end()) << endl;

    }
}