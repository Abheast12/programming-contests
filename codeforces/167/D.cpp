#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int m, n;
    
    cin >> n >> m;
    vector<long long> a(n), b(n), c(m);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    for(int i=0; i<m; i++){
        cin >> c[i];
    }
    vector<pair<long long, long long>> dif(n);
    for(int i=0; i<n; i++){
        dif[i] = {a[i]-b[i], a[i]};
    }
    sort(dif.begin(), dif.end());
    long long ans = 0;
    vector<pair<long long, long long>>opt;
    long long lb = dif[0].second-dif[0].first;
    long long ld = dif[0].first;
    opt.push_back({dif[0].first, dif[0].second});
    for(int i=1; i<n; i++){
        if(dif[i].first > ld && dif[i].second >= lb){
            opt.push_back({dif[i].first, dif[i].second});
            lb = dif[i].second-dif[i].first;
            ld = dif[i].first;
        }
    }
    // vector<long long> psum(opt.size());
    sort(c.begin(), c.end());
    // psum[opt.size()-1] = 0;
    long long sum = 0;
    long long active = 0;
    int pos = m-1;
    for(int i=0; i<opt.size(); i++){
        if(pos < 0)break;
        while(pos>=0 && c[pos] >= opt[i].second){};
    }
}