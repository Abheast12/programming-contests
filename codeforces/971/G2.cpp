#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define int long long

int32_t main(){
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
        vector<vector<int>>dp(n+1, vector<int>(20, -1));
        vector<vector<int>>ancestor(n+2, vector<int>(20, n+1));
        stack<int>st;
        map<int, int>par;
        for(int i=n-k+1; i>=1; i--){
            while(!st.empty()){
                if(ans[st.top()] < ans[i]){
                    par[i] = st.top();
                    break;
                }
                st.pop();
            }
            if(!par[i]){
                par[i] = n+1;
            }
            st.push(i);
        }
        for(int i=n-k+1; i>=1; i--){
            for(int j=0; j<20; j++){
                if(j==0){
                    ancestor[i][j] = par[i];
                }
                else{
                    ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
                }
            }
        }
        for(int i=n-k+1; i>=1; i--){
            // int p = par[i];
            for(int j=0; j<19; j++){
                if(j==0){
                    if(par[i] == n+1) break;
                    dp[i][j] = ans[i]*(par[i]-i);
                    
                }
                else{
                    if(ancestor[i][j-1] == n+1) break;
                    dp[i][j] = dp[i][j-1] + dp[ancestor[i][j-1]][j-1];
                }
            }
        }
        for(int i=1; i<=q; i++){
            int l, r;
            cin >> l >> r;
            int a =0;
            int cur = l;
            r-=(k-1);
            // while(true){
                // bool t = true;
            for(int j=19; j>=0; j--){
                if(ancestor[cur][j] <= r){
                    a += dp[cur][j];
                    cur = ancestor[cur][j];
                    // t = false;
                    // break;
                }
            }
                // if(t) break;
            // }
            cout << a +(r-cur+1)*ans[cur] << endl;
        }
    }
    return 0;
}