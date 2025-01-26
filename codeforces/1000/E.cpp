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
void dfs(map<int, int>&mp, int cur, int par, int d, vector<vector<int>>&adj){
    mp[d]++;
    for(int j : adj[cur]){
        if(j != par){
            dfs(mp, j, cur, d+1, adj);
        }
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        map<int, vector<int>>store;
        vector<int>tot(n+1, 0);
        for(int j : adj[1]){
            map<int, int>mp;
            dfs(mp, j, 1, 1, adj);
            vector<int>v(mp.size()+1);
            for(int i=1; i<=mp.size(); i++){
                v[i] = mp[i];
                tot[i]+=mp[i];
            }
            vector<int>pre(mp.size()+1, 0);
            for(int i=1; i<=mp.size(); i++){
                pre[i] = v[i];
                if(i > 0){
                    pre[i] += pre[i-1];
                }
            }
            store[j] = pre;
        }
        vector<int>pr(n+1, 0);
        for(int i=1; i<=n; i++){
            pr[i] = tot[i];
            if(i > 0){
                pr[i] += pr[i-1];
            }
        }




    }
}