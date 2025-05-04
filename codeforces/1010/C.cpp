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
int modinv(int x, int m){
    int res = 1;
    int pow = m-2;
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
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n==1){
            cout << 0 << endl;
            continue;
        }
        int pow = 1;
        int val = 0;
        int mod = 1e9+7;
        for(int i=n-1; i>=0; i--){
            pow%=mod;
            if(s[i] == '1'){
                val+=pow;
                val%=mod;
            }
            pow*=2;
        }
        
        pow/=2;
        val-=pow;
        val=(val+mod)%mod;
        // cout << val << " " << pow << endl;
        const int tmp = pow;
        for(int i=1; i<n-1; i++){
            pow+=tmp;
            pow%=mod;
        }
        val+=pow;
        val%=mod;
        // cout << val << " " << tmp << endl;
        int inv = modinv(tmp, mod);
        val*=inv;
        val%=mod;
        cout << val << endl;
    }
}