#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        // vector<int> b(n);
        for(int i=0; i<n; i++){
            cin >> v[i].first;
        }
        for(int i=0; i<n; i++){
            cin >> v[i].second;
        }
        int ans = -1;
        sort(v.begin(), v.end());
        ans = v[n-1].first + v[n/2-1].first;
        for(int i=n-1; i>=0; i--){
            if(v[i].second == 1){
                int tmp = v[i].first + k;
                if(i>n/2-1){
                    ans = max(ans, tmp+v[n/2-1].first);
                }
                else{
                    ans = max(ans, tmp+v[n/2].first);
                }
            }
        }
        // int best = -1;
        int best_ans = -1;
        int l = 1, r = 1e9;
        while(l<=r){
           
            int mid = (l+r)/2;
            // cout << mid << endl;
            int cnt = 0;
            int rem = k;
            int mx = mid;
            for(int i=n-1; i>=0; i--){
                if(v[i].first < mid){
                    if(v[i].second == 0) continue;
                    if(mid-v[i].first <= rem){
                        rem -= mid-v[i].first;
                        cnt++;
                    }
                }
                else cnt++;
                mx = max(mx, v[i].first);
            }
            if(cnt >= (n+1)/2+1){
                best_ans = mx + mid;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        ans = max(ans, best_ans);
        cout << ans << endl;
    }
}