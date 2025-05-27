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
    vector<int>comb(501, 0);
    vector<int>combi(501, 0);
    int md = 998244353;
    comb[0] = 1;    
    combi[0] = 1;
    for(int i=1; i<=500; i++){
        comb[i] = (comb[i-1]*i)%md;
        combi[i] = modinv(comb[i], md);
    }
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>>dp(k+1, vector<int>(n+1, 0));
        string s;
        cin >> s;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                dp[1][i] = 1;
            }
            dp[1][i] += dp[1][i+1];
        }
        vector<int>pree(n+1, 0);
        vector<int>preo(n+1, 0);
        vector<int>sufe(n+2, 0);
        vector<int>sufo(n+2, 0);
        
        for(int i=2; i<=k; i++){
            for(int j=n-1; j>=0; j--){
                
                
                int avail;
                if(s[j] == '0'){
                    avail = (i+1)/2;
                }
                else{
                    avail = i/2;
                }
                for(int l=i-1; l>=1; l--){
                    // int val =0;
                    if(i-l > avail){
                        break;
                    }
                    int dif = i-l;
                    int tmp = (comb[avail]*combi[dif])%md;
                    tmp = (tmp*combi[avail-dif])%md;
                    dp[i][j]+=(tmp*dp[l][j+1])%md;
                    dp[i][j]%=md;
                }
                dp[i][j] += dp[i][j+1];
                dp[i][j] %= md;
            }
           
        }
        // for(int i=1; i<=k; i++){
        //     for(int j=0;j<n;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[k][0] << endl;
    }
}