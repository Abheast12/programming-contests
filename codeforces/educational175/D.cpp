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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int>par;
        vector<vector<int>>adj(n+1);
        for(int i=2; i<=n; i++){
            int a;
            cin >> a;
            adj[a].push_back(i);
            par[i] = a;
        }
        queue<pair<int, int>>q;
        q.push({1, 0});
        vector<int>dp(n+1, 0);
        dp[1] = 1;
        vector<int>sm(n+1, 0);
        sm[0] = 1;
        int md = 998244353;
        while(!q.empty()){
            int x = q.front().first;
            int d = q.front().second;
            q.pop();
            if(par[x] == 1){
                dp[x] = 1;
                sm[d] += dp[x];
                sm[d] = (sm[d]+md)%md;
            }
            else if(x!=1){
                dp[x] = sm[d-1]-dp[par[x]];
                dp[x] = (dp[x]+md)%md;
                sm[d] += dp[x];
                sm[d] = (sm[d]+md)%md;
            }
            for(auto v:adj[x]){
                // cout << v << " " << x << " " << d << " " << dp[par[v]] << endl;
                
                q.push({v, d+1});
            }
        }
        int ans = 0;
        for(int i=0; i<=n; i++){
            ans = (ans+sm[i])%md;
        }
        cout << ans << endl;
    }
}