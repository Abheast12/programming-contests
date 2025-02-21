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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>v(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        map<int, int>mp;
       
        vector<pair<int, int>>v2;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mp[v[i][j]] == 2){
                    continue;
                }
                if(i<n-1 && v[i][j] == v[i+1][j]){
                    mp[v[i][j]] = 2;
                }
                else if(j<m-1 && v[i][j] == v[i][j+1]){
                    mp[v[i][j]] = 2;
                }
                else{
                    mp[v[i][j]] = 1;
                }
            }
        }
        
        for(auto it: mp){
            // cout << it.first << " " << it.second << endl;
            v2.push_back({it.second, it.first});
        }
        int ans = 0;
        if(v2.size() == 0){
            cout << 0 << endl;
            continue;
        }
        sort(v2.begin(), v2.end());
        
        for(int i=0; i<v2.size()-1; i++){
            ans+=v2[i].first;
        }
        cout << ans << endl;
    }
}