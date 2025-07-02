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
long long maxsz = 1;
int find(int x, vector<long long>&root) {
    while (x != root[x]) {
        if(root[x] != root[root[x]]) root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unite(int a, int b, vector<long long>&root, vector<long long>&sz) {
    int roota = find(a, root);
    int rootb = find(b, root);
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>>edges;
    vector<vector<pair<int, int>>>adj(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        // adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
        edges.push_back({w, {u, v}});
    }  
    int ans = 1<<30;
    ans--;
    // cout << ans << endl;
    for(int i=29; i>=0; i--){
        vector<long long>root(n+1), sz(n+1);
        for (int j = 1; j <= n; j++) root[j] = j;
        for (int j = 1; j <= n; j++) sz[j] = 1;
        ans -= (1<<i);
        for(int j=0; j<m; j++){
            if((edges[j].first | ans) == ans){
                int u = edges[j].second.first;
                int v = edges[j].second.second;
                unite(u, v, root, sz);
            }
        }
        if(find(1, root) != find(n, root)) ans += (1<<i);
        // cout << ans << endl;
        
    }
    cout << ans << endl;
}