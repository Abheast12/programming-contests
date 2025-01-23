#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        long long n, m, q;
        cin >> n >> m >> q;
        // vector<long long>a(n);
        // vector<long long>d(n);
        vector<pair<long long, long long>>v(n);
        vector<long long>l(m);
        for(int i=0; i<n; i++){
            cin >> v[i].second;
        }
        for(int i=0; i<n; i++){
            cin >> v[i].first;
        }
        vector<long long>pre_l(m, 0);
        for(int i=0; i<m; i++){
            cin >> l[i];
            if(i==0){
                pre_l[i] = l[i];
            }
            else{
                pre_l[i] = pre_l[i-1]+l[i];
            }
        }
        // vector<pair<long long, long long>>v(n);
        // for(int i=0; i<n; i++){
        //     v[i] = {d[i], a[i]};
        // }
        sort(v.begin(), v.end());
        vector<long long> latest_start(n, 0);
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                latest_start[i] = v[i].first - v[i].second;
            }
            else{
                latest_start[i] = min(latest_start[i+1], v[i].first) - v[i].second;
            }
        }
        vector<long long>pre_v(n);
        for(int i=0; i<n; i++){
            if(i==0){
                pre_v[i] = v[i].second;
            }
            else{
                pre_v[i] = pre_v[i-1]+v[i].second;
            }
        }
        // long long cur = 0;
        // vector<long long>times;
        // int p1 =0;
        // int p2 = 0;
        // while(p2 < m){
        //     if(p1 == n){
        //         times.push_back(cur+l[p2]);
        //         cur += l[p2];
        //         p2++;
        //         continue;
        //     }
        //     if(cur+l[p2]<=latest_start[p1]){
        //         times.push_back(cur+l[p2]);
        //         cur += l[p2];
        //         p2++;
        //     }
        //     else{
        //         cur+= v[p1].second;
        //         p1++;
        //     }
        // }
        vector<long long>queries(q);
        for(int i=0; i<q; i++){
            cin >> queries[i];
        }
        for(int i=0; i<q; i++){
            auto it = lower_bound(latest_start.begin(), latest_start.end(), queries[i]);
            int dist = distance(latest_start.begin(), it);
            long long start;
            long long e = queries[i];
            if(dist == 0){
                start =0;
            }
            else {
                if(v[dist-1].second+latest_start[dist-1] >= queries[i]){
                    if(dist == 1){
                        start = 0;
                    }
                    else{
                        start = pre_v[dist-2];  
                    }
                    e = latest_start[dist-1];
                }
                else start = pre_v[dist-1];
            }
            // cout << dist << " " << start << endl;
            // int end = queries[i];
            // if()
            auto it2 = lower_bound(pre_l.begin(), pre_l.end(), e-start);
            dist = distance(pre_l.begin(), it2);
            if(e-start == *it2){
                dist++;
            }
            // if(queries[i] == *it){
            //     dist++;
            // }
            cout << dist << " ";
        }
        cout << endl;

    }
}