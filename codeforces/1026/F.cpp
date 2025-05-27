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
        vector<int>ans(n);
        set<int>s;
        int mx = 0;
        // int best = 0;
        for(int i=0; i<n; i++){
            if(i == 0){
                ans[i] = 0;
                mx= v[i];
                continue;
            }
            if(v[i] > mx){
                if(v[i] >= 2*mx){
                    mx = v[i];
                    for(int j=0; j<i; j++){
                        ans[i] = max(ans[i], v[j]%mx+mx%v[j]);
                    }
                }
                else{
                    ans[i]= v[i];
                    mx = v[i];
                }
            }
            else{
                ans[i] = max(ans[i-1], v[i]%mx+mx%v[i]);
            }
            // s.insert(v[i]);
            // mx = max(mx, v[i]);
            // if(mx < v[i] ){
            //     if(mx!=0) s.insert(mx);
            //     mx = v[i];
            // }
            // else if(mx != v[i]) s.insert(v[i]);
            // if(i==0) ans[i] = 0;
            // else{
            //     if(s.empty()){
            //         ans[i] = 0;
            //         continue;
            //     }
            //     // s.erase(mx);
            //     int l =1, r = mx;
            //     int tmp=1;
            //     while(l < r){
            //         int mid = (l+r)/2;
            //         int val = mx/(mid+1) + 1;
            //         if(s.lower_bound(val) != s.end()){
            //             tmp = *s.lower_bound(val);
            //             r = mid;
            //         }
            //         else{
            //             l = mid+1;
            //         }
            //     }
            //     ans[i] = tmp+mx%tmp;
            // }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}