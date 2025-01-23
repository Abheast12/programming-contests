#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        map<long long, long long> mp;
        vector<pair<long long, long long>> vp;
        for(int i=0; i<n; i++){
            cin >> v[i];
            mp[v[i]]++;
        }
        for(auto x: mp){
            vp.push_back({x.second, x.first});
        }
        sort(vp.begin(), vp.end());
        
        if(vp.size() == 1){
            cout << 1 << endl;
            continue;
        }
        int cur = 0;
        int tmp = 1;
        while(k>0 && cur != vp.size()-1){
            if(vp[cur].first <= k){
                k-=vp[cur].first;
                tmp++;
            }
            else break;
            cur++;
        }
        cout << vp.size()-tmp+1 << endl;
    }
}