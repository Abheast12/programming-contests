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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, l;
        cin >> n >> m >> l;
        vector<int>a(l);
        int sme = 1e9, smo = 1e18;
        int sm = 0;
        for(int i=0; i<l; i++){
            cin >> a[i];
            sm+= a[i];
            if(a[i]%2==0){
                sme = min(sme, a[i]);
            }
            else{
                smo = min(smo, a[i]);
            }
        }
        if(sm%2==0){
            sme = sm;
            smo = sm-smo;
        }
        else{
            sme = sm-smo;
            smo = sm;
        }
        vector<vector<int>>adj(n+1);
        for(int i=0; i<m; i++){
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<vector<int>>dists(n+1, vector<int>(2, 1e18+1));
        vector<int>vis1(n+1, 0);
        vector<int>vis2(n+1, 0);
        queue<pair<int, int>>q;
        q.push({1, 0});
        dists[1][0] = 0;
        while(!q.empty()){
            int nd = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist%2==0){
                if(vis1[nd]){
                    continue;
                }
                vis1[nd] = 1;
                dists[nd][0] = dist;
            }
            else{
                if(vis2[nd]){
                    continue;
                }
                vis2[nd] = 1;
                dists[nd][1] = dist;
            }
            for(int child: adj[nd]){
                int val = (dist+1)%2;
                if(val==0){
                    if(!vis1[child]){
                        q.push({child, dist+1});
                    }
                }
                else{
                    if(!vis2[child]){
                        q.push({child, dist+1});
                    }
                }
            }
        }
        // cout << sme << " " << smo << endl;
        // for(int i=1; i<=n; i++){
        //     cout << dists[i][0] << " " << dists[i][1] << endl;
        // }
        for(int i=1; i<=n; i++){
            if(dists[i][0] <= sme || dists[i][1] <= smo){
                cout << "1";
            }
            else{
                cout << "0";
            }
        }
        cout << endl;
    }
}