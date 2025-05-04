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
int maxsz = 1;
int root[300300], sz[300300];

int find(int x) {
    while (x != root[x]) {
        if(root[x] != root[root[x]]) root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unite(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if (sz[roota] < sz[rootb]){
        sz[rootb]+=sz[roota];
        maxsz = max(maxsz, sz[rootb]);
        root[roota] = rootb;
    } else{
        sz[roota] += sz[rootb];
        maxsz = max(maxsz, sz[roota]);
        root[rootb] = roota;
    }
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>>v(n);
    for(int i=0; i<n; i++){
        int a1, a2, a3, a4, a5;
        cin >> a1 >> a2 >> a3 >> a4 >> a5;
        v[i] = {a1, a2, a3, a4, a5};
    }
    int q;
    cin >> q;
    vector<pair<int, int>>queries(q);
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        queries[i] = {a, b};
    }
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    map<pair<int, int>, int>adj;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            // if(find(i) == find(j)) continue;
            int ct =0 ;
            for(int k=0; k<5; k++){
                if(v[i][k] == v[j][k]) ct++;
            }
            if(ct == 1){
                // unite(i, j);
                adj[{i, j}] = 1;
                adj[{j, i}] = 1;
            }
        }
    }
    // cout << adj[{2, 3}] << endl;
    for(int i=0; i<q; i++){
        bool flag = false;
        for(int j=0; j<n; j++){
            if(adj[{queries[i].first-1, j}] && adj[{queries[i].second-1, j}]){
                cout << "YES" << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            // if(adj[{queries[i].first, queries[i].second}]){
            //     cout << "YES" << endl;
            // }
            // else cout << "NO" << endl;
            cout << "NO" << endl;
        }
        // if(find(queries[i].first) == find(queries[i].second)){
        //     cout << "YES" << endl;
        // }
        // else cout << "NO" << endl;
    }
    
}