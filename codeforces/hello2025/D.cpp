#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;
#define int long long
struct Tree1 {
	typedef pair<int, pair<int, int>> T;
	static constexpr T unit = {INT_MIN, {INT_MIN, INT_MAX}};
	T f(T a, T b) { 
        int val1 = max({a.first, b.first, b.second.first-a.second.second});
        int val2 = max(a.second.first, b.second.first);
        int val3 = min(a.second.second, b.second.second);
        return {val1, {val2, val3}};
    } // (any associative fn)
	vector<T> s; int n;
	Tree1(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

struct Tree2 {
	typedef pair<int, pair<int, int>> T;
	static constexpr T unit = {INT_MIN, {INT_MIN, INT_MAX}};
	T f(T a, T b) { 
        int val1 = max({a.first, b.first, a.second.first-b.second.second});
        int val2 = max(a.second.first, b.second.first);
        int val3 = min(a.second.second, b.second.second);
        return {val1, {val2, val3}};
    } // (any associative fn)
	vector<T> s; int n;
	Tree2(int n = 0, T def = unit) : s(2*n, def), n(n) {}
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

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        long long n, q;
        cin >> n >> q;
        Tree1 t1(n);
        Tree2 t2(n);
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
            t1.update(i, {0, {v[i]-i, v[i]-i}});
            t2.update(i, {0, {v[i]+i, v[i]+i}});
        }
        long long val1 = t2.query(0, n).first;
        long long val2 = t1.query(0, n).first;
        cout << max(val1, val2) << endl;
        for(int i=0; i<q; i++){
            int x, y;
            cin >> x >> y;
            x--;
            t1.update(x, {0, {y-x, y-x}});
            t2.update(x, {0, {y+x, y+x}});
            val1 = t2.query(0, n).first;
            val2 = t1.query(0, n).first;
            cout << max(val1, val2) << endl;
        }
        
    }
}