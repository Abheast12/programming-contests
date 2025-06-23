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

// #define int long long
using ll = long long;
using namespace std;  
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
    ll,                                // key type
    null_type,                          // mapped-policy (we just want a set)
    less<ll>,                          // ordering
    rb_tree_tag,                        // underlying tree
    tree_order_statistics_node_update   // order‐statistic support
> ordered_set;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;
    ordered_set v;
    
    for(int i=1; i<=n; i++){
        v.insert(i);
    }
    ll cur = 0;
    // k++;
    while(v.size() >=1){
        cur+=k;
        cur %= v.size();
        auto it = v.find_by_order(cur);
        cout << *it << " ";
        v.erase(it);
    }
    cout << endl;
    
}