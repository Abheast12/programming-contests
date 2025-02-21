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
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int ans = 0;
        int mod = 998244353;
        int t_ans = 0;
        int ct = 0;
        int pw = 1;
        for(int i=0; i<n; i++){
            if(v[i] == 1){
                ct++;
                t_ans++;
                // pw = 1;
                t_ans%=mod;
            }
            else if(v[i] == 2){
                t_ans*=2;
                t_ans%=mod;
            }
            else if(v[i] == 3){
                // t_ans*=pw;
                t_ans%=mod;
                ans+=t_ans-ct+mod;
                ans%=mod;
                // pw = 1;
            }
        }
        cout << ans << endl;
    }
}