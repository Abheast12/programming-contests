#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

long long solve(vector<vector<pair<long long, long long>>> &adj, vector<long long>&vis, vector<long long>& weights, long long cur, long long dest, long long k){
    vis[cur] = 1;
    if(cur == dest){
        sort(weights.begin(), weights.end());
        return weights[weights.size()-k];
    }
    for(auto x: adj[cur]){
        if(vis[x.first] == 0){
            weights.push_back(x.second);
            long long tmp = solve(adj, vis, weights, x.first, dest, k);
            if(tmp != -1) return tmp;
            weights.pop_back();
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while(t--){
        long long n, m, q;
        cin >> n >> m>> q;
        vector<vector<pair<long long, long long>>> adj(n+1);
        // vector<long long> v(n);
        for(int i=0; i<m; i++){
            long long a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }

        for(int i=0; i<q; i++){
            long long a, b, k;
            cin >> a >> b >> k;
            queue<pair<long long, pair<vector<long long>, vector<long long>>>> qu;
            qu.push({a, {vector<long long>(n+1, 0), vector<long long>()}});
            // vector<long long> vis(n+1, 0);
            // vector<long long> weights;
            // long long ans = solve(adj, vis, weights, a, b, k);
            map<pair<long long, long long>, long long> mp;
            if(mp[{a, b}] != 0){
                cout << mp[{a, b}] << " ";
                continue;
            }
            else if(mp[{b, a}] != 0){
                cout << mp[{b, a}] << " ";
                continue;
            }
            long long ans = 1e9+1;
            while(!qu.empty()){
                long long cur = qu.front().first;
                vector<long long> vis = qu.front().second.first;
                vector<long long> weights = qu.front().second.second;
                qu.pop();
                if(vis[cur] == 1) continue;
                vis[cur] = 1;
                if(cur == b){
                    sort(weights.begin(), weights.end());
                    ans = min(ans, weights[weights.size()-k]);
                    // cout << weights[weights.size()-k] << " ";
                    // break;
                    // ans.insert(ans.end(), weights.begin(), weights.end());
                    continue;
                }
                for(auto x: adj[cur]){
                    if(vis[x.first] == 0){
                        weights.push_back(x.second);
                        qu.push({x.first, {vis, weights}});
                        weights.pop_back();
                    }
                }
            }
            
            cout << ans << " ";
            mp[{a, b}] = ans;
            mp[{b, a}] = ans;
        }
        cout << endl;
    }
}