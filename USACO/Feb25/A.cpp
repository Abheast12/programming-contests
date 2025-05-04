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
    vector<vector<int>>adj(n+1);
    for(int i=0; i<n; i++){
        cin >> v[i];
        adj[v[i]].push_back(i);
    }
    vector<int>c(n);
    for(int i=0; i<n; i++){
        cin >> c[i];
    }

    
    
}