#include<iostream>
#include<vector>

using namespace std;
#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i].first;
        }
        for(int i=0; i<n; i++){
            cin >> v[i].second;
        }
        int l = 0, r = 1e9;
        int best = -1;
        int best_ans = -1;
        while(l<=r){
            int mid = (l+r)/2;
            int cnt = 0;
            int tmp_ans = 0;
            
            for(int i=0; i<n; i++){
                if(mid+1 > v[i].first) continue;
                int tmp = (v[i].first - (mid+1))/v[i].second;
                int num = tmp+1;
                int beg = v[i].first - tmp*v[i].second;
                int gg = (v[i].first + beg)*num/2;
                cnt+= (num);
                if(cnt>k) break;
                tmp_ans += gg;
            }
            // cout << mid << " " << cnt << " " << tmp_ans << endl;
            for(int i=0; i<n; i++){
                if(cnt >= k) break;
                if(v[i].first>=mid && (v[i].first-mid)%v[i].second == 0){
                    cnt++;
                    tmp_ans += mid;
                }
            }
            if(cnt >= k){
                best = mid;
                l = mid+1;   
            }
            else r = mid-1;
            if(cnt<=k) best_ans = max(best_ans, tmp_ans);
        }
        cout << best_ans << endl;
    }   
}