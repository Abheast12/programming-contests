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
    int n, k;
    cin >> n >> k;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        v[i]*=(n-i);
    }
    sort(v.begin(), v.end());
    int val = 0;
    int ans =0 ;
    for(int i=0; i<n; i++){
        if(val+v[i] < k){
            val+=v[i];
            ans++;
        }
        else break;
    }
    cout << ans << endl;


}