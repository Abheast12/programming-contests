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
    int n, q;
    cin >> n >> q;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<pair<pair<int, int>, int>>queries;
    for(int i=0; i<q; i++){
        int r, x;
        cin >> r >> x;
        r--;
        queries.push_back({{r, x}, i});
    }
    vector<int>ans(q);
    sort(queries.begin(), queries.end());
    vector<int>lis;
    // vector<vector<int>>liss;
    int cur =0;
    for(int i=0; i<n; i++){
        auto it = lower_bound(lis.begin(), lis.end(), v[i]);
        if(it == lis.end()){
            lis.push_back(v[i]);
        }
        else{
            *it = v[i];
        }
        // liss.push_back(lis);
        while(cur < q && queries[cur].first.first == i){
            int x = queries[cur].first.second;
            auto it = upper_bound(lis.begin(), lis.end(), x);
            ans[queries[cur].second] = it - lis.begin();
            cur++;
        }
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
    
}