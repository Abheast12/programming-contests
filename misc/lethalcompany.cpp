#include<iostream>
#include<tuple>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
bool check(vector<tuple<long long, long long, long long>>&v, long long mid, long long k){
    map<long long, pair<long long, long long>>m;
    map<long long, long long>look;
    auto it = upper_bound(v.begin(), v.end(), make_tuple(mid, 1e18+1, 1e18+1));
    if(it == v.begin()){
        return true;
    }
    --it;
    for(auto i=it; i!=v.begin(); i--){
        long long a = get<0>(*i);
        long long b = get<1>(*i);
        long long c = get<2>(*i);
        if(m.find(b)==m.end()){
            m[b] = make_pair(c, a);
            long long tmp = (c+k-1)/k;
            look[b] = tmp-1;
        }
        else{
            long long cur_time = (m[b].first + k-1)/k + (m[b].second-1);
            long long new_time = (c + k-1)/k + (a-1);
            if(new_time >= cur_time){
                continue;
            }
            else{
                if(m[b].first >= c){
                    m[b] = make_pair(c, a);
                    long long tmp = (c+k-1)/k;
                    look[b] = tmp-1;
                }
                else{
                    long long tmp = (c+k-1)/k;
                    if(tmp-1+(a-1)>mid){
                        continue;
                    }
                    look[b] = tmp-1;
                }
            }
        }
    }
    // for(auto i=v.begin(); i!=it; i++){
    //     long long a = get<0>(*i);
    //     long long b = get<1>(*i);
    //     long long c = get<2>(*i);
    //     if(m.find(b)==m.end()){
    //         m[b] = make_pair(c, a);
    //     }
    //     else{
    //         if(m[b].first-c>(a-m[b].second)*k){
    //             m[b] = make_pair(c, a);
    //         }
    //         else if(m.size()==1 && m[b].first > c){
    //             m[b] = make_pair(c, a);
    //         }
    //     }
    // }
    long long tot=0;
    if(m.size()<=1){
        return true;
    }
    // if(mid == 1){
    //     for(auto i=m.begin(); i!=m.end(); i++){
    //         cout << i->first << " " << i->second.first << " " << i->second.second << endl;
    //     }
    // }
    for(auto i=m.begin(); i!=m.end(); i++){
        long long tmp = i->second.first/k;
        if(i->second.first%k!=0){
            tmp++;
        }
        if((tmp-1)+(i->second.second-1)>mid){
            continue;
        }
        tot+=mid-(tmp-1)-(i->second.second-1);
    }
    if(tot <= mid){
        return true;
    }
    return false;
}
int main(){
    long long n, m, k;
    cin >> n >> m >> k;
    vector<tuple<long long, long long, long long>>v;
    for(int i=0; i<m; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        v.push_back(make_tuple(a, b, c));
    }
    sort(v.begin(), v.end());
    long long lb =0, rb = 1e18+1, ans = -1;
    while(lb<=rb){
        // cout << lb << " " << rb << " " << ans << endl;
        long long mid = (lb+rb)/2;
        if(check(v, mid, k)){
            ans = mid;
            lb = mid+1;
        }
        else{
            rb = mid-1;
        }
    }
    if(ans==1e18+1){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}