#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;
long long mn = INT_MAX;
long long dp[100100];
void dfs(int pos, vector<int>&v1, long long cur, long long curr){
    // cout << pos << endl;
    if(pos == v1.size()){
        if(curr!=0) mn = min(mn, cur+dp[curr]);
        else mn = min(mn, cur);
        return;
    }
    if(pos+1 < v1.size() && v1[pos+1] == 0){
        dfs(pos+1, v1, cur, curr*10+v1[pos]);
    }
    else{
        dfs(pos+1, v1, cur, curr*10+v1[pos]);
        dfs(pos+1, v1, cur+dp[curr*10+v1[pos]], 0);
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    for(int i=0; i<100100; i++){
        dp[i] = INT_MAX;
    }
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        // cout << i << endl;
        long long minf = INT_MAX;
        dp[i] = min(dp[i-1]+1, dp[i]);
        for(int j=2; j*j <= i; j++){
            if(i%j==0){
                minf = min(minf, dp[j]+dp[i/j]);
            }
        }
        dp[i] = min(minf, dp[i]);
        int ii = i;
        vector<int>v1;
        while(ii !=0){
            v1.push_back(ii%10);
            ii/=10;
        }
        reverse(v1.begin(), v1.end());
        // int pow = 1;
        // int a = 0;
        // for(int j=v1.size()-1; j>=1; j--){
        //     a+=v1[j]*pow;
        //     pow*=10;
        //     int pow2 = 1;
        //     int b = 0;
        //     for(int jj = j-1; jj>=0; jj--){
        //         b+=v1[jj]*pow2;
        //         pow2*=10;
        //     }
        //     // cout << a << " " << b << endl;
        //     dp[i] = min(dp[i], dp[a]+dp[b]);
        // }
        
        if(!v1.empty()){
            // cout << "here" <<endl;
            dfs(0, v1, 0LL, 0LL);
            dp[i] = min(dp[i], mn);
            mn = INT_MAX;
            v1.clear();
        }
        if(i<8000){
            for(int j=1;j<i;j++){
                dp[i] = min(dp[i],dp[j]+dp[i-j]);
            }
        }
        // cout << i << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;
}