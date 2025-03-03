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


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll ans =0;
    ll prev = -1;
    vector<ll>pre(n+1, 0);
    // cout << "hi" << endl;
    for(ll i=1; i<=n; i++){
        if(s[i-1] == '1'){
            pre[i] = pre[i-1]-3;
        }
        else pre[i] = pre[i-1]+1;
        // cout << pre[i] << " ";  
    }
    // cout << endl;
    vector<ordered_set> st(4);

    st[0].insert(0);
    int difs[4] = {-3, -4, -1, 2};
    // cout << "here" << endl;
    // map<ll, ll>val;
    // val[0] = 1;
    for(ll i=1; i<=n; i++){
        // auto it = upper_bound(st.begin(), st.end(), pre[i]-2LL);
        // ll idx = st.order_of_key(pre[i]-1);
        for(int j=0; j<4; j++){
            ll idx = st[(i-j+4)%4].order_of_key(pre[i]+difs[j]);
            ans+=idx;
        }
        st[i%4].insert(pre[i]);
        // if(i==7){
        //     cout << "elements" << endl;
        //     for(auto x: st[0]){
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        // cout << i << " " << ans << endl;
        
        // cout << idx << endl;
        // ans+=(idx);
        // ans+=val[pre[i]+1];
        // cout << idx << " " << val[pre[i]+1] << " " << ans << endl;
        // st.insert(pre[i]);
        // val[pre[i]]++;
    }
    cout << ans << endl;

}