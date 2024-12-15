#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;


bool check(vector<pair<long long, long long>>v, long long mid){
    
    auto it = lower_bound(v.begin(), v.end(), make_pair(mid, (long long)0));
    int idx = it-v.begin();
    // v3.clear();
    // multiset<pair<long long, long long>>v3;
    if(idx==0)return true;
    vector<long long>v3(idx);
    vector<long long>v4((int)v.size()-idx);
    if(idx>(int)v.size()-idx)return false;
    for(int j=idx; j<v.size(); j++){
        v4[j-idx] = v[j].first - mid + v[j].second;
    }
    for(int j=0; j<idx; j++){
        v3[j] = v[j].second;
    }
    sort(v3.begin(), v3.end());
    sort(v4.begin(), v4.end());
    for(int j=1; j<=(int)v3.size(); j++){
        if(v3[(int)v3.size()-j]>v4[(int)v4.size()-j]) return false;
    }
    return true;
    // if(idx ==0) return true;
    // for(int j=0; j<idx; j++){
    //     // v3.insert({v[j].second, v[j].first});
    //     v3[j] = {v[j].second, v[j].first};
    // }
    
    // // if(v3.empty()) return true;
    // // cout << idx << " " << mid << endl;
    // // sort(v3.begin(), v3.end());
    // // cout << "here" << endl;
    // // cout << idx << " "<< v.size() << endl;
    // for(int j=idx; j<v.size(); j++){
    //     // long long wj = v[j].second;
    //     if(v3.empty()) return true;
    //     auto it2 = lower_bound(v3.begin(), v3.end(), make_pair(v[j].first - mid + v[j].second, (long long)0));
    //     if(it2==v3.end()){
    //         --it2;
    //         v3.erase(it2);
    //     }
    //     else if(it2->first>v[j].first - mid + v[j].second && it2!=v3.begin()){
    //         --it2;
    //         v3.erase(it2);
    //     }
    //     else if(it2->first==v[j].first - mid + v[j].second){
    //         v3.erase(it2);
    //     }
    //     // else if(it2==v3.begin()){
    //     //     continue;
    //     // }
        
    // }
    // if(v3.empty()) {
    //     // cout << "here" << endl;
    //     return true;
    // }
    // else return false;
}
int main(){
    long long t, n;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        vector<pair<long long, long long>>v(n);
        // vector<pair<long long, long long>>v2(n);
        for(int j=0; j<n; j++){
            long long s, w;
            cin >> s >> w;
            v[j] = {s, w};
            // v2.push_back({w, s});
        }
        // cout << v.size() << endl;
        sort(v.begin(), v.end());
        // sort(v2.begin(), v2.end());
        long long left = 1, right = 1e9;
        long long ans;
        while(left<=right){
            long long mid = (left+right)/2;
            // cout << mid << endl;
            if(check(v, mid)){
                // cout << "here " << mid << endl;
                left = mid+1;
                ans = mid;
            }
            else right = mid-1;
        }
        cout << ans << endl;
        v.clear();
    }
}