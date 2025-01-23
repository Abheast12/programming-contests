#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(int cur, int par, vector<vector<int>>&dp, vector<vector<int>>&children, vector<int>&vis){
    vector<int>child;
    vis[cur] = 1;
    int t1 =0;
    int t2 =0;
    int t3 =0;
    for(int c : children[cur]){
        if(vis[c] || c==par) continue;
        dfs(c, cur, dp, children, vis);
        child.push_back(dp[c][0]);
        t2 = max(t2, dp[c][1]);
        t3 = max(t3, dp[c][2]);
        // int val = dp[c];
        // if(dp[c]==0){
        //     val = dfs(c, dp, children);
        // }
        // if(children[c].size() == 1 && val >=2){
        //     val--;
        // }
        // child.push_back(val);
    }
    sort(child.begin(), child.end());
    reverse(child.begin(), child.end());
    // int t11 =0;
    if(child.size()>0){
        t1 = child[0];
    }
    dp[cur][0] = max(t1+(int)child.size()-1, (int)child.size());
    dp[cur][2] = max(t3, max(t1, t2)+1);
    if(child.size()>=2){
        dp[cur][1] = child[0]+child[1]+child.size()-2;
    }
    else dp[cur][1] = 0;
    
    // if(child.size()==0){
    //     dp[cur] = 1;
    // }
    // else if(child.size()==1){
    //     if(children[children[cur][0]].size() == 0){
    //         dp[cur] = 1;
    //     }
    //     else if(children[children[cur][0]].size() == 1){
    //         if(children[children[children[cur][0]][0]].size() == 0){
    //             dp[cur] = child[0]+1;
    //         }
    //         else dp[cur] = dp[children[cur][0]];
    //     }
    //     else{
    //         dp[cur] = child[0]+1;
    //     }
    // }
    // else{
    //     dp[cur] = child[0]+child[1]+child.size()-2;
    // }
    // return dp[cur];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>children(n+1);
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            // if(a > b) swap(a, b);
            children[a].push_back(b);
            children[b].push_back(a);
        }
        // dp[i][0] -> i is end of path
        // dp[i][1] -> i is not end of path but is included in path
        // dp[i][2] -> i is not included in path
        vector<vector<int>>dp(n+1, vector<int>(3, 0));
        vector<int>vis(n+1, 0);
        dfs(1, 0, dp, children, vis);
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
            // cout << i << " " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
        }
        // cout << max(dp[1][0], max(dp[1][1], dp[1][2])) << endl;
        cout << ans << endl;

    }
}