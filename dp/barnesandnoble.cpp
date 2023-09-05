#include<iostream>
using namespace std;
int dp[100100];
int prices[1010];
int pages[1010];
int main(){
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> prices[i];
    }
    for(int i=0; i<n; i++){
        cin >> pages[i];
    }
    int ans = 0;
    for(int i=x; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i-prices[j]>=0){
                dp[i-prices[j]] = max(dp[i-prices[j]], dp[i]+pages[j]);
            }
        }
    }
    for(int i=0; i<=x; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}