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
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int val = abs(v[0]);
        for(int i=0; i<n; i++){
            v[i] = abs(v[i]);
        }
        sort(v.begin(), v.end());
        int idx = -1;
        for(int i=0; i<n; i++){
            if(v[i] == val){
                idx = i;
                if (i <= n/2){
                    cout << "YES" << endl;
                    break;
                }
                else{
                    cout << "NO" << endl;
                    break;
                }
            }

        }
    }
}