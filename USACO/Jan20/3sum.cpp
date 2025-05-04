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
#include<fstream>
#include<chrono>
#include<unordered_map>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define int long long
using namespace std;  

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}



int32_t main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    setIO("threesum");

    int n, q;
    cin >> n >> q;
    // const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
    
    // struct chash {
    //     int random;
    //     chash(int r) : random(r) {}
    //     int operator()(int x) const { return x ^ random; }
    // };
    
    // gp_hash_table<int, int, chash> mp(chash(RANDOM));
    
    vector<int>v(n+1);
    vector<vector<int>>ct(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    for(int i=1; i<=n; i++){
        // map<int, int>mp;
        gp_hash_table<int,int> g({},{},{},{},{1<<13}); 
		// initialize with capacity that is a power of 2
		for (int j = i+1; j<=n; ++j) {
			int res = -v[i]-v[j];
			auto it = g.find(res); 
			if (it != end(g) && j-i+1>2)ct[i][j] = it->second;
			g[v[j]] ++;
		}
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i+j>n) break;
            ct[j][i+j] += (ct[j][i+j-1] + ct[j+1][i+j] - ct[j+1][i+j-1]);
        }
    }
    int l, r;
    for(int i=0; i<q; i++){
        
        cin >> l >> r;
        cout << ct[l][r] << "\n";
    }


}