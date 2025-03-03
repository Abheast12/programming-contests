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
using ll = long long;
using namespace std;  
vector<ll> getPath(ll cur, ll en, vector<set<ll>>&adj, vector<ll>&path, vector<ll>&vis){
    path.push_back(cur);
    vis[cur] = 1;
    if(cur==en){
        return path;
    }
    for(auto child: adj[cur]){
        if(vis[child]){
            continue;
        }
        vector<ll>tmp = getPath(child, en, adj, path, vis);
        if(tmp.size()>0){
            return tmp;
        }
    }
    path.pop_back();
    return {};
}
void getComponent(ll cur, vector<set<ll>>&adj, map<ll, ll>&vis, set<ll>&near, vector<ll>&component){
    vis[cur] = 1;
    component.push_back(cur);
    for(auto child: adj[cur]){
        if(vis[child]){
            continue;
        }
        if(near.find(child)!=near.end()){
            continue;
        }
        getComponent(child, adj, vis, near, component);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while(t--){
        ll n, st, en;
        cin >> n >> st >> en;
        vector<set<ll>>adj(n+1);
        for(int i=0; i<n-1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
        }
        vector<ll>dist(n+1, 0);
        queue<pair<ll, ll>>q;
        q.push({st, 0});
        vector<int>vis(n+1, 0);
        while(!q.empty()){
            int x = q.front().first;
            int d = q.front().second;
            q.pop();
            if(vis[x]){
                continue;
            }
            vis[x] = 1;
            dist[x] = d;
            for(auto child: adj[x]){
                q.push({child, d+1});
            }
        }
        vector<ll>path;
        vector<ll>vis2(n+1, 0);
        vector<ll>ans = getPath(st, en, adj, path, vis2);
        vector<ll>actual;
        // for(auto x: ans){
        //     cout << x << " ";
        // }
        for(int i=0; i<ans.size(); i++){
            set<ll>near;
            if(i==0){
                adj[ans[i]].erase(ans[i+1]);
            }
            else if(i==ans.size()-1){
                adj[ans[i]].erase(ans[i-1]);
            }
            else{
                adj[ans[i]].erase(ans[i-1]);
                adj[ans[i]].erase(ans[i+1]);
            }
            map<ll, ll>vis3;
            vector<ll>component;
            getComponent(ans[i], adj, vis3, near,component);
            sort(component.begin(), component.end(), [&](ll a, ll b){
                return dist[a]>dist[b];
            });
            for(auto y: component){
                if(near.find(y)==near.end() && y!=ans[i]){
                    actual.push_back(y);
                }
            }
            actual.push_back(ans[i]);
        }
        for(auto x: actual){
            cout << x << " ";
        }
        cout << endl;

    }
}