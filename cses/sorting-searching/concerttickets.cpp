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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n, m;
    cin >> n >> m;
    // vector<int>v(n);
    multiset<int>v;
    vector<int>v2(m);
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.insert(a);
    }
    for(int i=0; i<m; i++){
        // cin >> v2[i];
        int a;
        cin >> a;
        auto it = v.upper_bound(a);
        
        if(it == v.begin()){
            cout << -1 << endl;
        } else {
            it--;
            cout << *it << endl;
            v.erase(it);
        }
    }


    
}