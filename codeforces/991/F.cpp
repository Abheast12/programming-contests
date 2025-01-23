#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
using namespace std;
#define int long long
struct Tree1 {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { 
        // if(a == -1) return b;
        // if(b == -1) return a;
        // cout << a << " " << b << endl;
        return gcd(a, b);
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
    void output(){
        for(int i=0; i<2*n; i++){
            cout << s[i] << " ";
        }
        cout << endl;
    }
};


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, q;
        cin >> n >> q;
        Tree1 t1(n-1);
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(i>0){
                // cout << i << " " << abs(v[i]-v[i-1]) << endl;
                t1.update(i-1, abs(v[i]-v[i-1]));
            }
        }
        // t1.output();
        map<int, int> mp;
        int prev = -1;
        for(int i=n-1; i>=0; i--){
            if(prev!=-1){
                if(v[i] == v[prev]){
                    mp[i] = prev;
                }
                else{
                    mp[i] = i;
                    prev = i;
                }
            }
            else{
                prev = i;
                mp[i] = i;
            }
        }
        for(int i=0; i<q; i++){
            int x, y;
            cin >> x >> y;
            if(x == y) cout << "0 ";
            else{
                x--;
                y--;
                if(mp[x] >= y){
                    // cout << "here" << endl;
                    cout << "0 ";
                }
                else{
                    // y--;
                    // cout << x << " " << y << endl;
                    int ans = t1.query(x, y);
                    cout << ans << " ";
                }
            }  
        }
        cout << endl;
        
    }
}