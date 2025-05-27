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
        vector<pair<int, int>>h(n);
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            h[i] = {a, b};
        }
        int r = 0;
        int l = 0;
        bool ok = true;
        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            if(v[i] ==1){
                l+=1;
                r+=1;
            }
            else if(v[i] == -1){
                r+=1;
            }
            if(h[i].first > r || h[i].second < l){
                ok = false;
                break;
            }
            else{
                // l = max(l, h[i].first);
                r = min(r, h[i].second);
                if(h[i].first > l){
                    ans[i] = h[i].first-l;
                    l = h[i].first;
                }
                // ans[i] = {l, r};
            }
        }
        // for(int i=n-1; i>=0; i--){
        //     if(h[i].first > r){
        //         ok = false;
        //         break;
        //     }
        //     if(h[i].second < l){
        //         ok = false;
        //         break;
        //     }


        // }
        if(!ok){
            cout << -1 << endl;
        }
        else{
            vector<int>ans1(n);
            // ans1[n-1] = ans[n-1].second;
            // int cur = ans1[n-1];
            int cur = 0;
            for(int i=n-1; i>=0; i--){
                cur+=ans[i];
                if(v[i] == -1){
                    if(cur > 0){
                        cur--;
                        ans1[i] = 1;
                    }
                    else ans1[i] = 0;
                }
                else{
                    ans1[i] = v[i];
                }
                // if(v[n-1] == 1){
                //     cur--;
                // }
                // else if(v[n-1] == -1 && cur > ans[i-1].)
                
            }
            for(int i=0; i<n; i++){
                cout << ans1[i] << " ";
            }
            cout << endl;
        }
    }
}