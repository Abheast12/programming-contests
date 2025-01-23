#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<cmath>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int ans = 0;
        int odd = 0;
        bool tt = false;
        for(int i=0; i<n; i++){
            if(v[i]%2LL==1LL)odd++;
            else tt = true;
        }
        // cout << odd << endl;
        if(tt){
            ans = odd+1;
        }
        else{
            ans = odd-1;
        }
        cout << ans << endl;
    }
}