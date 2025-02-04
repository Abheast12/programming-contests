#include<iostream>
#include<vector>
#include<climits>
#define int long long
using namespace std;


struct Tree {
	typedef pair<pair<int, int>, pair<int, int>> T;
	static constexpr T unit = {{INT_MIN, INT_MIN}, {INT_MIN, INT_MIN}};
	T f(T a, T b) { 
        int val =0;
        int val1 = max(max(a.first.second+b.first.first, a.second.first), b.second.first);
        int val2 = a.second.second+b.second.second;
        int val3 = max(b.first.second, b.second.second+a.first.second);
        int val4 = max(a.first.first, a.second.second+b.first.first);
        return {{val4, val3}, {val1, val2}};
        // if(a.first.second != b.first.first-1){
        //     val = query(a.first.second+1, b.first.first-1).second.second;
        // }
        // if(a.second.first+b.second.first+val >= a.second.first && a.second.first+b.second.first+val >= b.second.first){
        //     return {{a.first.first, b.first.second}, {a.second.first+b.second.first+val, a.second.second+b.second.second}};
        // }
        // else if(a.second.first >= b.second.first){
        //     return {{a.first.first, a.first.second}, {a.second.first, a.second.second+b.second.second}};
        // }
        // else return {{b.first.first, b.first.second}, {b.second.first, a.second.second+b.second.second}};
        
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
    // T getbeg(){
    //     return s[1];
    // }
    // void print(){
    //     for(T el: s){
    //         cout << el << " ";
    //     }
    // }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    // vector<int>v(n);
    Tree t(n);
    for(int i=0; i<n; i++){
        // cin >> v[i];
        int x;
        cin >> x;
        t.update(i, {{x, x}, {x,x}});
    }
    // cout << "here" << endl;
    for(int i=0; i<m; i++){
        int k, x;
        cin >> k >> x;
        k--;
        t.update(k, {{x, x}, {x, x}});
        cout << max(0LL, t.query(0, n).second.first) << endl;
    }
}