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
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        vector<set<int>>adj1(n+1);
        vector<set<int>>adj2(n+1);
        int m1, m2;
        cin >> m1;
        for(int i=0; i<m1; i++){
            int x, y;
            cin >> x >> y;
            adj1[x].insert(y);
            adj1[y].insert(x);
        }
        cin >> m2;
        for(int i=0; i<m2; i++){
            int x, y;
            cin >> x >> y;
            adj2[x].insert(y);
            adj2[y].insert(x);
        }
        // vector<pair<int, int>>pairs;
        map<pair<int, int>, int>pairs;
        for(int i=1; i<=n-1; i++){
            for(int j=i+1; j<=n; j++){
                if(adj1[i].find(j)!=adj1[i].end() && adj2[i].find(j)!=adj2[i].end()){
                    pairs[{i, j}] = 1;
                    pairs[{j, i}] = 1;
                }
            }
        }
        // vector<vector<int>>dist1(n+1, vector<int>(2, 1e9));
        // vector<vector<int>>dist2(n+1, vector<int>(2, 1e9));
        priority_queue<pair<int, pair<int, int>>>pq;
        map<pair<int, int>, int>vis1;
        map<pair<int, int>, int>dist;
        pq.push({0, {s1, s2}});
        bool tt = false;
        while(!pq.empty()){
            int cur1 = pq.top().second.first;
            int d = -pq.top().first;
            int cur2 = pq.top().second.second;
            // cout << cur1 << " " << cur2 << endl; 
            // if(pairs[{cur1, cur2}] == 1){
                
            //     cout << d << endl;
            //     tt = true;
            //     break;
            // }
            pq.pop();
            if(vis1[{cur1, cur2}] == 1){
                continue;
            }
            vis1[{cur1, cur2}]=1;
            dist[{cur1, cur2}] = d;
            for(auto x:adj1[cur1]){
                for(auto y:adj2[cur2]){
                    if(cur1 == cur2 && x == y){
                        cout << d << endl;
                        tt = true;
                        break;
                    }
                    if(vis1[{x, y}] == 0){
                        pq.push({-(d+abs(x-y)), {x, y}});
                    }
                }
                if(tt){
                    break;
                }
            }
            if(tt){
                break;
            }
        }
        if(!tt){
            cout << -1 << endl;
        }
    }
}