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
	typedef int T;
	static constexpr T unit =0;
	T f(T a, T b) { 
        return a+b;
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] += val; pos /= 2;)
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    set<pair<int, int>>s;
    vector<pair<int, pair<int, int>>>v;
    // vector<int>v(n)
    set<int>vals;
    map<int, pair<int, int>>mp1;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        vals.insert(a);
        vals.insert(b);
        v.push_back({a, {0, i}});
        v.push_back({b, {1, i}});
        // s.insert({a, b});
        mp1[i] = {a, b};
    }
    int q;
    cin >> q;
    // vector<pair<int, pair<int, int>>>qs;
    map<int, pair<int, int>>mp2;
    for(int i=0; i<q; i++){
        int a, b;
        cin >> a >> b;
        vals.insert(a);
        vals.insert(b);
        v.push_back({a, {2, i}});
        v.push_back({b, {3, i}});
        mp2[i] = {a, b};
    }
    map<int, int>mp;
    
    int idx =0;
    for(auto it: vals){
        mp[it] = idx;
        idx++;
    }
    for(int i=0; i<v.size(); i++){
        v[i].first = mp[v[i].first];
    }
    sort(v.begin(), v.end());
    Tree t1(idx+1);
    Tree t2(idx+1);
    vector<int>ans(q);
    for(int i=0; i<v.size(); i++){
        if(v[i].second.first == 0){
            t1.update(v[i].first, 1);
            t2.update(v[i].first, 1);
        }
        else if(v[i].second.first == 1){
            t1.update(mp1[v[i].second.second].first, -1);
            t2.update(mp1[v[i].second.second].first, -1);
        }
    }
    // for(int i=0; i<n; i++){
    //     cin >> v[i];
    // }    
}