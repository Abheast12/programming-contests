#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
using namespace std;
int mod = 998244353;
vector<int> dfs(int cur, int m, vector<vector<int>>&adj, vector<vector<int>>&dp){
    if(dp[cur][0] != -1){
        return dp[cur];
    }
    vector<int>ans(m+1, 1);
    ans[0] = 0;
    if(adj[cur].size() == 0){
        return ans;
    }

    for(int c : adj[cur]){
        vector<int>tmp = dfs(c, m, adj, dp);
        
        for(int i=1; i<m+1; i++){
            // ans[i] = (ans[i]*tmp[i])%mod;
            tmp[i] = tmp[i-1] + tmp[i];
            tmp[i] %= mod;
            ans[i] = (ans[i]*tmp[i])%mod;
        }
    }
    // vector<int>tmp2 (m+1, 0);
    // for(int i=1; i<m+1; i++){
    //     tmp2[i] = tmp2[i-1] + ans[i];
    //     tmp2[i] %= mod;
    // }
    // dp[cur] = tmp2;
    dp[cur] = ans;
    return ans;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    // cin >> t;
    
        int n, m;
        cin >> n >> m;
        vector<vector<int>>adj(n+1);
        vector<vector<int>>adj2(n+1);
        // map<int, int>mp;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
            adj[i].push_back(v[i]);
            adj2[v[i]].push_back(i);
        }
        // cout << "here" << endl;
        vector<int>vis(n+1, 0);
        int mxd = 0;
        map<int, int>cycle;
        map<int, int>newVertex;
        vector<int>heads;
        for(int i=1; i<=n; i++){
            // cout << i << endl;
            stack<int>q;
            int cur = i;  
            while(!vis[cur]){
                vis[cur] = i;
                q.push(cur);
                cur = adj[cur][0];
            }
            if(!q.empty() && vis[cur] == i){
                // int tmp = q.top();
                heads.push_back(cur);
                cycle[cur] = 1;
                newVertex[cur] = cur;
                // q.pop();
                while(!q.empty()){
                    if(q.top() == cur){
                        break;
                    }
                    cycle[q.top()] = 1;
                    adj2[cur].insert(adj2[cur].end(), adj2[q.top()].begin(), adj2[q.top()].end());
                    newVertex[q.top()] = cur;
                    q.pop();
                }
                vector<int>newAdj;
                for(int i=0; i<adj2[cur].size(); i++){
                    if(newVertex[adj2[cur][i]] != cur){
                        newAdj.push_back(adj2[cur][i]);
                    }
                }
                adj2[cur] = newAdj;
            }
            
        }
        // cout << "here" << endl; 
        // for(auto it : cycle){
        //     cout << it.first << " " << it.second << endl;
        // }
        for(int i=1; i<=10; i++){
            if(cycle[i] && newVertex[i] != i){
                continue;
            }
            cout << i << ": " << endl;
            for(int j=0; j<adj2[i].size(); j++){
                cout << adj2[i][j] << " ";
            }
            cout << endl;
        }
        vector<int>ans(m+1, 1);
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        for(int i=1;i<=n; i++){
            if(cycle[i] && newVertex[i] != i){
                continue;
            }
            else {
                vector<int>tmp = dfs(i, m, adj2, dp);
                for(int i=1; i<m+1; i++){
                    ans[i] = (ans[i]*tmp[i])%mod;
                }
            }
        }
        int lans =0;
        for(int i=1; i<m+1; i++){
            lans = (lans + ans[i])%mod;
        }
        cout << lans << endl;


    
}