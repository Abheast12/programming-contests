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
	static constexpr T unit = 0;
	T f(T a, T b) { 
        return max(a, b);
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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d, r;
    cin >> n >> d >> r;
    vector<int>v(n);
    map<int, int>mp;
    for(int i=0; i<n; i++){
        cin >> v[i];
        mp[v[i]] = i;
    }    
    Tree seg(n);
    vector<int>dp(n+1, 0);
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(i-d > 0){
            seg.update(mp[i-d], dp[i-d]);
        }
        int lb = max(0LL, mp[i]-r);
        int rb = min(n-1LL, mp[i]+r);
        dp[i] = seg.query(lb, rb+1) + 1;
        ans = max(ans, dp[i]);
    }
    // for(int i=1; i<=n; i++){
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << ans-1 << endl;

}