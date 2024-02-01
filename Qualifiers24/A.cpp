#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<long long, long long>>v;

int main(){
    long long t, n, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> k;
        vector<long long>v2(n);
        bool t = false;
        for(int j=0; j<n; j++){
            long long a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());
        for(int j=0; j<n; j++){
            if(j==0){
                v2[j] = v[j].second;
            }
            else v2[j] = v[j].second+v2[j-1];
            if(v2[j]>k*(v[j].first)){
                cout << "No" << endl;
                t = true;
                break;
            }
        }
        if(!t) cout << "Yes" << endl;
        v.clear();
    }
}