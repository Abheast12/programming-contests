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
        set<int>s;
        for(int i=1; i<=n; i++){
            s.insert(i);
        }
        vector<int>pre(n);
        vector<int>suf(n);
        for(int i=0; i<n; i++){
            auto it = s.upper_bound(v[i]);
            if(it == s.begin()){
                if(i!=0){
                    pre[i] = pre[i-1];
                }
                else pre[i] = 0;
            }
            else{
                it--;
                s.erase(it);
                pre[i] = n-s.size();
            }
        }
        s.clear();
        for(int i=1; i<=n; i++){
            s.insert(i);
        }
        for(int i=n-1; i>=0; i--){
            auto it = s.upper_bound(v[i]);
            if(it == s.begin()){
                if(i!=n-1){
                    suf[i] = suf[i+1];
                }
                else suf[i] = 0;
            }
            else{
                it--;
                s.erase(it);
                suf[i] = n-s.size();
            }
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            ans +=min(pre[i], suf[i+1]);
        }
        cout << ans << endl;
    }
}