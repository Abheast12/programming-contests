#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<cmath>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<int>dp(n+1);
        dp[0] = 1;
        if(v[1] == 0){
            dp[1] = 1;
        }
        v[0] = 0;
        int mod = 998244353;
        for(int i=2; i<=n; i++){
            if(v[i] == v[i-1]){
                dp[i]+=dp[i-1];
                dp[i]%=mod;
            }
            if(v[i] == v[i-2]+1){
                dp[i]+=dp[i-2];
                dp[i]%=mod;
            }
        }
        int ans = (dp[n]+dp[n-1])%mod;
        cout << ans << endl;
    
    }
}

// int32_t main(){
//     int t;
//     cin >> t;
//     int ct =0 ;
//     while(t--){
//         ct++;
//         int n;
//         cin >> n;
//         vector<int>v(n);
//         for(int i=0; i<n; i++){
//             cin >> v[i];
//         }
//         if(ct == 172){
//             cout << n << "-" << v[0] << "-" << v[1] << "-" << v[2] << "-" << v[3] << "-" << v[4] << endl;
//         }
//         if(n==1){
//             if(v[0] == 0){
//                 cout << 2 << endl;
//             }
//             else{
//                 cout << 1 << endl;
//             }
//             continue;
//         }
//         int ans = 0;
//         int mod = 998244353;
//         if(v[n-1] <= n/2){
//             int cur =0;
//             set<int>liars;
//             map<int, int>bg;
//             map<int, int>ed;
//             for(int i=0; i<n; i++){
                
//                 if(v[i] != cur && v[i] != cur+1){
//                     liars.insert(i);
//                     cur++;
//                 }
//                 else if(v[i]>(i+1)/2){
//                     liars.insert(i);
//                     cur++;
//                 }
//                 else{
//                     cur = v[i];
//                     if(i!=n-1){
//                         if(bg.find(cur) == bg.end()){
//                             bg[cur] = 1e9;
//                         }
//                         if(cur!=0) bg[v[i]] = min(bg[v[i]], i);
//                         else bg[v[i]] = i;
//                         ed[v[i]] = max(ed[v[i]], i);
//                     }
//                 }
                
//             }
            
//             if(liars.find(n-1)==liars.end()){
//                 if(v[n-1] > v[n-2]){
//                     liars.insert(n-2);
//                 }
//                 if(liars.size()<=v[n-1]){
//                 set<int>pos;
//                 for(int i=0; i<=cur; i++){
//                     if(bg.find(i) != bg.end()){
//                         if(bg[i] != n-1){
//                             pos.insert(bg[i]);
//                         }
//                         if(ed[i] != n-1){
//                             pos.insert(ed[i]);
//                         }
//                     }
//                 }
//                 bool fail = false;
//                 for(auto& it: liars){
//                     if(liars.find(it+1) != liars.end()){
//                         fail = true;
//                         break;
//                     }
//                     if(pos.find(it+1) != pos.end()){
//                         pos.erase(it+1);
//                     }
//                     if(pos.find(it-1) != pos.end()){
//                         pos.erase(it-1);
//                     }
//                     if(pos.find(it) != pos.end()){
//                         pos.erase(it);
//                     }
//                 }
//                 int tmp = 1;
//                 for(auto &it: pos){
//                     // cout << it << " ";
//                     if(pos.find(it+1)!=pos.end()){
//                         tmp = (tmp*2LL)%mod;
//                         pos.erase(it+1);
//                     }
//                 }
//                 if(!fail) ans+=tmp;
//                 ans%=mod;
//                 }
//             }
//         }
//         if(v[n-2] <= (n-1)/2){
//             int cur =0;
//             set<int>liars;
//             map<int, int>bg;
//             map<int, int>ed;
//             for(int i=0; i<n-1; i++){
                
//                 if(v[i] != cur && v[i] != cur+1){
//                     liars.insert(i);
//                     cur++;
//                 }
//                 else if(v[i]>(i+1)/2){
//                     liars.insert(i);
//                     cur++;
//                 }
//                 else{
//                     cur = v[i];
//                     if(i!=n-2){
//                         if(bg.find(cur) == bg.end()){
//                             bg[cur] = 1e9;
//                         }
//                         if(cur!=0) bg[v[i]] = min(bg[v[i]], i);
//                         else bg[v[i]] = i;
//                         ed[v[i]] = max(ed[v[i]], i);
//                     }
//                 }
                
//             }
//             // if(liars.size() > v[n-2]){
//             //     continue;
//             // }
//             if(liars.find(n-2)==liars.end()){
//                 if(v[n-2] > v[n-3]){
//                     liars.insert(n-3);
//                 }
//                 if(liars.size() <= v[n-2]){

                
//                 set<int>pos;
//                 for(int i=0; i<=cur; i++){
//                     if(bg.find(i) != bg.end()){
//                         if(bg[i] != n-2){
//                             pos.insert(bg[i]);
//                         }
//                         if(ed[i] != n-2){
//                             pos.insert(ed[i]);
//                         }
//                     }
//                 }
//                 bool fail = false;
//                 for(auto& it: liars){
//                     if(liars.find(it+1) != liars.end()){
//                         fail = true;
//                         break;
//                     }
//                     if(pos.find(it+1) != pos.end()){
//                         pos.erase(it+1);
//                     }
//                     if(pos.find(it-1) != pos.end()){
//                         pos.erase(it-1);
//                     }
//                     if(pos.find(it) != pos.end()){
//                         pos.erase(it);
//                     }
//                 }
//                 int tmp = 1;
//                 for(auto &it: pos){
//                     if(pos.find(it+1)!=pos.end()){
//                         tmp = (tmp*2LL)%mod;
//                         pos.erase(it+1);
//                     }
//                 }
//                 if(!fail) ans+=tmp;
//                 ans%=mod;
//                 }
//             }
//         }
//         cout << ans << endl;
//     }
// }