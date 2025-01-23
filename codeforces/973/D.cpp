#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<cmath>
using namespace std;
typedef long long ll;

// pair<ll, bool> check(vector<ll>&v, ll x, bool flag, ll mn2){
//     ll mn = 1e18;
//     ll mx = -1;
//     ll left =0;
//     for(int i=0; i<v.size(); i++){
//         ll nw;
//         if(v[i] > x){
//             left += v[i]-x;
//             nw = x;
//         }
//         else{
//             if(left > x-v[i]){
//                 nw = x;
//                 left -=(x-v[i]);
//             }
//             else{
//                 nw = v[i]+left;
//                 left = 0;
//             }
//         }
//         mn = min(mn, nw);
//         mx = max(mx, nw);
//     }
//     cout << mn << " " << mx << " " << x << " " << left << endl;
//     if(left > 0){
//         mx = max(mx, x+left); 
//         return {mx-mn, false};
//     }
//     return {mx-mn, true};
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<ll>v(n);
        ll mn = 1e18;
        ll mx = -1;
        ll tmp =0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            tmp+=v[i];
            if(tmp/(i+1) < mn){
                mn = tmp/(i+1);
            }
        }
        tmp = 0;
        for(int i=n-1; i>=0; i--){
            tmp+=v[i];
            ll val = ceil((double)tmp/(double)(n-i));
            if(val > mx){
                mx = val;
            }
        }
        cout << mx - mn << endl;
        // ll ans =1e18;
        // ll l = 0;
        // ll r = 1e18;
        // while(l<r){
        //     ll mid = (l+r)/2;
        //     pair<ll, bool> p = check(v, mid);
        //     ans = min(ans, p.first);
        //     // cout << ans << " " << mid << endl;
        //     if(p.second){
        //         r = mid;
        //     }
        //     else{
        //         l = mid+1;
        //     }
        // }
        // cout << ans << endl;

    }
}