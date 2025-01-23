#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>>dp(n+1, vector<int>(k+1, 1e9));
        dp[0][0] = 0;
        vector<pair<int, int>>v(n);
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            // if (a > b){
            //     swap(a, b);
            // }
            v[i] = {a, b};
        }
        // sort(v.begin(), v.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++){
                if(dp[i][j] == 1e9) continue;
                int ct = 0;
                int a = v[i].first;
                int b = v[i].second;
                int tot =0;
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
                while(true){
                    if(a==1 && b==1){
                        ct+=1;
                        tot+=1;
                        dp[i+1][min(k, j+tot)] = min({dp[i+1][min(k, j+tot)], dp[i][min(k, j+tot)], dp[i][j]+ct});
                        tot+=1;
                        dp[i+1][min(k, j+tot)] = min({dp[i+1][min(k, j+tot)], dp[i][min(k, j+tot)], dp[i][j]+ct});
                        break;
                    }
                    if(a > b){
                        swap(a, b);
                    }
                    ct+=a;
                    b--;
                    tot++;
                    dp[i+1][min(k, j+tot)] = min({dp[i+1][min(k, j+tot)], dp[i][min(k, j+tot)], dp[i][j]+ct});
                }
            }
        }
        // int op = 0;
        // int tot =0;
        // for(int i=0; i<n; i++){
        //     if(v[i].first+v[i].second+tot >k){
        //         int a = v[i].first;
        //         int b = v[i].second;
        //         while(tot<k){
        //             if(a == 1 && b == 1){
        //                 op+=1;
        //                 tot+=2;
        //                 break;
        //             }
        //             if(a > b){
        //                 swap(a, b);
        //             }
        //             op+=a;
        //             b--;
        //             tot++;
        //         }
        //         break;
        //     }
        //     else{
        //         op+=(v[i].first*v[i].second);
        //         tot+=(v[i].first+v[i].second);
        //     }
        // }
        // if(tot >= k){
        //     cout << op << endl;
        // }
        // else{
        //     cout << -1 << endl;
        // }
        // for(int i=0; i<=n ;i++){
        //     for(int j=0; j<=k; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        if(dp[n][k] == 1e9){
            cout << -1 << endl;
        }
        else cout << dp[n][k] << endl;
    }
}