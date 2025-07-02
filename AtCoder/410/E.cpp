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
    int n, h, m;
    cin >> n >> h >> m;
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }  
    int ans =0;
    priority_queue<pair<int, pair< int, int>>> pq;
    pq.push({0, {h, m}});
    for(int i=0; i<n; i++){
        int mval = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int hh = pq.top().second.first;
            int mm = pq.top().second.second;
            if(-d!=i){
                break;
            }
            pq.pop();
            if(mm <= mval){
                continue;
            }
            mval = max(mval, mm);
            if(hh >= v[i].first){
                ans = max(ans, -d+1);
                pq.push({d-1, {hh-v[i].first, mm}});
            }
            if(mm >= v[i].second){
                ans = max(ans, -d+1);
                pq.push({d-1, {hh, mm-v[i].second}});
            }
        }
    }
    cout << ans << endl;
}