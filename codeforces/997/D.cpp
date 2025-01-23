#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#define int long long
using namespace std;

int32_t main(){
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
        for(int i=1; i<=10; i++){
            // int md = i;
            // int sm = 0;
            int ct =0;
            map<int, int>mp;
            vector<int>v2(n, 0);
            vector<int>pref(n, 0);
            int sm = 0;
            for(int j=0; j<n; j++){
                if(v[j] <= i){
                    v2[j] = -1;
                }
                else{
                    v2[j] = 1;
                }
                pref[j] = sm;
                sm+=v2[j];
            }
            sm = 0;
            int st =0;
            for(int j=0; j<n; j++){
                if(v[j] == i){
                    while(st <= j){
                        mp[pref[st]]++;
                        st++;
                    }
                }
                sm+=v2[j];
                ans+=mp[sm];
            }
        }
        ans = n*(n+1)/2 - ans;
        cout << ans << endl;
    }
}