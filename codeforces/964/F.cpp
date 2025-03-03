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
int modinv(int a, int m){
    int pow = m-2;
    int ans = 1;
    while(pow){
        if(pow%2){
            ans = (ans*a)%m;
        }
        a = (a*a)%m;
        pow/=2;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        int ct0 =0, ct1= 0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] == 0) ct0++;
            else ct1++;
        }
        int ans =0;
        vector<int>factorials1(ct1+1);
        vector<int>factorials0(ct0+1);
        factorials1[0] = 1;
        factorials0[0] = 1;
        if(ct1!=0)factorials1[1] =ct1;
        if(ct0 !=0)factorials0[1] = ct0;
        int cur1 = ct1;
        int mod= 1e9+7;
        for(int i=2; i<=ct1; i++){
            cur1 = cur1*(ct1-i+1);
            cur1%=mod;
            cur1*=modinv(i, mod);
            cur1%=mod;
            factorials1[i] = cur1;
        }
        int cur0 = ct0;
        for(int i=2; i<=ct0; i++){
            cur0 = cur0*(ct0-i+1);
            cur0%=mod;
            cur0*=modinv(i, mod);
            cur0%=mod;
            factorials0[i] = cur0;
        }


        for(int i=k; i>k/2; i--){
            if(i>ct1 || k-i>ct0) continue;
            int val = factorials1[i] * factorials0[k-i];
            val%=mod;
            ans+=val;
            ans%=mod;
        }
        cout << ans << endl;
    }
}