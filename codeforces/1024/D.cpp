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
        return a+b;
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        vector<int>vo;
        vector<int>ve;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(i%2 == 0){
                ve.push_back(v[i]);
            }
            else{
                vo.push_back(v[i]);
            }
        }
        map<int, int>m1;
        map<int, int>m2;
        sort(ve.begin(), ve.end());
        sort(vo.begin(), vo.end());
        for(int i=0; i<ve.size(); i++){
            m1[ve[i]] = i;
        }
        for(int i=0; i<vo.size(); i++){
            m2[vo[i]] = i;
        }
        int inve=0, invo=0;
        Tree t1(ve.size()+1);
        Tree t2(vo.size()+1);
        // cout << "HI" << endl;
        for(int i=0; i<n; i+=2){
            t1.update(m1[v[i]], 1);
            inve+=t1.query(0, ve.size()) - t1.query(0, m1[v[i]]+1);
        }
        for(int i=1; i<n; i+=2){
            t2.update(m2[v[i]], 1);
            invo+=t2.query(0, vo.size()) - t2.query(0, m2[v[i]]+1);
        }
        // cout << "here" << endl; 
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                ans.push_back(ve[i/2]);
            }
            else{
                ans.push_back(vo[i/2]);
            }
        }
        // cout << inve << " " << invo << endl;
        if(inve%2 != invo%2){
            swap(ans[n-3], ans[n-1]);
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        // if(invo%2 == inve%2){
        //     cout << ve[ve.size() - 2] << " " << vo[vo.size()-1] << " " << ve[ve.size()-1] << endl;
        // }
        // else{
        //     cout << ve[ve.size() - 1] << " " << vo[vo.size()-1] << " " << ve[ve.size()-2] << endl;
        // }
    }
}