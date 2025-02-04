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

// long long maxsz = 1;
// int find(int x, vector<long long>&root) {
//     while (x != root[x]) {
//         if(root[x] != root[root[x]]) root[x] = root[root[x]];
//         x = root[x];
//     }
//     return x;
// }
// void unite(int a, int b, vector<long long>&root, vector<long long>&sz) {
//     int roota = find(a, root);
//     int rootb = find(b, root);
//     if (sz[roota] < sz[rootb]){
//         sz[rootb]+=sz[roota];
//         maxsz = max(maxsz, sz[rootb]);
//         root[roota] = rootb;
//     } else{
//         sz[roota] += sz[rootb];
//         maxsz = max(maxsz, sz[roota]);
//         root[rootb] = roota;
//     } 
// }

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int, int>>v(n);
        // vector<long long>root(n+1), sz(n+1);
        // for (int i = 1; i <= n; i++) root[i] = i;
        // for (int i = 1; i <= n; i++) sz[i] = 1;

        for(int i=0; i<n; i++){
            int a;
            cin >> a;
            v[i] = {a, i+1};
        }
        cout << "YES" << endl;
        vector<pair<int, int>>ops;
        for(int i=n-1; i>=1; i--){
            map<int, int>m;
            for(int j= 0; j<v.size(); j++){
                if(m[v[j].first%i]){
                    
                    ops.push_back({m[v[j].first%i], v[j].second});
                    v.erase(v.begin()+j);
                    break;
                }
                else{
                    m[v[j].first%i] = v[j].second;
                }
            }
        }
        reverse(ops.begin(), ops.end());
        for(auto x: ops){
            cout << x.first << " " << x.second << endl;
        }
    }
}