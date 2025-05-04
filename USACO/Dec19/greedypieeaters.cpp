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
#include<fstream>
#define int long long
using namespace std;  

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int32_t main(){
    setIO("pieaters");
    
    int n, m;
    cin >> n >> m;
    // vector<pair<pair<int, int>, int>>v(m);
    vector<vector<vector<int>>>mx(n+1, vector<vector<int>>(n+1, vector<int>(n+1, 0)));
    // vector<int>mxs(n+1, 0);
    for(int i=0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        // v[i] = {{y, z}, x};
        // mx[x][y][z] = max(mx[x][y][z], x);
        for(int j=y; j<=z; j++){
            // mxs[j] = max(mxs[j], x);
            mx[j][y][z] = max(mx[j][y][z], x);
        }
    }
    // cout << "hi" << endl;
    for(int i=1; i<=n; i++){
        for(int j=i; j>=1; j--){
            for(int k=i; k<=n; k++){
                // cout << i << " " << j << " " << k << endl;
                if(k<n){
                    mx[i][j][k+1] = max(mx[i][j][k], mx[i][j][k+1]);
                }
                if(j>1){
                    mx[i][j-1][k] = max(mx[i][j-1][k], mx[i][j][k]);
                }
                // if(j>1 && k<n){
                //     mx[i][j-1][k+1] = max(mx[i][j-1][k+1], mx[i][j][k]);
                // }
            }
        }
    }
    // cout << "hi" << endl;
    vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j+i-1>n) continue;
            for(int k=j+1; k<=j+i-1; k++){
                dp[j][j+i-1] = max(dp[j][j+i-1], dp[j][k-1] + dp[k][j+i-1]);
            }
            for(int k=j; k<=j+i-1; k++){
                int val  =0;
                if(k!=j){
                    val += dp[j][k-1];
                }
                if(k!= j+i-1){
                    val += dp[k+1][j+i-1];
                }
                dp[j][j+i-1] = max(dp[j][j+i-1], mx[k][j][j+i-1] + val);
            }
        }
    }
    cout << dp[1][n] << endl;

    // sort(v.begin(), v.end());
    // map<int, vector<pair<int, int>>>mp;
    // int ct = 0;
    // for(int i=1;i<=n; i++){
    //     while(ct < m && v[ct].first.first == i){
    //         mp[v[ct].first.first].push_back({v[ct].second, v[ct].first.second});
    //         ct++;
    //     }
    // }
    // priority_queue<pair<int, int>>pq;
    // vector<int>maxs(n+1, 0);
    // for(int i=1; i<=n; i++){
    //     for(auto it: mp[i]){
    //         pq.push({it});
    //     }
    //     while(!pq.empty()){
    //         auto it = pq.top();
    //         if(it.second < i){
    //             pq.pop();
    //         }
    //         else{
    //             break;
    //         }
    //     }
    //     if(!pq.empty()){
    //         maxs[i] = pq.top().first;
    //     }
    //     else{
    //         maxs[i] = 0;
    //     }
    // }

}