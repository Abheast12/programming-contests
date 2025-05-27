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
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans = n;
        for(int i=0; i<n; i++){
            int val = v[i]+v[n-1];
            if(val%2==0){
                ans = min(ans, i);
            }
        }
        for(int i=n-1; i>=0; i--){
            int val = v[i]+v[0];
            if(val%2==0){
                ans = min(ans, n-i-1);
            }
        }
        cout << ans << endl;
    }
}