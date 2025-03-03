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
using ll = long long;
using namespace std;  
ll solve(vector<ll>&pre, ll l, ll p, ll lm){
    // cout << l << " " << p << endl;
    if(l<=lm){
        return pre[l];
    }
    if(l%2==0){
        return (p^solve(pre, l/2, p, lm));
    }
    else{
        return p;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n, l , r;
        cin >> n >> l >> r;
        vector<ll>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        if(l<=n){
            cout << v[l-1] << endl;
            continue;
        }
        ll lm;
        // cout << "here" << endl;
        if(n%2 == 0) lm = n+1;
        else lm = n;
        vector<ll>pre(lm+1, 0);
        for(int i=0; i<n; i++){
            pre[i+1] = pre[i]^v[i];
            // cout << pre[i+1] << " ";
        }
        // cout << endl;
        if(lm == n+1){
            pre[lm] = pre[lm-1]^pre[lm/2];
        }
        if(l == lm){
            cout << pre[lm/2] << endl;
            continue;
        }
        cout << solve(pre, l/2, pre[lm], lm) << endl;
        // int ops = 0;
        // while(l > n){
        //     ops++;
        //     l/=2;
        // }
        // l*=2;
        // ops = ops%2;
        // // cout << l << endl;
        // cout << (pre[l]) << endl;
        
    }
}