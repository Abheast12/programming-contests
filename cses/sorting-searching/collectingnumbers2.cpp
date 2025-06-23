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

int contribution(unordered_map<int, int>&mp, int x, int pos, int n){
    int val = 0;
    if(x!=1 && mp[x-1] >= pos){
        val++;
    }
    if(x!=n && mp[x+1] < pos){
        val++;
    }
    return val;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n, m;
    cin >> n >> m;
    vector<int>v(n);
    unordered_map<int, int>mp;
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
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        int x = v[a-1];
        int y = v[b-1];
        int tot =0;
        tot+= contribution(mp, x, a-1, n);
        tot+= contribution(mp, y, b-1, n);
        v[a-1] = y;
        v[b-1] = x;
        mp[x] = b-1;
        mp[y] = a-1;
        int ntot = 0;
        ntot+= contribution(mp, y, a-1, n);
        ntot+= contribution(mp, x, b-1, n);
        ans+= (ntot-tot);
        // cout << "tot: " << tot << " ntot: " << ntot << endl;
        // cout << "x: " << x << " y: " << y << endl;
        if(x-y==1){
            // if(x == n || y == 1){
            //     ans+=1;
            // }
            // else ans+=2;
            ans+= 1;
            // continue;
        }
        else if(y-x==1){
            // if(x == 1 || y == n){
            //     ans-=1;
            // }
            // else ans-=2;
            ans-= 1;
            // continue;
        }
        
        
        // cout << tot << " " << ntot << endl;
        // cout << x << " " << y << endl;
        
        cout << ans << endl;
    }
    
    
}