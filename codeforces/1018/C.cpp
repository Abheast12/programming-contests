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
        int n;
        cin >> n;
        vector<vector<int>>v(n+1, vector<int>(n+1, 1e18));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int a;
                cin >> a;
                v[i][j] =a;
            }
        }
        

        vector<int>row(n+1), col(n+1);
        for(int i=1; i<=n; i++){
            cin >> row[i];
        }
        for(int i=1; i<=n; i++){
            cin >> col[i];
        }

        vector<set<int>>sr(n+1);
        vector<set<int>>sc(n+1);
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int d = v[i][j]-v[i][j-1];
                if(abs(d) <=1){
                    sc[j].insert(d);
                }
                d = v[i][j]-v[i-1][j];
                if(abs(d) <=1){
                    sr[i].insert(d);
                }
            }
        }
        vector<vector<int>>dpr(n+1, vector<int>(2, 1e18));
        vector<vector<int>>dpc(n+1, vector<int>(2, 1e18));
        dpr[1][0] = 0;
        dpr[1][1] = row[1];
        for(int i=2; i<=n; i++){
            // if(sr[i].size() == 3) break;
            // cout << i << endl;
            // for(auto it : sr[i]){
            //     cout << it << " ";
            // }
            // cout << endl;
            set<pair<int, int>>s2;
            s2.insert({0, 0});
            s2.insert({1, 0});
            s2.insert({0, 1});
            s2.insert({1, 1});
            if(sr[i].find(-1) != sr[i].end()){
                s2.erase({0, 1});
            }
            if(sr[i].find(1) != sr[i].end()){
                s2.erase({1, 0});
            }
            if(sr[i].find(0) != sr[i].end()){
                s2.erase({0, 0});
                s2.erase({1, 1});
            }
            
            if(s2.size() == 0) break;
            for(auto it : s2){
                // cout << i << " " << it.first << " " << it.second << endl;
                int a = it.first;
                int b = it.second;
                if(a == 0 && b == 0){
                    dpr[i][0] = min(dpr[i][0], dpr[i-1][0]);
                }
                else if(a == 1 && b == 0){
                    dpr[i][0] = min(dpr[i][0], dpr[i-1][1]);
                }
                else if(a == 0 && b == 1){
                    dpr[i][1] = min(dpr[i][1], dpr[i-1][0]+row[i]);
                }
                else if(a == 1 && b == 1){
                    dpr[i][1] = min(dpr[i][1], dpr[i-1][1]+row[i]);
                }
            }
        }

        dpc[1][0] = 0;
        dpc[1][1] = col[1];
        for(int i=2; i<=n; i++){
            set<pair<int, int>>s2;
            s2.insert({0, 0});
            s2.insert({1, 0});
            s2.insert({0, 1});
            s2.insert({1, 1});
            if(sc[i].find(-1) != sc[i].end()){
                s2.erase({0, 1});
            }
            if(sc[i].find(1) != sc[i].end()){
                s2.erase({1, 0});
            }
            if(sc[i].find(0) != sc[i].end()){
                s2.erase({0, 0});
                s2.erase({1, 1});
            }
            if(s2.size() == 0) break;
            for(auto it : s2){
                int a = it.first;
                int b = it.second;
                if(a == 0 && b == 0){
                    dpc[i][0] = min(dpc[i][0], dpc[i-1][0]);
                }
                else if(a == 1 && b == 0){
                    dpc[i][0] = min(dpc[i][0], dpc[i-1][1]);
                }
                else if(a == 0 && b == 1){
                    dpc[i][1] = min(dpc[i][1], dpc[i-1][0]+col[i]);
                }
                else if(a == 1 && b == 1){
                    dpc[i][1] = min(dpc[i][1], dpc[i-1][1]+col[i]);
                }
            }
        }
        // for(int i=1; i<=n; i++){
        //     cout << dpr[i][0] << " " << dpr[i][1] << endl;
        //     // cout << dpc[i][0] << " " << dpc[i][1] << endl;
        // }
        // for(int i=1; i<=n; i++){
        //     // cout << dpr[i][0] << " " << dpr[i][1] << endl;
        //     cout << dpc[i][0] << " " << dpc[i][1] << endl;
        // }
        // if(dpc[n][0] == 1e18 || dpr[n][0] == 1e18 || dpc[n][1] == 1e18 || dpr[n][1] == 1e18){
        //     cout << -1 << endl;
        //     continue;
        // }
        int v1 = min(dpr[n][0], dpr[n][1]);
        int v2 = min(dpc[n][0], dpc[n][1]);
        if(v1 == 1e18 || v2 == 1e18){
            cout << -1 << endl;
            continue;
        }
        // int ans = min(dpr[n][0], dpr[n][1]) + min(dpc[n][0], dpc[n][1]);
        // cout << ans << endl;
        cout << v1 + v2 << endl;

    //     vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(4, 1e18)));
    //     // 1 -> row, 2-> col
    //     dp[1][1][0] = 0;
    //     dp[1][1][1] = row[1];
    //     dp[1][1][2] = col[1];
    //     dp[1][1][3] = row[1] + col[1];
    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=n; j++){
    //             if(i==1 && j==1)continue;
    //             for(int k=0; k<4; k++){
    //                 if(k==0){
    //                     if(v[i][j] != v[i-1][j]) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
    //                     if(v[i][j] != v[i][j-1]) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
    //                     if(v[i][j] != v[i-1][j]+1) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][1]);
    //                     if(v[i][j] != v[i][j-1]+1) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][2]);
    //                     if(v[i][j] != v[i-1][j]+2) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][3]);
    //                     if(v[i][j] != v[i][j-1]+2) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][3]);    
    //                 }
    //                 else if(k==1){
    //                     if(v[i][j] != v[i-1][j]) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
    //                     if(v[i][j]+1 != v[i][j-1]) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
    //                     if(v[i][j] != v[i-1][j]+1) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][0]);
    //                     if(v[i][j] != v[i][j-1]+1) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][3]);
    //                 }
    //                 else if(k==2){
    //                     if(v[i][j] != v[i-1][j]) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]);
    //                     if(v[i][j] != v[i][j-1]) dp[i][j][k] = min(dp[i][j][k], dp[i][j-1][k]);
    //                     if(v[i][j] != v[i-1][j]+2) dp[i][j][k] = min(dp[i][j][k], dp[i-1][j+1]);
    //                 }
    //             }
    //         }
    //     }
    }
}