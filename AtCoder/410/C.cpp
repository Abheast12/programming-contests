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
    int n, q;
    cin >> n >> q;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        v[i] = i + 1; 
    }    
    int st = 0;
    for(int i=0; i<q; i++){
        int x;
        cin >> x;
        if(x == 1){
            int p, y;
            cin >> p >> y;
            p--;
            v[(st+p)%n] = y;
        }
        else if(x == 2){
            int p;
            cin >> p;
            p--;
            cout << v[(st+p)%n] << endl;
        }
        else{
            int k;
            cin >> k;
            k%=n;
            st = (st+k) % n;
        }
    }
    
}