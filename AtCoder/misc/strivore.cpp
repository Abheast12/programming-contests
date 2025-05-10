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



// Binary Exponentiation
long long binexp(long long bs, long long pw, long long mod = 1e9+7){
    long long res = 1;
    while(pw > 0){
        if(pw%2 == 1){
            res = (res*bs);
            res%=mod;
        }
        bs = (bs*bs);
        bs%=mod;
        pw >>= 1;
    }
    return res;
}

// Calculate the modular inverse of a number given prime modulus
long long modinv(long long x, long long m){
    return binexp(x, m-2);
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int md = 1e9+7;
    int ans = 0;
    int prev =1;
    for(int i=0; i<=n; i++){
        int tmp = 1;
        int rm = binexp(26, n-i);
        int rn = binexp(25, i);
        if(i==0){
            prev = 1;
        }
        else{
            prev = prev*(i+s.length()-1);
            prev%=md;
            int inv = modinv(i, md);
            prev = (prev*inv)%md;
        }
        tmp = (tmp*prev)%md;
        tmp = (tmp*rm)%md;
        tmp = (tmp*rn)%md;
        ans = (ans+tmp)%md;
    }
    cout << ans << endl;


}
