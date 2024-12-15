#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n,m;
    cin >> n >> m;
    vector<long long>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    long long dp[5002], update[5002];
    //dp[i][I] = dp[i-1][I] + 1 if T-I > abs(v[i]) and v[i] < 0
    //dp[i][I] = dp[i-1][I-1] 
    for(int i=0; i<5002; i++){
        dp[i] = 0;
        update[i] = 0;
    }
    long long t = 0;
    for(int i=0; i<n; i++){
        if(v[i]>0 && t>=v[i]){
            update[v[i]]++;
            update[t+1]--;
        }
        else if(v[i]<0 && t>=-v[i]){
            update[0]++;
            update[t+v[i]+1]--;
        }
        else if(v[i]==0){
            for(int j=t+1; j>0; j--){
                dp[j] = max(dp[j], dp[j-1]);
            }
            for(int j=0; j<=t+1; j++){
                if(j!=0){
                    update[j]+=update[j-1];
                }
                dp[j]+=update[j];
                update[j-1] = 0;
            }
            update[t] = 0;
            update[t+1] = 0;
            
            // for(int j=0; j<=t; j++){
            //     cout << dp[j] << " ";
            // }
            // cout << endl;
            t++;
        }
    }
    for(int j=t+1; j>0; j--){
        dp[j] = max(dp[j], dp[j-1]);
    }
    for(int j=0; j<=t+1; j++){
        if(j!=0){
            update[j]+=update[j-1];
        }
        dp[j]+=update[j];
        update[j-1] = 0;
    }
    long long ans =0;
    for(int j=0; j<=m; j++){
        // if(j!=0){
        //     dp[j] = max(dp[j], dp[j-1]);
        // }
        // cout << dp[j] << " ";
        ans = max(ans, dp[j]);
    }
    // cout << endl;
    cout << ans << endl;
}