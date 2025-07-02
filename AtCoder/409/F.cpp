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

// dsu implementation
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

// void recalculateDists(vector<vector<pair<int, int>>>&dists, vector<pair<int, int>>&v, int n, vector<bool>&recalculate, vector<long long>&root, vector<long long>&sz) {
//     for(int i=1; i<=n; i++){
//         if(recalculate[i]){
//             dists[i].clear();
//             for(int j=1; j<=n; j++){
//                 if(find(i, root) != find(j, root)){
//                     int dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
//                     if(dists[i].size() > 0){
//                         if(dists[i][0].first > dist){
//                             dists[i].clear();
//                             dists[i].push_back({dist, j});
//                         }
//                         else if(dists[i][0].first == dist){
//                             dists[i].push_back({dist, j});
//                         }
//                     }
//                     else{
//                         dists[i].push_back({dist, j});
//                     }
//                 }
//             }
//             recalculate[i] = false;
//         }
//     }
// }

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>>v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i].first >> v[i].second;
    }    
    vector<long long>root(n+1), sz(n+1);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    vector<vector<pair<int, int>>>dists(n+1);

    priority_queue<pair<int, pair<int, int>>>pq;
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            pq.push({-(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)), {i, j}});
        }
    }
    for(int i=0; i<q; i++){
        int a;
        cin >> a;
        if(a==3){
            int x, y;
            cin >> x >> y;
            int rootx = find(x, root);
            int rooty = find(y, root);
            if(rootx != rooty){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
        }
        else if(a==1){
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
            n++;
            root.push_back(n);
            sz.push_back(1);
            for(int j=1; j<n; j++){
                pq.push({-(abs(v[n].first - v[j].first) + abs(v[n].second - v[j].second)), {j, n}});
            }
        }
        else{
            bool flag = false;
            int prev =-1;
            while(!pq.empty()){
                pair<int, pair<int, int>>p = pq.top();
                pq.pop();
                int dist = -p.first;
                int u = p.second.first;
                int v = p.second.second;
                if(find(u, root) != find(v, root)){
                    if(!flag){
                        unite(u, v, root, sz);
                        cout << dist << endl;
                        flag = true;
                        prev = dist;
                    }
                    else{
                        if(prev == dist){
                            unite(u, v, root, sz);
                        }
                        else{
                            pq.push(p);
                            break;
                        }
                    }
                }
            }
            if(!flag){
                cout << -1 << endl;
            }
        }
    }


    // for(int i=1; i<=n; i++){
    //     for(int j=i+1; j<=n; j++){
    //         int dist = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
    //         if(dists[i].size() > 0){
    //             if(dists[i][0].first > dist){
    //                 dists[i].clear();
    //                 dists[i].push_back({dist, j});
    //             }
    //             else if(dists[i][0].first == dist){
    //                 dists[i].push_back({dist, j});
    //             }
    //         }
    //         else{
    //             dists[i].push_back({dist, j});
    //         }
    //         if(dists[j].size() > 0){
    //             if(dists[j][0].first > dist){
    //                 dists[j].clear();
    //                 dists[j].push_back({dist, i});
    //             }
    //             else if(dists[j][0].first == dist){
    //                 dists[j].push_back({dist, i});
    //             }
    //         }
    //         else{
    //             dists[j].push_back({dist, i});
    //         }   
    //     }
    // }
    // vector<bool>recalculate(n+1, false);
    // for(int i=0; i<q; i++){
    //     int a;
    //     cin >> a;
    //     if(a == 3){
    //         int x, y;
    //         cin >> x >> y;
    //         int rootx = find(x, root);
    //         int rooty = find(y, root);
    //         if(rootx != rooty){
    //             cout << "No" << endl;
    //         }
    //         else{
    //             cout << "Yes" << endl;
    //         }
    //     }
    //     else if(a == 1){
    //         int x, y;
    //         cin >> x >> y;
    //         v.push_back({x, y});
    //         n++;
    //         root.push_back(n);
    //         sz.push_back(1);
    //         vector<pair<int, int>>newdists;
    //         for(int j=1; j<n; j++){
    //             int dist = abs(v[n].first - v[j].first) + abs(v[n].second - v[j].second);
    //             if(dists[j].size() > 0){
    //                 if(dists[j][0].first > dist){
    //                     dists[j].clear();
    //                     dists[j].push_back({dist, n});
    //                 }
    //                 else if(dists[j][0].first == dist){
    //                     dists[j].push_back({dist, n});
    //                 }
    //             }
    //             else{
    //                 dists[j].push_back({dist, n});
    //             }
    //             if(newdists.size() > 0){
    //                 if(newdists[0].first > dist){
    //                     newdists.clear();
    //                     newdists.push_back({dist, j});
    //                 }
    //                 else if(newdists[0].first == dist){
    //                     newdists.push_back({dist, j});
    //                 }
    //             }
    //             else{
    //                 newdists.push_back({dist, j});
    //             }
    //         }
    //         dists.push_back(newdists);
    //         recalculate.push_back(false);

    //     }
    //     else{
    //         recalculateDists(dists, v, n, recalculate, root, sz);
    //         int mndist = 1e18;
    //         for(int i=1; i<=n; i++){
    //             if(dists[i].size() > 0 && dists[i][0].first < mndist){
    //                 mndist = dists[i][0].first;
    //             }
    //         }
    //         set<int>changed;
    //         for(int i=1; i<=n; i++){
    //             if(dists[i].size() > 0 && dists[i][0].first == mndist){
    //                 for(pair<int, int>p : dists[i]){
    //                     if(find(i, root) != find(p.second, root)){
    //                         changed.insert(find(i, root));
    //                         changed.insert(find(p.second, root));
    //                         unite(i, p.second, root, sz);
    //                     }
    //                 }
    //             }   
    //         }
    //         for(int i=1; i<=n; i++){
    //             if(changed.find(find(i, root)) != changed.end()){
    //                 recalculate[i] = true;
    //             }
    //         }
    //         if(mndist == 1e18){
    //             cout << -1 << endl;
    //         }
    //         else{
    //             cout << mndist << endl;
    //         }
    //     }
    // }
}