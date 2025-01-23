#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;
long long ans = 0;
void nonleafdfs(int cur, int par, vector<long long>&nonleaf, vector<vector<int>>&children, vector<int>&vis, vector<bool>&adjleafnode){
    vis[cur] = 1;
    bool t = false;
    // bool tt = fals
    if(par!=0 && children[par].size()==1){
        t = true;
    }
    
    for(int c : children[cur]){
        if(vis[c] || c==par) continue;
        nonleafdfs(c, cur, nonleaf, children, vis, adjleafnode);
        nonleaf[cur] += nonleaf[c];
        if(children[c].size() == 1){
            t = true;
        }
    }
    
    if(children[cur].size() == 1){
        t = true;
    }
    else adjleafnode[cur] = t;
    if(!t){
        nonleaf[cur]++;
    }
}
void solve(int cur, int par, vector<long long>&nonleaf, vector<vector<int>>&children, vector<int>&vis, vector<bool>&adjleafnode){
    vis[cur] = 1;
    for(int c : children[cur]){
        if(!vis[c] && c!=par){
            solve(c, cur, nonleaf, children, vis, adjleafnode);
        }
        if(c!=par && adjleafnode[c] && children[cur].size() != 1){
            // cout << "cur: " << cur << " c: " << c << endl;
            ans+=nonleaf[c];
        }
    }
    if(children[cur].size()!=1 && adjleafnode[par]){
        // cout << "cur: " << cur << " par: " << par << endl;
        ans+=(nonleaf[1]-nonleaf[cur]);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<vector<int>>children(n+1);
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            children[a].push_back(b);
            children[b].push_back(a);
        }
        ans =0;
        long long t1 = 0, t2 = 0;
        for(int i=1; i<=n; i++){
            if(children[i].size() == 1){
                t1++;
            }
            else{
                t2++;
            }
        }
        ans+=t1*t2;
        vector<long long>nonleaf(n+1, 0);
        vector<bool>adjleafnode(n+1, false);
        vector<int>vis(n+1, 0);
        vector<int>vis2(n+1, 0);
        nonleafdfs(1, 0, nonleaf, children, vis, adjleafnode);
        // for(int i=1; i<=n; i++){
        //     cout << nonleaf[i] << " ";
        //     if(adjleafnode[i]){
        //         cout << "true ";
        //     }
        //     else cout << "false ";
        //     cout << endl;
        // }
        // cout << endl;
        solve(1, 0, nonleaf, children, vis2, adjleafnode);
        // cout << max(dp[1][0], dp[1][1]) << endl;
        cout << ans << endl;

    }
}