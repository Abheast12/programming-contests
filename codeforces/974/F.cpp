#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int cur, int par, vector<vector<long long>>&dp, vector<vector<int>>&children, vector<int>&vis, vector<long long>&gold, long long price){
    vis[cur] = 1;
    long long t1 = 0;
    long long t2 = 0;
    for(int c : children[cur]){
        if(vis[c] || c==par) continue;
        dfs(c, cur, dp, children, vis, gold, price);
        t1 += max(dp[c][0], dp[c][1]);
        t2 += max(dp[c][0], dp[c][1]-2*price);
    }
    dp[cur][0] = t1;
    dp[cur][1] = t2+gold[cur];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, c;
        cin >> n >> c;
        vector<vector<int>>children(n+1);
        vector<long long>gold(n+1);
        for(int i=1; i<=n; i++){
            cin >> gold[i];
        }
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            children[a].push_back(b);
            children[b].push_back(a);
        }
        vector<vector<long long>>dp(n+1, vector<long long>(2, -1LL*1e10));
        vector<int>vis(n+1, 0);
        dfs(1, 0, dp, children, vis, gold, c);
        cout << max(dp[1][0], dp[1][1]) << endl;

    }
}