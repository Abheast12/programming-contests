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
        int n, x;
        cin >> n >> x;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        int l = 1, r=n+1;
        set<int>used;
        // set<pair<int, int>>swaps;
        while(r-l>1){
            // cout << l << " " << r << endl;
            int mid = (l+r)/2;
           
            
            
            if(v[mid]<=x){
                l=mid;
            }
            else{
                r = mid;
            }
        }
        if(v[l] == x){
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
            for(int i=1; i<=n; i++){
                if(v[i] == x){
                    cout << i  << " " << l << endl;
                    break;
                }
            }
        }
    }
}