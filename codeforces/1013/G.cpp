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
        int n, k;
        cin >> n >> k;
        if(n >= k*k){
            if(n%k == 0){
                cout << k << endl;
            }
            else cout << max(1LL, k-2) << endl;
        }
        else{
            priority_queue<pair<pair<int, int>,pair<int, int>>>pq;
            map<tuple<int, int, int, int>, int>mp;
            pq.push({{k, 0}, {1, 0}});
            while(!pq.empty()){
                int p = pq.top().first.first;
                int q = pq.top().first.second;
                int r = pq.top().second.first;
                int s = pq.top().second.second;
                // cout << p << " " << q << " " << r << " " << s << endl;
                pq.pop();
                if(q == n){
                    cout << p << endl;
                    break;
                }
                if(mp.find({p, q, r, s}) != mp.end()) continue;
                mp[{p, q, r, s}] = 1;
                int val = q + p*r;
                if(val >=0 && val <=n){
                    pq.push({{p, val}, {r, 0}});
                }
                if(s != 1){
                    pq.push({{max(1LL, p-1), q}, {-1*r, 1}});
                }
            }
        }
    }

}