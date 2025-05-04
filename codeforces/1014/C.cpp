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
        int n;
        cin >> n;
        vector<int>v(n);
        int sume = 0;
        int sumo = 0;
        int mxe = 0;
        int mxo =0;
        int cto =0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i]%2==0){
                sume += v[i];
                mxe = max(mxe, v[i]);
            }
            else{
                sumo += v[i];
                mxo = max(mxo, v[i]);
                cto++;
            }
        }
        if(cto == n){
            cout << mxo << endl;
        }
        else if(cto == 0){
            cout << mxe << endl;
        }
        else{
            cout << sumo+sume-(cto-1) << endl;
        }
        // int val1, val2;
        // if(mxe == 0){
        //     val1 =0;
        // }
        // else{
        //     val1 = mxe+sumo;
        // }
        // if(mxo == 0){
        //     val2 = 0;
        // }
        // else{
        //     val2 = mxo+sume;
        // }
        // int ans = max(val1, val2);
        // cout << ans << endl;

    }
}