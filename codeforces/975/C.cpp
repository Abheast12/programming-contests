#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dfs(int cur, int par, vector<vector<int>>&adj, vector<int>&maxd, vector<int>&d, int depth){
    d[cur] = depth;
    int mx = -1;
    for(int c : adj[cur]){
        if(c == par){
            continue;
        }
        mx = max(mx, dfs(c, cur, adj, maxd, d, depth+1));
    }
    if(mx==-1){
        maxd[cur] = depth;
        return depth;
    }
    else{
        maxd[cur] = mx;
        return mx;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);    
            adj[b].push_back(a);
        }
        vector<int>maxd(n+1, 0);
        vector<int>d(n+1, 0);
        dfs(1, 0, adj, maxd, d, 0);
        int ans = 0;
        vector<pair<int, int>>v;
        for(int i=1; i<=n; i++){
            v.push_back({d[i], 1});
            v.push_back({maxd[i], 2});
        }
        sort(v.begin(), v.end());
        int ct =0 ;
        for(int i=0; i<v.size(); i++){
            if(v[i].second == 1){
                ct++;
            }
            else{
                ct--;
            }
            ans = max(ans, ct);
        }
        cout << n-ans << endl;
    }
}