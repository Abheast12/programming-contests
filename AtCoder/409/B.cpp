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
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }    
    sort(v.begin(), v.end());
    int best = 0;
    for(int i=1; i<=n; i++){
        auto it = lower_bound(v.begin(), v.end(), i);
        if(distance(it, v.end()) >= i){
            best = i;
        }
        else break;
    }
    cout << best << endl;
}