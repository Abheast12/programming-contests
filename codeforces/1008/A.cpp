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
        int tot = 0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            tot+=v[i];
        }
        if(tot%n ==0 && tot/n == k){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}