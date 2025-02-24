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
// int binmul(int a, int b, int mod){
//     int res = 0;
//     while(b){
//         if(b&1){
//             res = (res+a)%mod;
//         }
//         a = (a+a)%mod;
//         b>>=1;
//     }
//     return res;
// }
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
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
        // int mod = 998244353;
        vector<vector<int>>prect(31, vector<int>(n+1, 0));
        vector<vector<int>>sufct(31, vector<int>(n+1, 0));
        for(int i=0; i<=30; i++){
            for(int j=1; j<=n; j++){
                prect[i][j] = prect[i][j-1] + ((pre[j]>>i)&1);
            }
        }
        
        for(int i=0; i<=30; i++){
            for(int j=n; j>=1; j--){
                if(j==n) sufct[i][j] = ((pre[j]>>i)&1);
                else sufct[i][j] = sufct[i][j+1] + ((pre[j]>>i)&1);
            }
        }
        
        int ans = 0;
        // for(int i=0;i<=3; i++){
        //     cout << pre[i] << " ";
        // }
        // cout << endl;
        // for(int i=0; i<=3; i++){
        //     cout << sufct[2][i] << " ";
        // }
        // cout << endl;
        for(int i=1; i<=n; i++){
            int val = 63-__builtin_clzll(v[i]);
            // cout << val << endl;
            // cout << ans << endl;
            int t_ans = 0;
            int p0 = i-prect[val][i-1];
            
            int p1 = prect[val][i-1];
            
            
            // cout << "here" << endl;
            int s0 = n-i-sufct[val][i]+1;
            int s1 = sufct[val][i];
            // cout << p0 << " " << p1 << " " << s0 << " " << s1 << endl;
            t_ans+=p0*s0+(p1)*s1;
            // if(i==n){
            //     if(pre[i]&(1LL<<val)){
            //         t_ans+=p1;
            //     }
            //     else{
            //         t_ans+=p0;
            //     }
            // }
            // else{
            //     int s0 = n-i-sufct[val][i+1];
            //     int s1 = sufct[val][i+1];
            //     t_ans+=p0*s0+(p1)*s1;
            // }
            ans+=t_ans;
        }
        cout << ans << endl;

        // vector<vector<int>>bits(31, vector<int>(n+1, 0));
        // int ans = 0;
        // for(int i=0; i<=30; i++){
        //     int sm0 = 0, sm1 = 0, ct0 = 1, ct1 = 0;
        //     int tmp = 1LL<<i;
        //     int t_ans = 0;
        //     for(int j=1; j<=n; j++){
        //         if(pre[j]&tmp){
        //             t_ans+=j*ct0-sm0;
        //             sm1+=j;
        //             ct1++;
        //         }
        //         else {
        //             t_ans+=j*ct1-sm1;
        //             sm0+=j;
        //             ct0++;
        //         }
        //         t_ans = t_ans%mod;
        //     }
            
        //     t_ans = binmul(t_ans, tmp, mod);
        //     ans = (ans+t_ans)%mod;
        // }
        // cout << ans << endl;
    }
}