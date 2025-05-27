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

void dfs(int u, vector<int>&ans, vector<set<int>>&adj){
    while(!adj[u].empty()){
        int v = *adj[u].begin();
        adj[v].erase(u);
        adj[u].erase(v);
        dfs(v, ans, adj);
    }
    ans.push_back(u);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // vector<int>v(n);
        map<int, int>p, v;
        // map<int, set<int>>mp;
        // map<int, set<int>>mp2;
        vector<set<int>>mp(2*n+3, set<int>());
        map<pair<int, int>, int>mp2;
        for(int i=1; i<=n; i++){
            int a, b;
            cin >> a >> b;
            if(!p[a]){
                p[a] = 2*i;
            }
            if(!v[b]){
                v[b] = 2*i+1;
            }
            mp[p[a]].insert(v[b]);
            mp[v[b]].insert(p[a]);
            mp2[{p[a], v[b]}] = i;
        }
        int start = 2;
        int ct =0;
        for(int i=2; i<2*n+3; i++){
            if(mp[i].size()%2==1){
                start = i;
                ct++;
            }
        }
        if(ct != 2 && ct != 0){
            cout << "NO" << endl;
            continue;
        }
        vector<int>ans;
        // cout << "here " << start << endl;
        // for(int i=0; i<ans.size(); i++){
        //     cout << ans[i] << " ";
        // }
        // cout << endl;
        dfs(start, ans, mp);
        if(ans.size()!=n+1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int i=ans.size()-1; i>=1; i--){
            int a = ans[i];
            int b = ans[i-1];
            if(a%2==1){
                swap(a, b);
            }
            cout << mp2[{a, b}] << " ";
        }
        cout << endl;

    }
}