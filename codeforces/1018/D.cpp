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
        vector<pair<int, int>>v(n);
        int x = 0;
        int tot =0;
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            v[i] = {a, b};
            x = x^a;
            tot = tot^(a+b);
        }
        tot-=x;
        cout << x << " " << tot << endl;
    }
}