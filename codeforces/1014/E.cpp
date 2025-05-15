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
long long binexp(long long bs, long long pw){
    int md = 1e9+7;
    long long res = 1;
    while(pw > 0){
        if(pw%2 == 1){
            res = (res*bs);
            res = (res)%md;
        }
        bs = (bs*bs);
        bs = (bs)%md;
        pw >>= 1;
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int ct = 2*n+2*(m-2)-4;
        // vector<int>v(n);
        int val =0;
        for(int i=0; i<k; i++){
            int a, b, c;
            cin >> a >> b >> c;
            if((a==1 && b==1) || (a==1 && b==m) || (a==n && b==1) || (a==n && b==m)) continue;
            if(a == 1 || b == 1 || a == n || b == m){
                ct--;
                val+=c;
            }
        }
        if(k == n*m){
            if(val%2==1) cout << 0 << endl;
            else cout << 1 << endl;
            continue;
        }
        if(ct == 0){
            if(val%2==1) cout << 0 << endl;
            else cout << binexp(2, n*m-k) << endl;
        }
        else{
            cout << binexp(2, n*m-k-1) << endl;
        }
    }
}