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
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        if(n==k){
            // vector<int>v2;
            int ans =-1;
            int ct = 1;
            for(int i=1; i<n; i+=2){
                // cout << i << " " << ct << endl;
                if(v[i] != ct){
                    ans = ct;
                    break;
                }
                ct++;
            }
            if(ans==-1){
                ans = ct;
            }
            cout << ans << endl;
            continue;
        }
        bool tt = false;
        
        for(int i=1; i<n-(k-2); i++){
            if(v[i] > 1){
                tt = true;
                break;
            }
        }
        if(tt){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
}