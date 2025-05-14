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
        int n, m, p, q;
        cin >> n >> m >> p >> q;
        if(n%p ==0){
            if(m!=(n/p)*q){
                cout << "NO" << endl;
                continue;
            }
        }
        cout << "YES" << endl;
        // int val = (n+p-1)/p;
        // if(val*q < m){
        //     cout << "NO" << endl;
        // }
        // else{
        //     cout << "YES" << endl;
        // }
    }
}