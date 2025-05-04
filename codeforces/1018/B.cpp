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
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        vector<int>l(n);
        vector<int>r(n);
        for(int i=0; i<n; i++){
            cin >> l[i];
        }
        for(int i=0; i<n; i++){
            cin >> r[i];
        }
        int tot =0;
        for(int i=0; i<n; i++){
            int a = l[i];
            int b = r[i];
            // cin >> a >> b;
            tot+=max(a, b);
            v[i] = min(a, b);
        }
        sort(v.begin(), v.end());
        for(int i=n-1; i>n-k; i--){
            tot+=v[i];
        }
        tot++;
        cout << tot << endl;
    }
}