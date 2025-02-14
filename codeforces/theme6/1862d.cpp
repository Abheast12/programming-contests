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
        int l = 1, r = 2e9+1;
        int ans = 0;
        while(l < r){
            int mid = (l+r)/2LL;
            // cout << mid << endl;
            if(mid*(mid-1LL)/2LL >= n){
                ans = mid;
                r = mid;
            }
            else{
                l = mid+1LL;
            }
        }
        if(ans*(ans-1LL)/2LL == n){
            cout << ans << endl;
            continue;
        }
        int gg = ans-1LL;
        int tmp = gg*(gg-1LL)/2LL;
        int diff = n-tmp;
        cout << diff + gg << endl;

    }
}