#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    long long dp1[1001][21], dp2[1001][21];
    for(int i=0; i<1001; i++){
        for(int j=0; j<21; j++){
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }
    long long mod = 998244353;
    string s;
    cin >> s;
    string a, b;
    cin >> a >> b;
    long long n = s.length();
    for(int i=1; i<=n; i++){
        for(int j=0; j<a.length(); j++){
            dp1[i][j] = dp1[i-1][j];
            if(s[i-1] == a[j]){
                if(j==0){
                    dp1[i][j]+=1;
                    dp1[i][j]%=mod;
                }
                else{
                    dp1[i][j] = (dp1[i][j]+dp1[i-1][j-1])%mod;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<b.length(); j++){
            dp2[i][j] = dp2[i-1][j];
            if(s[i-1] == b[j]){
                if(j==0){
                    dp2[i][j] = (dp2[i][j]+1)%mod;
                }
                else{
                    dp2[i][j] = (dp2[i][j]+dp2[i-1][j-1])%mod;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<a.length(); j++){
            cout << dp1[i][j] << " ";
        }
        cout << endl;
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<b.length(); j++){
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }
    long long ans =0;
    for(int i=1; i<=n; i++){
        ans+=dp1[i][a.length()-1]*dp2[i][b.length()-1]*i;
        ans%=mod;
    }
    ans-=(dp1[n][a.length()-1]*dp2[n][b.length()-1]/2);
    ans%=mod;
    cout << ans << endl;


}