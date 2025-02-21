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

int find_best(int b, int y, int c){
    int l =b, r = 1 << 30;
    int ans = 0;
    while(l < r){
        int mid = (l+r)/2;
        // cout << mid << " " << y << " " << c << endl;
        if((mid^y) >= c){
            r= mid;
            ans = mid;
        }
        else{
            l = mid+1;
        }
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int>v(n);
        vector<int>v2(q);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=0; i<q; i++){
            cin >> v2[i];
        }

        vector<vector<int>>dp(n+1, vector<int>(32, -1));
        for(int j=30; j>=0; j--){
            int x = 1 << j;
            for(int i=0; i<n; i++){
                if(v[i] >= x){
                    dp[i][j] = i;
                }
                else{
                    if(i>0){
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        for(int j=30; j>=0; j--){
            dp[n][j] = n-1;
        }
        // for(int j=0; j<=4; j++){
        //     for(int i=0; i<n; i++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int>xors(n+1);
        xors[n] = 0;
        for(int i=n-1; i>=0; i--){
            xors[i] = xors[i+1]^v[i];
        }
        for(int i=0; i<q; i++){
            int x = v2[i];
            int ans = 0;
            int cur = n-1;
            while(x!=0 && cur >= 0){
                // cout << x << " " << cur << endl;
                if(v[cur] <= x){
                    x=x^v[cur];
                    if(x == 0){
                        ans = n-cur;
                        break;
                    }
                    int val = (int)log2(x);
                    if(dp[cur][val] == -1){
                        ans = n;
                        break;
                    }
                    cur--;
                    if(cur<0){
                        ans = n;
                        break;
                    }
                    // int y = ;
                    // cout << y << endl;
                    // y = y^xors[cur];
                    // cout << y << endl;
                    if(dp[cur][val] != cur)x = x^xors[dp[cur][val]+1]^xors[cur+1];
                    // cout << x << endl;
                    ans = n-dp[cur][val]-1;
                    cur = dp[cur][val];
                }
                else{
                    ans = n-cur-1;
                    break;
                }
                // int val = (int)log2(x);
                // cout << x << " " << val << " " << cur << endl;
                // if(dp[cur][val] == -1){
                //     ans = n;
                //     break;
                // }
                // int y = x^xors[dp[cur][val]+1];
                // y = y^xors[cur];
                // cout << y << endl;
                // if(v[dp[cur][val]]<= y){
                //     x = x^xors[dp[cur][val]]^xors[cur];
                //     ans = n-dp[cur][val];
                //     cur = dp[cur][val]-1;
                // }
                // else{
                //     ans = n-dp[cur][val]-1;
                //     break;
                // }
            }
            cout << ans << " ";
        }
        cout << endl;
        




        // int prev_bound = 0;
        // int xors = 0;
        // set<pair<int, int>>s;
        // for(int i=n-1; i>=0; i--){
        //     if(i==n-1){
        //         prev_bound = v[i];
        //         s.insert({v[i], 1LL});
        //         xors = v[i];
        //     }
        //     else{
        //         int bt = find_best(prev_bound, xors, v[i]);
        //         // cout << bt << endl;
        //         prev_bound = max(prev_bound, bt);
        //         s.insert({prev_bound, n-i});
        //         xors = xors^v[i];
        //         // int nb = xors^v[i];
        //         // prev_bound = max(prev_bound, nb);
        //         // s.insert({prev_bound, n-i});
        //         // xors = xors^v[i];
        //     }
        // }
        // // for(auto it : s){
        // //     cout << it.first << " " << it.second << endl;
        // // }
        // // cout << "here" << endl;
        // for(int i=0; i<q; i++){
        //     auto it = lower_bound(s.begin(), s.end(), make_pair(v2[i], (long long)1e7));
        //     if(it == s.begin()){
        //         cout << 0 << " ";
        //     }
        //     else{
        //         it--;
        //         cout << it->second << " ";
        //     }
        // }
        // cout << endl;
        
    }
}