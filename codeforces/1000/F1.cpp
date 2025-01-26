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
#include<iterator>
#define int long long
using namespace std;  

int helper(int left, int right, int &ans) {

    // If no more left and right parentheses
    // are remaining, a valid combination is found
    if (left == 0 && right == 0) {
        ans++;
        return ans;
    }

    // If more right parentheses than left,
    // return (invalid state)
    if (left > right) {
        return 0;
    }

    // Try adding a left parenthesis if available
    if (left > 0) {
        helper(left - 1, right, ans);
    }

    // Try adding a right parenthesis 
      // if available
    if (right > 0) {
        helper(left, right - 1, ans);
    }

    return ans;
}

// Function to count valid parentheses
// arrangements of length n
int findWays(int n) {

    // If n is odd, no valid arrangements possible
    if (n % 2 == 1)
        return 0;
    int ans = 0;
    return helper(n / 2, n / 2, ans);
}

void solve(int n, int i, set<pair<int, int>>&s){
    vector<int>vals(n+1, 0);
    map<int, int>seen;
    
    int a, b;
    cin >> a >> b;
    // cerr << a << " " << b << endl;
    s.insert({a, i});
    s.insert({b, i});
    vals[0]+=s.begin()->first-1LL;
    vals[0]+=2*n-s.rbegin()->first;
    for(auto it = s.begin(); it!=s.end(); it++){
        if(seen[it->second]){
            auto it2 = prev(it);
            if(it2->second != it->second) vals[it->second] += it->first-it2->first-1;
        }
        else{
            auto it2 = next(it);
            vals[it->second] += it2->first-it->first-1;
            seen[it->second] = 1;
        }
    }
    int ans = 1;
    int mod = 998244353;
    for(int i=0; i<=n; i++){
        if(vals[i] != 0){
            cout << i << " " << vals[i] << " ";
        }
        // if(vals[i]%2==1){
        //     while(true){}
        // }
        if(vals[i]!=0 && vals[i]%2==0) ans*=findWays(vals[i]);
        ans%=mod;
    }
    cout << ans << " ";
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << findWays(2*n) << " ";
        // cerr << n << endl;
        set<pair<int, int>>s;
        for(int i=1; i<=n; i++){
            solve(n, i, s);
        }
        cout << endl;
    }
}