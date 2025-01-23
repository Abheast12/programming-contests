#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        int n, k, q;
        cin >> n >> k >> q;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<int>ans(n+1);
        set<pair<int, int>>s;
        map<int, int>m;
        for(int i=1; i<=k; i++){
            m[v[i]-i]++;
        }
        for(auto x : m){
            s.insert({x.second, x.first});
        }
        ans[1] = k-s.rbegin()->first;
        for(int i=k+1; i<=n; i++){
            int val = v[i-k]-i+k;
            auto it = s.find({m[val], val});
            s.erase(it);
            m[val]--;
            if(m[val] > 0){
                s.insert({m[val], val});
            }
            if(m[v[i]-i] == 0){
                m[v[i]-i]++;
                s.insert({1, v[i]-i});
            }
            else{
                it = s.find({m[v[i]-i], v[i]-i});
                s.erase(it);
                m[v[i]-i]++;
                s.insert({m[v[i]-i], v[i]-i});
            }
            ans[i-k+1] = k-s.rbegin()->first;
        }
        for(int i=1; i<=q; i++){
            int l, r;
            cin >> l >> r;
            cout << ans[l] << endl;
        }
    }
    return 0;
}