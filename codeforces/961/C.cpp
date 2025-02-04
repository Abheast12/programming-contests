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
        vector<double>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int ans = 0;
        vector<int>pw(n, 0);
        pw[0] = 0;
        for(int i=1; i<n; i++){
            if(v[i] == 1 && v[i] < v[i-1]){
                ans = -1;
                break;
            }
            else if(v[i] == 1 && v[i-1] == 1){
                pw[i] = 0;
                continue;
            }
            double tmp = log2(v[i-1])/log2(v[i]);
            // cout << tmp << " " << gg << endl;
            int nval = max(0LL, (int)ceil(log2(tmp) + pw[i-1]));
            // cout << i <<  " " << nval << endl;
            pw[i] = nval;
            ans += nval;
        }
        cout << ans << endl;
    }
}