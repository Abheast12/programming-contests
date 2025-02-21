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
        int ans =0;
        vector<int>suf(n);
        vector<int>pref(n);
        pref[0] = 0;
        for(int i=0; i<n; i++){
            if(i==0){
                if(v[i ]> 0){
                    pref[i] = v[i];
                }
                else{
                    pref[i] = 0;
                }
            }
            else{
                if(v[i] > 0){
                    pref[i] = pref[i-1] + v[i];
                }
                else{
                    pref[i] = pref[i-1];
                }
            }
        }
        suf[n-1] = 0;
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                if(v[i] < 0){
                    suf[i] = -1*v[i];
                }
                else{
                    suf[i] = 0;
                }
            }
            else{
                if(v[i] < 0){
                    suf[i] = suf[i+1] + -1*v[i];
                }
                else{
                    suf[i] = suf[i+1];
                }
            }
        }
        ans = max(pref[n-1], suf[0]);
        for(int i=0; i<n-1; i++){
            ans = max(ans, pref[i] + suf[i+1]);
        }
        cout << ans << endl;
    }
}