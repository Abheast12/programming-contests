#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include <stdio.h>
#include <string.h>

using namespace std;
long long ans[300005][24];
vector<int> adj[300005];
long long w[300005];
long long smn[24];
void dfs(int x, int par) {
    for(int i=1; i<=22; i++){
        ans[x][i] = w[x]*i;
    }
    for(int j : adj[x]){
        if(j == par) continue;
        dfs(j, x);
        smn[23] = 8e18;
        for(int i=22; i>=1; i--){
            smn[i] = min(smn[i+1], ans[j][i]);
        }
        long long tmp = 8e18;
        for(int i=1; i<=22; i++){
            ans[x][i] += min(tmp, smn[i+1]);
            tmp = min(tmp, ans[j][i]);
            // ans[x][i] += tmp;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // vector<long long> w(n+1);
        // vector<vector<int>> adj(n+1);
        // vector<int>vis(n+1, 0);
        for(int i=1; i<=n; i++){
            cin >> w[i];
        }
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1, 0);
        long long min_ans = 8e18;
        for(int i=1; i<=22; i++){
            min_ans = min(min_ans, ans[1][i]);
        }
        cout << min_ans << endl;
        for(int i=1; i<=n; i++){
            adj[i].clear();
            memset(ans[i], 0, sizeof(ans[i]));
        }
        // queue<int> q;
        // q.push(1);
        // vis[1] = 1;
        // while(!q.empty()){
        //     int u = q.front();
        //     q.pop();
        //     for(int v: adj[u]){
        //         if(vis[v] == 0){
        //             if(vis[u] == 1){
        //                 vis[v] = 2;
        //             }
        //             else{
        //                 vis[v] = 1;
        //             }
        //             q.push(v);
        //         }
        //         else if(vis[v] == vis[u]){
        //             return -1;
        //         }
        //     }
        // }
        // long long sum1 = 0, sum2 = 0;
        // for(int i=1; i<=n; i++){
        //     if(vis[i] == 1){
        //         sum1 += w[i];
        //     }
        //     else{
        //         sum2 += w[i];
        //     }
        // }
        // long long ans = sum1+sum2;
        // if(sum1 < sum2) ans+=sum1;
        // else ans+=sum2;
        // cout << ans << endl;
        // w.clear();
        // adj.clear();
        // vis.clear();
    }
}