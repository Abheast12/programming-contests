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
        vector<int>ans(n);
        int mx =0;

        for(int i=0; i<n; i++){
            cin >> v[i];
            mx = max(mx, v[i]);
        }
        bool flag = false;
        for(int i=1; i<n; i++){
            if(v[i] != v[i-1]){
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "No" << endl;
        }
        else{
            for(int i=0; i<n; i++){
                if(v[i] == mx){
                    ans[i] = 1;
                }
                else{
                    ans[i] = 2;
                }
            }
            cout << "Yes" << endl;
            for(int i=0; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}