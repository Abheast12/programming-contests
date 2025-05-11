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

void dfs(int node, int parent, vector<vector<int>>&adj, vector<int>&height, vector<int>&tired, vector<vector<int>>&dp){
    // int mod = 1e9 + 7;
    bool isLeaf = true;
    // int tot1 =0, tot2=0;
    int totc = 0;
    int totd = 0;
    vector<int>child0;
    vector<int>child2;
    for(auto child: adj[node]){
        if(child == parent) continue;
        if(height[child] >= height[node]){
            child0.push_back(child);
        }
        if(height[child]<=height[node]){
            child2.push_back(child);
        }
        isLeaf = false;
        dfs(child, node, adj, height,tired, dp);
        // tot1+= dp[child][0];
        // tot2+=dp[child][2];
        totc+=tired[node];
        totc+=tired[child];
        totd+=min({dp[child][0], dp[child][1], dp[child][2]});
    }
    

    if(isLeaf){
        dp[node][0] =0;
        dp[node][2] = 0;
        return;
    }

    int val0 = 1e18;
    for(auto child: child0){
        int mn = min({dp[child][0], dp[child][1], dp[child][2]});
        val0 = min(val0, totd-mn+dp[child][0]-tired[child]);
    }
    int val2 = 1e18;
    for(auto child: child2){
        int mn = min({dp[child][0], dp[child][1], dp[child][2]});
        val2 = min(val2, totd-mn+dp[child][2]-tired[child]);
    }
    dp[node][0] = val0+totc;
    dp[node][2] = val2+totc;
    if(child0.size() > 0 && child2.size() > 0){
        dp[node][1] = val0+val2-totd-tired[node]+totc;
    }
    cout << node << " " << dp[node][0] << " " << dp[node][1] << " " << dp[node][2] << endl; 
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> t;
    // while(t--){
        int n;
        cin >> n;
        // vector<pair<int, int>>v(n+1);
        vector<int>height(n+1), tired(n+1);
        for(int i=1; i<=n; i++){
            cin >> tired[i];
        }
        for(int i=1; i<=n; i++){
            cin >> height[i];
        }
        vector<vector<int>>adj(n+1);
        for(int i=0; i<n-1; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>>dp(n+1, vector<int>(3, 1e18));
        dfs(1, -1, adj, height, tired, dp);
        // int mod = 1e9 + 7;
        int ans = min({dp[1][0], dp[1][1], dp[1][2]});
        cout << ans << endl;
    // }
    
}