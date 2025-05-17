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
        vector<string>v(n);
        // vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        map<int, int>mp;
        int mx =0;
        for(int i=0; i<m; i++){
            int ct =0;
            for(int j=0; j<n; j++){
                string s;
                cin >> s;
                if(s==v[j]){
                    mp[j]++;
                    ct++;
                }
            }
            mx = max(mx, ct);
        }
        bool f = false;
        for(int i=0; i<n; i++){
            if(!mp[i]){
                f = true;
                break;
            }
        }
        if(f){
            cout << -1 << endl;
        }
        else{
            cout << n + 2*(n-mx) << endl;
        }
    }
}