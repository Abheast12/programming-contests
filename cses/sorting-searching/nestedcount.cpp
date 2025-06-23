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
#include<unordered_map>
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
   
    int n;
    cin >> n;
    
    // map<int, pair<int, int>> m;
    vector<pair<pair<int, int>, int>> v;
    set<int> coords;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        v.push_back({{x, y}, i});
        coords.insert(x);
        coords.insert(y);
    }
    int ct =0;
    unordered_map<int, int> coord_map;
    for(auto x: coords) {
        coord_map[x] = ct++;
    }
    for(int i=0; i<n; i++){
        v[i].first.first = coord_map[v[i].first.first];
        v[i].first.second = coord_map[v[i].first.second];
    }
    
    sort(v.begin(), v.end(), [](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if(a.first.first == b.first.first) return a.first.second > b.first.second;
        return a.first.first < b.first.first;
    });
    Tree seg(coords.size()+1);
    Tree seg2(coords.size()+1);

    vector<int>ans1(n, 0);
    vector<int>ans2(n, 0);
    int mxr = 0;
    for(int i=0; i<n; i++){
        // if(v[i].first.second <= mxr){
        //     ans1[v[i].second] = 1;
        // }
        // mxr = max(mxr, v[i].first.second);
        ans1[v[i].second] = seg.query(v[i].first.second, coords.size()+1);
        seg.update(v[i].first.second, 1);
    }
    int mnr = 1e18;
    for(int i=n-1; i>=0; i--){
        // if(v[i].first.second >= mnr){
        //     ans2[v[i].second] = 1;
        // }
        // mnr = min(mnr, v[i].first.second);
        ans2[v[i].second] = seg2.query(0, v[i].first.second+1);
        seg2.update(v[i].first.second, 1);
    }
    for(int i=0; i<n; i++){
        cout << ans2[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++){
        cout << ans1[i] << " ";
    }
    cout << endl;

    
}