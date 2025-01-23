#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
bool check(vector<pair<long long, long long>>&v, long long m, long long k, long long mid){
    long long cnt = 0;
    vector<pair<long long, long long>>pts;
    for(int i=0; i<v.size(); i++){
        long long div = ceil((double)v[i].second/(double)mid);
        if(div>m) continue;
        long long dif = m-div;
        // cout << mid << " " << div << " " << dif << endl;
        pts.push_back({v[i].first-dif, 1});
        pts.push_back({v[i].first+dif, 2});
    }
    sort(pts.begin(), pts.end());
    long long ct = 0;
    long long best = 0;
    for(int i=0; i<pts.size(); i++){
        if(pts[i].second==1){
            ct++;
        }
        else{
            ct--;
        }
        best = max(best, ct);
    }

    return best>=k;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, m, k;
        cin >> n >> m >> k;
        vector<pair<long long, long long>>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i].second;
        }
        for(int i=0; i<n; i++){
            cin >> v[i].first;
        }
        sort(v.begin(), v.end());
        long long ans = -1;
        long long l = 1, r = 1e10;
        while(l<r){
            long long mid = (l+r)/2;
            if(check(v, m, k, mid)){
                ans = mid;
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        cout << ans << endl;
    }
}