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

long long maxsz = 1;
int find(int x, vector<long long>&root) {
    while (x != root[x]) {
        if(root[x] != root[root[x]]) root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unite(int a, int b, vector<long long>&root, vector<long long>&sz) {
    int roota = find(a, root);
    int rootb = find(b, root);
    if (sz[roota] < sz[rootb]){
        sz[rootb]+=sz[roota];
        maxsz = max(maxsz, sz[rootb]);
        root[roota] = rootb;
    } else{
        sz[roota] += sz[rootb];
        maxsz = max(maxsz, sz[roota]);
        root[rootb] = roota;
    } 
}

void dfs(string &s1, string &s2, int cur, vector<set<int>>&adj, map<int, int>&vis, multiset<char>&st, multiset<char>&st2){
    vis[cur] = 1;
    // cout << cur << endl;
    st.insert(s1[cur-1]);
    st2.insert(s2[cur-1]);
    for(auto x: adj[cur]){
        if(!vis[x]) dfs(s1, s2, x, adj, vis, st, st2);
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s1, s2;
        // vector<long long>root(n+1), sz(n+1);
        // for (int i = 1; i <= n; i++) root[i] = i;
        // for (int i = 1; i <= n; i++) sz[i] = 1;
        cin >> s1 >> s2;
        vector<set<int>>adj(n+1);
        for(int i=1; i<=n; i++){
            int d1 = i-k;
            int d2 = i-k-1;
            int p1 = i+k;
            int p2 = i+k+1;
            if(d1 >=1 && d1 <= n){
                adj[i].insert(d1);
                adj[d1].insert(i);
            }
            if(d2 >=1 && d2 <= n){
                adj[i].insert(d2);
                adj[d2].insert(i);
            }
            if(p1 >=1 && p1 <= n){
                adj[i].insert(p1);
                adj[p1].insert(i);
            }
            if(p2 >=1 && p2 <= n){
                adj[i].insert(p2);
                adj[p2].insert(i);
            }

            // if(d1 >=1 && d1 <= n){
            //     unite(i, d1, root, sz);
            // }
            // if(d2 >=1 && d2 <= n){
            //     unite(i, d2, root, sz);
            // }
            // if(p1 >=1 && p1 <= n){
            //     unite(i, p1, root, sz);
            // }
            // if(p2 >=1 && p2 <= n){
            //     unite(i, p2, root, sz);
            // }
        }
        map<int, int>vis;
        bool t = true;
        // for(auto x : adj[1]){
        //     cout << x << " ";
        // }
        // cout << endl;
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                multiset<char>st;
                multiset<char>st2;
                dfs(s1, s2, i, adj, vis, st, st2);
                // cout << i << endl;
                
                // for(auto x: st){
                //     cout << x << " ";
                // }
                // cout << endl;
                // for(auto x: st2){
                //     cout << x << " ";
                // }
                if(st != st2){
                    t = false;
                    break;
                }
            }
        }
        if(t){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }
}