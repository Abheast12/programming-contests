#include<iostream>
#include<vector>

using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<vector<int>>dp(n+1, vector<int>(3, 0));    
        for(int i=1; i<=n; i++){
            int dif = 0;
            if(v[i] > dp[i-1][0]){
                dif = 1;
            }
            else if(v[i] < dp[i-1][0]){
                dif = -1;
            }
            dp[i][0] = dp[i-1][0] + dif;
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
            int dif2 =0, dif3 =0;
            if(v[i] > dp[i-1][2]){
                dif2 = 1;
            }
            else if(v[i] < dp[i-1][2]){
                dif2 = -1;
            }
            if(v[i] > dp[i-1][1]){
                dif3 = 1;
            }
            else if(v[i] < dp[i-1][1]){
                dif3 = -1;
            }
            if(i>=2)dp[i][2] = max(dp[i-1][2]+dif2, dp[i-1][1]+dif3);
        }
        cout << max(dp[n][2], dp[n][1]) << endl;
    }
}