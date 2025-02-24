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
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<int>pre(n+1, 0);
        vector<int>suf(n+1, 0);
        for(int i=1; i<=n; i++){
            pre[i] = pre[i-1] + v[i];
        }
        for(int i=n; i>=1; i--){
            if(i == n) suf[i] = v[i];
            else suf[i] = suf[i+1] + v[i];
        }
        int ans = max(abs(pre[n]), abs(suf[1]));
        for(int i=1; i<=n-1; i++){
            ans = max(ans, abs(pre[i]) + suf[i+1]);
        }
        cout << ans << endl;
    }
}