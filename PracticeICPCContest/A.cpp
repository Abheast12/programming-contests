#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int>m;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    vector<int> f= v;
    sort(f.begin(), f.end());
    for(int i=0; i<n; i++){
        m[f[i]] = i;
    }
    int mx = -1;
    int ans = 0;

    for(int i=0;i<n; i++){
        mx = max(m[v[i]], mx);
        if(v[i] == f[i] && mx <=i){
            ans++;
        }
    }
    mx = -1;
    int ct = 0;
    cout << ans << " ";
    for(int i=0;i<n; i++){
        mx = max(m[v[i]], mx);
        if(v[i] == f[i] && mx <=i){
            ct++;
            cout << v[i] << " ";
            if(ct==100) break;
        }
    }
    // set<int>s;
    // for(int i=0; i<n; i++){
    //     if(upper_bound(s.begin(), s.end(), v[i]) == s.end()){
    //         f[i] = 1;
    //     }
    //     s.insert(v[i]);
    // }
    // s.clear();
    // int ans = 0;
    // for(int i=n-1; i>=0; i--){
    //     if(s.size() ==0 || lower_bound(s.begin(), s.end(), v[i]) == s.begin()){
    //         if(f[i]==1){
    //             ans++;
    //         }
    //     }
    //     else{
    //         f[i] = 0;
    //     }
    //     s.insert(v[i]);
    // }
    // cout << ans << " ";
    // int ct = 0;
    // for(int i=0; i<n; i++){
    //     if(f[i] == 1){
    //         cout << v[i] << " ";
    //         ct++;
    //     }
    //     if(ct == 100) break;
    // }
}