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
        int n, k;
        cin >> n >> k;
        vector<int>a(n+1);
        vector<int>b(n+1);
        vector<int>pa(2*n+1, 0);
        vector<int>pb(2*n+1, 0);
        for(int i=1; i<=n; i++){
            cin >> a[i];
            pa[i] = pa[i-1] + a[i];
        }
        for(int i=1; i<=n; i++){
            cin >> b[i];
            pb[i] = pb[i-1] + b[i];
        }
        for(int i=n+1; i<= 2*n; i++){
            pa[i] = pa[i-1] + a[i-n];
            pb[i] = pb[i-1] + b[i-n];
        }
        int ans = -1;
        int l = 1, r =1;
        while(l <= n){
            while(r <= 2*n && pa[r]- pa[l-1] > pb[r]-pb[l-1]){
                r++;
            }
            ans = max(ans, r-l+1);
            l++;
            if(r < l){
                r = l;
            }
        }
        cout << ans << endl;
    }
}