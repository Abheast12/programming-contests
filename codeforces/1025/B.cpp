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
int calc(int x, int y){
    int ct =0;
    while(x!=1){
        x = (x+1)/2;
        ct++;
    }
    while(y!=1){
        y = (y+1)/2;
        ct++;
    }
    return ct;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        // int ct =1;
        int ans = min({calc(a, m), calc(b,n), calc((m-b+1),n), calc((n-a+1),m)});
        cout << ans+1 << endl;
        // while(mns!=1){
        //     mns/=2;
        //     ct++;
        // }
        // cout << ct << endl;
    }
}