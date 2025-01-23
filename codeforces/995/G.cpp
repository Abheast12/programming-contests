#include<iostream>
#include<vector>

// #define int long long

using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<pair<int, char>>queries(q);
    for(int i=0; i<q; i++){
        int x;
        char c;
        cin >> x;
        cin >> c;
        queries[i] = {x, c};
    }
    // cout << "here1" << endl;
    vector<vector<int>>lt(n+1, vector<int>(n+1, 0));
    vector<int>ln(n+1, 1);
    for(int i=1; i<=n; i++){
        for(int j=0; j<q; j++){
            if(queries[j].first == i){
                if(queries[j].second == '+'){
                    ln[i]++;
                }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int k=1; k<=n; k++){
            if(i==k) continue;
            int begi = 1;
            int endi = 1;
            int begk = 1;
            int endk = 1;
            int st = 2;
            for(int j=0; j<q; j++){
                if(queries[j].first == i){
                    if(queries[j].second == '+'){
                        endi++;
                        st = max(endi+1-(begk-1), st);
                    }
                    else{
                        begi++;
                    }
                }
                if(queries[j].first == k){
                    if(queries[j].second == '+'){
                        endk++;
                    }
                    else{
                        begk++;
                    }
                }
            }
            lt[i][k] = st;
        }
        // int beg = 1;
        // int ed = 1;
        // // cout << beg << " " << ed << endl;
        // for(int j=0; j<q; j++){
        //     if(queries[j].first != i){
        //         continue;
        //     }
        //     if(queries[j].second == '+'){
        //         ed++;
        //     }
        //     else{
        //         beg++;
        //     }
        // }
        // lt[i] = ed;
    }
    // cout << "here" << endl;
    // cout << lt[3][1] << " " << lt[2][3] << " " << lt[2][1] << endl; 
    vector<vector<int>>dp(n+1, vector<int>(1<<n, 1e9));
    dp[0][0] = 0;
    for(int j=1; j<(1<<n); j++){
        for(int i=1; i<=n; i++){
            if((j&(1<<(i-1))) == 0) continue;
            if(j == (1<<(i-1))){
                dp[i][j] = 1;
                continue;
            }
            for(int k=1; k<=n; k++){
                if((j&(1<<(k-1))) == 0) continue;
                if(i==k) continue;
                dp[i][j] = min(dp[i][j], dp[k][j^(1<<(i-1))]+lt[k][i]-1);
            }
        }
    }
    int ans = 1e9;
    for(int i=1; i<=n; i++){
        ans = min(ans, dp[i][(1<<n)-1]+ln[i]-1);
    }
    cout << ans << endl;
}