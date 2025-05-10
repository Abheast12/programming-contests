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

struct Tree {
	typedef pair<int,int> T;
	static constexpr T unit = {1e18, 1e18};
	T f(T a, T b) { 
        if(a.first == b.first) return {a.first, min(a.second, b.second)};
        return min(a, b);
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void generateOrder(vector<vector<pair<int, int>>>&v, vector<pair<int, int>>&order, int node, vector<bool>&visited, int depth){
    visited[node] = true;
    order.push_back({depth, node});
    // cout << node << " " << depth << endl;
    for(auto child:v[node]){
        if(!visited[child.first]){
            generateOrder(v, order, child.first, visited, depth+child.second);
            order.push_back({depth, node});
        }
    }
    
    
}
void runDijkstras(vector<vector<pair<int, int>>>&adj, vector<int>&dist, int start){
    vector<bool>visited(adj.size(), false);
    priority_queue<pair<int, int>>pq;

    pq.push({0, start});
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(visited[x.second]) continue;
        visited[x.second] = true;
        dist[x.second] = -1*x.first;
        for(auto child:adj[x.second]){
            if(!visited[child.first]){
                pq.push({x.first-child.second, child.first});
            }
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n, m;
    cin >> n >> m;

    vector<long long>root(n+1), sz(n+1);
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;

    vector<vector<pair<int, int>>>v(n+1);
    vector<vector<pair<int,int>>>adj(n+1);
    vector<pair<int, pair<int, int>>>edges(m);
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
       
    }
    vector<pair<int, pair<int, int>>>unused;
    sort(edges.begin(), edges.end());
    for(int i=0; i<m; i++){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(find(a, root) != find(b, root)){
            unite(a, b, root, sz);
            // cout << a << " " << b << endl;
            v[a].push_back({b, edges[i].first});
            v[b].push_back({a, edges[i].first});
        }
        else{
            unused.push_back(edges[i]);
            unused.push_back(edges[i]);
        } 
    }

    set<int>s;
    for(auto x : unused){
        s.insert(x.second.first);
        s.insert(x.second.second);
    }
    map<int, vector<int>>dists;
    for(auto x:s){
        vector<int>dist(n+1, INT_MAX);
        runDijkstras(adj, dist, x);
        dists[x] = dist;
    }

    vector<bool>visited(n+1, false);
    vector<pair<int, int>>order;
    generateOrder(v, order, 1, visited, 0);
    map<int, int>mp;
    for(int i=0; i<order.size(); i++){
        // cout << order[i].first << " " << order[i].second << endl;
        if(!mp[order[i].second]) mp[order[i].second] = i;
    }
    // cout << order.size() << endl;
    Tree segtree(order.size()+1);
    for(int i=0; i<order.size(); i++){
        segtree.update(i, {order[i].first, order[i].second});
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        int x = mp[a];
        int y = mp[b];
        if(x > y) swap(x, y);
        auto ans = segtree.query(x, y+1);
        int best = order[x].first+order[y].first-2*ans.first;
        // cout << order[x].first << " " << order[y].first << " " << ans.first << endl;
        for(auto xx:s){
            // cout << xx << " " << dists[xx][a] << " " << dists[xx][b] << endl;
            best = min(best, dists[xx][a]+dists[xx][b]);
        }
        cout << best << endl;
    }


}