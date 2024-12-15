#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;
map<long long, int> vis;
long long dfs(long long tot, map<long long, vector<long long>>&m){
    vis[tot] = 1;
    if(m[tot].size() == 0){
        return tot;
    }
    long long ans = 0;
    for(long long x: m[tot]){
        if(!vis[tot+x]) ans = max(ans, dfs(tot + x, m));
    }
    return max(tot,ans);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long> v(n);
        map<long long, vector<long long>>m;
        for(int i=0; i<n; i++){
            cin >> v[i];
            m[v[i]+i].push_back(i);
        }
        long long ans = dfs(n, m);
        cout << ans << endl;
        v.clear();
        m.clear();
        vis.clear();
    }
}