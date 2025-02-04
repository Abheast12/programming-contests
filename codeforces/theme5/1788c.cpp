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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << 1 << " " << 2*n << endl;
        for(int i=2; i<=n/2+1; i++){
            cout << i << " " << 2*n-2*(i-1) << endl;
        }
        int tot = 2*n+2;
        int cur = n + 2;
        while(tot<=2*n+1+n/2){
            cout << cur << " " << tot-cur << endl;
            tot++;
            cur+=2;
        }
        // vector<int>v(n);
        
        // for(int i=0; i<n; i++){
        //     cin >> v[i];
        // }
    }
}