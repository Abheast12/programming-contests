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

template <class T> class BIT {
    private:
      int size;
      vector<T> bit;
      vector<T> arr;
  
    public:
      BIT(int size) : size(size), bit(size + 1), arr(size) {}
  
      void set(int ind, T val) { add(ind, val - arr[ind]); }
  
      void add(int ind, T val) {
          arr[ind] += val;
          ind++;
          for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
      }
  
      T pref_sum(int ind) {
          ind++;
          T total = 0;
          for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
          return total;
      }
};

void generateOrder(vector<vector<pair<int, int>>>&v, vector<pair<int, int>>&order, vector<pair<int, int>>&order2, int node, vector<bool>&visited, int depth, int depth2, vector<int>&sz){
    visited[node] = true;
    order.push_back({depth, node});
    order2.push_back({depth2, node});
    // cout << node << " " << depth << endl;
    sz[node] = 1;
    for(auto child:v[node]){
        if(!visited[child.first]){
            generateOrder(v, order, order2, child.first, visited, child.second, depth2+1, sz);
            // order.push_back({depth, node});
            sz[node] += sz[child.first];
            order2.push_back({depth2, node});
        }
    }
    
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin >> n;

    // vector<vector<pair<int, int>>>v(n+1);
    vector<vector<pair<int,int>>>adj(n+1);
    vector<pair<int, pair<int, int>>>edges(n+1);
    for(int i=0; i<n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
       
    }

    vector<bool>visited(n+1, false);
    vector<pair<int, int>>order;
    vector<pair<int, int>>order2;
    vector<int>sz(n+1);
    generateOrder(adj, order, order2, 1, visited, 0, 0, sz);
    // generateOrder(adj, order, 1, visited, 0);
    map<int, int>mp;
    // for(int i=0; i<order.size(); i++){
    //     // cout << order[i].first << " " << order[i].second << endl;
    //     mp[order[i].second] = i;
    // }
    // for(auto it: mp[2]){
    //     cout << it << " ";
    // }
    // cout << endl;
    // cout << order.size() << endl;
    Tree segtree(order2.size()+1);
    map<int, int>mp2;
    for(int i=0; i<order2.size(); i++){
        if(!mp2[order2[i].second]) mp2[order2[i].second] = i;
        segtree.update(i, {order2[i].first, order2[i].second});
    }

    // FenwickTree fenwick(order.size()+1);
    // for(int i=0; i<order.size(); i++){
    //     fenwick.add(i+1, order[i].first);
    //     mp[order[i].second] = i+1;
    // }
    BIT<int> fenwick(order.size()+2);
    for(int i=0; i<order.size(); i++){
        fenwick.add(i, order[i].first);
        fenwick.add(i+sz[order[i].second], -order[i].first);
        mp[order[i].second] = i;
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int p, a, b;
        cin >> p >> a >> b;
        if(p == 2){
            // cout << "here" << endl;
            // cout << a << " " << b << endl;
            int x = mp[a];
            int y = mp[b];
            
            // cout << x << " " << y << endl;
            if(x > y) swap(x, y);

            int x2 = mp2[a];
            int y2 = mp2[b];
            if(x2 > y2) swap(x2, y2);
            
            auto ans = segtree.query(x2, y2+1);
            
            int best = fenwick.pref_sum(x)+fenwick.pref_sum(y)-2*fenwick.pref_sum(mp[ans.second]);
            cout << best << endl;
        }
        else{
            
            int x = mp[edges[a-1].second.first];
            int y= mp[edges[a-1].second.second];
            int val;
            if(x > y){
                val = edges[a-1].second.first;
            }
            else{
                val = edges[a-1].second.second;
            }
            fenwick.add(mp[val], b-edges[a-1].first);
            fenwick.add(mp[val]+sz[val], edges[a-1].first-b);
            edges[a-1].first = b;
            // if(order[v1[0]].first > order[v2[0]].first) swap(v1, v2);
            // // order[v2[0]].first = b+order[x].first;

            // // segtree.update(y, order[y]);
            // cout << b+order[v1[0]].first << endl;   
            // for(int j=0; j<v2.size(); j++){
            //     cout << v2[j] << " " << order[v2[j]].first << endl;
            //     order[v2[j]].first = b+order[v1[0]].first;
            //     segtree.update(v2[j], order[v2[j]]);
            // }

        }
    }


}