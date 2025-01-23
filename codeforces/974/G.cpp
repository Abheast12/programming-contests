#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, m, k;
        cin >> n >> m >> k;
        vector<pair<long long, long long>>v(n);
        for(int i=0; i<n; i++){
            long long a, d;
            cin >> d >> a;
            v[i] = {d, a};
        }
        if(n==1){
            // come back later
            continue;
        }
        long long ans =0;
        // map<int ,int>mp;
        for(int i=1; i<n; i++){
            long long dif = v[i].first - v[i-1].first;
            long long day = v[i-1].first;
            long long cur =i-1;
            while(true){
                if(v[cur].first+k-1 >= day){
                    long long div = (v[cur].second+m-1)/m;
                    long long time = min(dif, k);
                }
                
            }
            if(dif > k){
                dif = k;
                // mp[i] = 1;
                v.erase(v.begin()+i);
            }

        }
    }
}