#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // cout << n << endl;
        vector<set<int>>adj(n+1);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            // cout << u << " " << v << endl;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        vector<pair<int, int>>v;
        for(int i=1; i<=n; i++){
            v.push_back({adj[i].size(), i});
        }
        if(n<=2){
            cout << 0 << endl;
            continue;
        }
        sort(v.begin(), v.end());
        if(v[n-3].first == v[n-1].first){
            cout << v[n-1].first*2-1 << endl;
        }
        else{
            vector<int>v2;
            vector<int>v3;
            int ans = 0;
            for(int i=1; i<=n; i++){
                if(i == v[n-1].second){
                    continue;
                }
                if(adj[i].find(v[n-1].second) == adj[i].end()){
                    v2.push_back(adj[i].size());
                }
                else{
                    v2.push_back(adj[i].size()-1);
                }
            }
            sort(v2.begin(), v2.end());
            ans = max(ans, v2[v2.size()-1] + v[n-1].first);
            for(int i=1; i<=n; i++){
                if(i == v[n-2].second){
                    continue;
                }
                if(adj[i].find(v[n-2].second) == adj[i].end()){
                    v3.push_back(adj[i].size());
                }
                else{
                    v3.push_back(adj[i].size()-1);
                }
            }
            sort(v3.begin(), v3.end());
            ans = max(ans, v3[v3.size()-1] + v[n-2].first);
            cout << ans-1 << endl;
        }
    }
}