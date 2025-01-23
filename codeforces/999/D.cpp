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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int>v(n);
        vector<int>v2(m);
        multiset<int>s;
        priority_queue<int>pq;
        for(int i=0; i<n; i++){
            cin >> v[i];
            s.insert(v[i]);
        }
        for(int i=0; i<m; i++){
            cin >> v2[i];
            pq.push(-1*v2[i]);
        }
        int ct = 0;
        bool gg = true;
        while(!pq.empty() && !s.empty()){
            
            int val = -1*pq.top();
            // cout << val << endl;
            pq.pop();
            
            if(s.find(val)==s.end() && val == 1){
                gg = false;
                break;
            }
            else if(s.find(val) != s.end()){
                s.erase(s.find(val));
                continue;
            }
            
            int d1 = val/2;
            int d2 = val - d1;
            if(d1 < *s.begin()){
                gg = false;
                break;
            }
            pq.push(-1*d1);
            pq.push(-1*d2);
            // if(s.find(d1) != s.end()){
            //     s.erase(s.find(d1));
            // }
            // else{
            //     pq.push(-1*d1);
            // }
            // if(s.find(d2)!=s.end()){
            //     s.erase(s.find(d2));
            // }
            // else{
            //     pq.push(-1*d2);
            // }
        }
        if(gg && s.empty() && pq.empty()){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }
}

// int32_t main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int tt;
//     cin >> tt;
//     while(tt--){
//         int n, m;
//         cin >> n >> m;
//         vector<int>v(n);
//         vector<int>v2(m);
//         // map<int, int>mp;
//         priority_queue<int>pq;
//         for(int i=0; i<n; i++){
//             cin >> v[i];
            
//             // mp[v[i]]++;
//         }
//         bool t = true;
//         for(int i=0; i<m; i++){
//             cin >> v2[i];
//         }
//         for(int i=0; i<n; i++){
//             pq.push(-1*v[i]);
//         }
//         sort(v2.begin(), v2.end());
//         int cur = 0;
//         while(cur<m && !pq.empty()){
//             int val = -1*pq.top();
//             pq.pop();
//             if(val == v2[cur]){
//                 cur++;
//             }
//             else{
//                 if(pq.empty()){
//                     break;
//                 }
//                 int val2 = -1*pq.top();
//                 pq.pop();
//                 if(val2 - val <=1){
//                     pq.push(-1*(val+val2));
//                 }
//                 else{
//                     t = false;
//                     break;
//                 }
//             }
//         }
//         if(cur == m && pq.empty() && t){
//             cout << "YES" << endl;
//         }
//         else{
//             cout << "NO" << endl;
//         }



//         // for(int i=0; i<m; i++){
//         //     if(v2[i]%2==0){
//         //         if(mp[v2[i]/2]>=2){
//         //             mp[v2[i]/2]-=2;
//         //         }
//         //         else{
//         //             t = false;
//         //             break;
//         //         }
//         //     }
//         //     else{
//         //         int val = v2[i]/2;
//         //         if(mp[val]>=1 && mp[val+1]>=1){
//         //             mp[val]--;
//         //             mp[val+1]--;
//         //         }
//         //         else{
//         //             t = false;
//         //             break;
//         //         }
//         //     }
//         // }
//         // if(!t){
//         //     cout << "NO" << endl;
//         // }
//         // else{
//         //     for(int i=0; i<n; i++){
//         //         if(mp[v[i]]>0){
//         //             t = false;
//         //             break;
//         //         }
//         //     }
//         //     if(t){
//         //         cout << "YES" << endl;
//         //     }
//         //     else{
//         //         cout << "NO" << endl;
//         //     }
//         // }

//     }
// }