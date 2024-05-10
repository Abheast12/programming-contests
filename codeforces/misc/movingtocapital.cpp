#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;
vector<int>v[200200];
int vis[200200];
int ans[200200] = {INT_MAX};
int dfs(int cur, const int ans2[]){
    vis[cur] = 1;
    for(int k=0; k<v[cur].size(); k++){
        if(ans2[v[cur][k]] > ans2[cur]){
            if(!vis[v[cur][k]]){
                ans[cur] = min(ans[cur], dfs(v[cur][k], ans2));
            }
            else{
                ans[cur] = min(ans[cur], ans[v[cur][k]]);
            }
        }
        else {
            ans[cur] = min(ans[cur], ans2[v[cur][k]]);
        }
    }
    return ans[cur];
}
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int vis2[200200] = {0};
        
        map<pair<int, int>, int>mp;
        int m, n;
        cin >> n >> m;
        // cout << n << m << endl;
        for(int j=0; j<m; j++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
        }
        queue<pair<int, int>>q;
        q.push({0, 1});
        while(!q.empty()){
            int cur = q.front().second;
            int dist = q.front().first;
            
            q.pop();
            if(vis2[cur]){
                continue;
            }
            ans[cur] = dist;
            vis2[cur] = 1;
            for(int j=0; j<v[cur].size(); j++){
                if(!vis2[v[cur][j]]){
                    q.push({dist+1, v[cur][j]});
                }
            }
        }
        // for(int j=1; j<=n; j++){
        //     cout << ans[j] << " ";
        // }
        // cout << endl;
        vis[1] = 1;
        int ans2[200200] = {INT_MAX};
        for(int j=1; j<=n; j++){
            ans2[j] = ans[j];
        }
        for(int j=2; j<=n; j++){
            if(!vis[j]){
                dfs(j, ans2);
            }
            // cout << j << endl;
            // for(int k=1; k<=n; k++){
            //     cout << ans[k] << " ";
            // }
            // cout << endl;
        }
        for(int j=1; j<=n; j++){
            cout << ans[j] << " ";
        }
        cout << endl;
        for(int j=0; j<=n; j++){
            v[j].clear();
            vis[j] = 0;
            ans[j] = INT_MAX;
        }
    }
}