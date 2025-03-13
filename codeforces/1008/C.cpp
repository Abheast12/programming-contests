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
        vector<int>v(2*n);
        for(int i=0; i<2*n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int tot1 = 0;
        int tot2 = 0;
        for(int i=1; i<n; i++){
            tot1+=v[i];
        }
        for(int i=n; i<2*n; i++){
            tot2+=v[i];
        }
        cout << v[0] << " " << tot2-tot1+v[0] << " ";
        int cur =2*n-1;
        while(cur >= n){
            if(cur == n){
                cout << v[cur] << endl;
                break;
            }
            else{
                cout << v[cur] << " " << v[cur-n] << " ";
            }
            cur--;
        }
        // for(int i=1; i<n; i++){
        //     cout << v[i] << " " << v[n+i] << " ";
        // }
        // cout << endl;
    }
}