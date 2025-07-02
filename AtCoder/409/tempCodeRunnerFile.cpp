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
    int n, l;
    cin >> n >> l;
    vector<int>v(n);
    for(int i=0; i<n-1; i++){
        cin >> v[i];
    }
    vector<int>pos(l+1, 0);
    pos[0] = 1;
    int cur = 0;
    for(int i=0; i<n-1; i++){
        cur += v[i];
        cur %= l;
        pos[cur]++;
    }
    int ans = 0;
    for(int i=0; i<l/3; i++){
        ans+= pos[i] * pos[i + l/3] * pos[i + 2*l/3];
    }
    cout << ans << endl;
}