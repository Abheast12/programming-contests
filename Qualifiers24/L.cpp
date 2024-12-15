#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long s;
    cin >> n >> s;
    vector<long long>t(n);
    vector<long long>a(n);
    for(int i=0; i<n; i++){
        cin >> t[i];
    }
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    // for(int i=0; i<n; i++){
    //     if(abs(a[i])> s*t[i]){
    //         a.erase(a.begin() + i);
    //         t.erase(t.begin() + i);
    //         i--;
    //     }
    // }
    // cout << a.size() << endl;
    vector<pair<long long, long long>>v1;

    for(int i=0; i<a.size(); i++){
        if(s*t[i] >= abs(a[i])){
            v1.push_back({s*t[i] - a[i], s*t[i] + a[i]});
        }
        // else{
        
    }
    
    sort(v1.begin(), v1.end());
    
    vector<long long>ans;
    if(v1.size() > 0){
        ans.push_back(v1[0].second);
        for(int i=1; i<v1.size() ;i++){
            if(v1[i].second>=ans.back()){
                ans.push_back(v1[i].second);
            }
            else{
                auto it = upper_bound(ans.begin(), ans.end(), v1[i].second);
                int idx = it - ans.begin();
                ans[idx] = v1[i].second;
            }
        }
    }
    cout << ans.size() << endl;

}