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
int binmul(int a, int b, int mod){
    int res = 0;
    while(b){
        if(b&1){
            res = (res+a)%mod;
        }
        a = (a+a)%mod;
        b>>=1;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        vector<int>v(n+1);
        vector<int>pre(n+1, 0);
        int sm = 0;
        for(int i=1; i<=n; i++){
            cin >> v[i];
            sm+=v[i];
            pre[i] = pre[i-1]^v[i];
        }
        int mod = 998244353;
        
        // vector<vector<int>>bits(31, vector<int>(n+1, 0));
        int ans = 0;
        for(int i=0; i<=30; i++){
            int sm0 = 0, sm1 = 0, ct0 = 1, ct1 = 0;
            int tmp = 1LL<<i;
            int t_ans = 0;
            for(int j=1; j<=n; j++){
                if(pre[j]&tmp){
                    t_ans+=j*ct0-sm0;
                    sm1+=j;
                    ct1++;
                }
                else {
                    t_ans+=j*ct1-sm1;
                    sm0+=j;
                    ct0++;
                }
                t_ans = t_ans%mod;
            }
            
            t_ans = binmul(t_ans, tmp, mod);
            ans = (ans+t_ans)%mod;
        }
        cout << ans << endl;
    // }
}