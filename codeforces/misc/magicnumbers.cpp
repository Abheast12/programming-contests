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

int getVal(string &b, int m, int d){
    vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(b.length()+1, vector<int>(2, 0)));

    for(int j=0; j<=9; j++){
        if(j!=d && j < b[0]-'0'){
            if(j == b[0]-'0') dp[j%m][0][1] = 1;
            else dp[j%m][0][0] = 1;
        }
    }
    int mod = 1e9+7;
    for(int i=1; i<b.length(); i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<2; k++){
                for(int p=0; p<=9; p++){
                    if(k==0){
                        if(i%2==0 && p == d){
                            dp[(10*j+p)%m][i+1][0] += dp[j][i][0];
                        }
                        else if(i%2==1 && p!=d) dp[(10*j+p)%m][i+1][0] += dp[j][i][0];
                    }
                    else if(k==1){
                        if(i%2==0){
                            if(p ==d && p < b[i]-'0'){
                                dp[(10*j+p)%m][i+1][0] += dp[j][i][1];
                            }
                            else if(p == d && p == b[i]-'0'){
                                dp[(10*j+p)%m][i+1][1] += dp[j][i][1];
                            }
                        }
                        else{
                            if(p < b[i]-'0' && p!=d){
                                dp[(10*j+p)%m][i+1][0] += dp[j][i][1];
                            }
                            else if(p == b[i]-'0' && p!=d){
                                dp[(10*j+p)%m][i+1][1] += dp[j][i][1];
                            }
                        }
                        
                    }
                    dp[(10*j+p)%m][i+1][0] %= mod;
                    dp[(10*j+p)%m][i+1][1] %= mod;
                }
                
            }
        }
    }
    return (dp[0][b.length()][0] + dp[0][b.length()][1])%mod;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, d;
    cin >> m >> d;
    string a, b;
    cin >> a >> b;
    int val1 = getVal(a, m, d);
    int val2 = getVal(b, m, d);
    cout << val2-val1 << endl;

}