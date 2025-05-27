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

int solve(int a, int k){
    queue<pair<int, int>>q;
    q.push({a, 0});
    while(!q.empty()){
        int x = q.front().first;
        int ct = q.front().second;
        q.pop();
        if(x == 1){
            return ct;
        }
        for(int i=min(x, k); i>=2; i--){
            if(x%i == 0){
                q.push({x/i, ct+1});
            }
        }
    }
    return -1;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x,y, k;
        cin >> x >> y >> k;
        int val = gcd(x, y);
        x/= val;
        y/= val;
        if(x==y){
            cout << 0 << endl;
            continue;
        }
        int valx = solve(x, k);
        int valy = solve(y, k);
        if(valx == -1 || valy == -1){
            cout << -1 << endl;
            continue;
        }
        cout << valx + valy << endl;
        // int ct =0;
        // bool ok = true;
        // while(x!=1 && ok){
        //     ok = false;
        //     for(int i=k; i>=2; i--){
        //         if(x%i != 0){
        //             continue;
        //         }
        //         x/=i;
        //         ok = true;
        //         ct++;
        //         break;
        //     }
        // }
        // if(!ok){
        //     cout << -1 << endl;
        //     continue;
        // }
        // while(y!=1 && ok){
        //     ok = false;
        //     for(int i=k; i>=2; i--){
        //         if(y%i != 0){
        //             continue;
        //         }
        //         y/=i;
        //         ok = true;
        //         ct++;
        //         break;
        //     }
        // }
        // if(!ok){
        //     cout << -1 << endl;
        //     continue;
        // }
        // cout << ct << endl;
    }
}