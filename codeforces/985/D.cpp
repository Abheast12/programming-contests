#include<iostream>
#include<vector>
#include<map>

using namespace std; 

int main(){
    long long t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        map<pair<long long, long long>, int> edges;
        vector<vector<long long>> adj(n+1);
        for(long long i=0; i<m; i++){
            long long u, v;
            cin >> u >> v;
            edges[{u,v}] = 1;
            edges[{v,u}] = 1;
            if(u<v){
                adj[u].push_back(v);
            }
            else{
                adj[v].push_back(u);
            }
        }
        if(m==0){
            cout << 0 << endl;
            continue;
        }
        vector<pair<pair<long long, long long>, long long>> ans;
        for(int i=1; i<n; i++){
            for(int j=0; j<adj[i].size(); j++){
                if(adj[i][j]!=n){
                    // cout << i << " " << adj[i][j] << " " << n << endl;
                    ans.push_back({{i,adj[i][j]},n});
                    if(edges[{i,n}]!=1){
                        edges[{i,n}] = 1;
                    }
                    else{
                        edges[{i,n}] = 0;
                    }
                    if(edges[{adj[i][j],n}]!=1){
                        edges[{adj[i][j],n}] = 1;
                    }
                    else{
                        edges[{adj[i][j],n}] = 0;
                    }
                }
            }
        }
        long long st  = -1;
        for(int i=1; i<n; i++){
            if(edges[{i,n}]==1){
                st = i;
                break;
            }
        }
        if(st!=-1){
            long long tmp = st;
            for(int i=1; i<n; i++){
                if(i!=st && edges[{i,n}]==0){
                    ans.push_back({{i,n},tmp});
                    tmp = i;
                }
            }
        }
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
        }
    }
}