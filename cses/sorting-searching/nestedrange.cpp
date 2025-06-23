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
   
    int n;
    cin >> n;
    
    // map<int, pair<int, int>> m;
    vector<pair<pair<int, int>, int>> v;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({{x, y}, i});
    }
    sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    });
    vector<int>ans1(n, 0);
    vector<int>ans2(n, 0);
    int mxr = 0;
    for(int i=0; i<n; i++){
        if(v[i].first.second <= mxr){
            ans1[v[i].second] = 1;
        }
        mxr = max(mxr, v[i].first.second);
    }
    int mnr = 1e18;
    for(int i=n-1; i>=0; i--){
        if(v[i].first.second >= mnr){
            ans2[v[i].second] = 1;
        }
        mnr = min(mnr, v[i].first.second);
    }
    for(int i=0; i<n; i++){
        cout << ans2[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << ans1[i] << " ";
    }
    cout << endl;

    
}