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
        vector<int>v(n);
        int ct =0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] == 1){
                ct++;
            }
        }
        if(ct == n){
            cout << "YES" << endl;
            continue;
        }
        bool f = false;
        for(int i=1; i<n; i++){
            if(v[i] == 0 && v[i-1] == 0){
                f = true;
                break;
            }
        }
        if(f){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}