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
    int k;
    cin >> k;
    // cout << k << endl;
    // for(int i=0; i<n; i++){
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    int ct =0;
    for(int i=0; i<n; i++){
        if(k <= v[i]){
            ct++;
        }
    }
    cout << ct << endl;
}