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
void dfs(int cur, int par, vector<int>&traversal, vector<vector<int>>&adj, map<int, int>&beg, map<int, int>&ed){
    traversal.push_back(cur);
    beg[cur] = traversal.size()-1;
    for(auto x: adj[cur]){
        if(x != par){
            dfs(x, cur, traversal, adj, beg, ed);
        }
    }
    traversal.push_back(cur);
    ed[cur] = traversal.size()-1;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>w(n+1);
        vector<vector<int>>adj(n+1);
        for(int i=1; i<=n; i++){
            cin >> w[i];
        }
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>traversal;
        map<int, int>beg;
        map<int, int>ed;
        dfs(1, 0, traversal, adj, beg, ed);
        vector<int>pre(traversal.size(), 0);
        for(int i=0; i<traversal.size(); i++){
            if(i == 0){
                pre[i] = w[traversal[i]];
                continue;
            }
            pre[i] = max(pre[i-1], w[traversal[i]]);
        }
        vector<int>suf(traversal.size(), 0);
        for(int i=traversal.size()-1; i>=0; i--){
            if(i == traversal.size()-1){
                suf[i] = w[traversal[i]];
                continue;
            }
            suf[i] = max(suf[i+1], w[traversal[i]]);
        }
        int ans =0;
        int val = 0;
        for(int i=2; i<=n; i++){
            int l = beg[i];
            int r = ed[i];
            int tmp = max(pre[l-1], suf[r+1]);
            if(w[i] < tmp){
                if(val < w[i]){
                    val = w[i];
                    ans = i;
                }
            }
        }
        cout << ans << endl;
    }
}