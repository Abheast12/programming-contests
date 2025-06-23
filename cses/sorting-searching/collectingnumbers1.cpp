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
   
    int n;
    cin >> n;
    vector<int>v(n);
    map<int, int>mp;
    for(int i=0; i<n; i++){
        cin >> v[i];
        mp[v[i]] = i;
    }
    int cur = -1;
    int ans = 1;
    for(int i=1; i<=n; i++){
        if(mp[i] < cur){
            ans++;
            
        }
        cur = mp[i];
    }
    cout << ans << endl;
    
}