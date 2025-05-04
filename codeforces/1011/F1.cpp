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
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        double ans = 1e18;
        double half = (double)k/(double)2 + 0.5;
        for(double i = half; i<=(double)n-half+1.0; i+=(double)1){
            vector<double>ldist(k+1, 1e9);
            vector<double>rdist(k+1,1e9);
            for(double j=1; j<=n; j++){
                if(j==i){
                    ldist[v[j]] = 0;
                    rdist[v[j]] = 0;
                }
                if(j<i){
                    ldist[v[j]] = min(ldist[v[j]], i-j);
                }
                else{
                    rdist[v[j]] = min(rdist[v[j]], j-i);
                }
            }
            vector<pair<double, int>>v2;
            for(int j=1; j<=k; j++){
                v2.push_back({ldist[j]-rdist[j], j});
            }
            sort(v2.begin(), v2.end());
            double ans1 = 0;
            for(int j=0; j<k; j++){
                if(j<(double)k/(double)2){
                    ans1 += ldist[v2[j].second];
                }
                else{
                    ans1 += rdist[v2[j].second];
                }
            }
            
            double val = k - k/2;
            val = val/(2.0);
            val = val* (double)(k/2) * 2.0;
            ans1-=val;
            ans = min(ans, ans1);
        }
        cout << ans << endl;
    }
}