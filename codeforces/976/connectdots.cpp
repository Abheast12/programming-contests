#include<iostream>
#include<set>
#include<cstring>
#include<vector>
using namespace std;


// int root[200200], sz[200200];

// int find(int x) {
//     while (x != root[x]) {
//         if(root[x] != root[root[x]]) root[x] = root[root[x]];
//         x = root[x];
//     }
//     return x;
// }
// void unite(int a, int b) {
//     int roota = find(a);
//     int rootb = find(b);
//     if (sz[roota] < sz[rootb]){
//         sz[rootb]+=sz[roota];
        
//         root[roota] = rootb;
//     } else{
//         sz[roota] += sz[rootb];

//         root[rootb] = roota;
//     }
    
// }
void dfs(int u, vector<vector<int>>&adj, vector<int>&vis, int n){
    vis[u] = 1;
    for(int v: adj[u]){
        if(vis[v]==0){
            dfs(v, adj, vis, n);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        // for (int i = 1; i <= n; i++) root[i] = i;
        // for (int i = 1; i <= n; i++) sz[i] = 1;
        vector<vector<int>>dp(n+1, vector<int>(11, 0));
        for(int i=0; i<m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            dp[a][b] = max(dp[a][b], c);
            // for(int i=1; i<=c; i++){
            //     if(find(a)!=find(a+b*i)){
            //         unite(a, a+b*i);
            //     }
            // }
        }
        vector<vector<int>>adj(n+1);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=10; j++){
                // if(i-j>=1){
                //     dp[i][j] = 
                // }
                if(i+j<=n){
                    if(dp[i][j]>0){
                        dp[i+j][j] = max(dp[i+j][j], dp[i][j]-1);
                        adj[i].push_back(i+j);
                        adj[i+j].push_back(i);
                    }
                    
                }
            }
        }
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=10; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int>vis(n+1, 0);
        int ans =0;
        for(int i=1; i<=n; i++){
            if(vis[i]==0){
                ans++;
                dfs(i, adj, vis, n);
            }
        }
        cout << ans << endl;
        // set<int>s;
        // for(int i=1; i<=n; i++){
        //     s.insert(find(i));
        // }
        // cout << s.size() << endl;
        // s.clear();
        

    }   
}