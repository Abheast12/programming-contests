#include<iostream>
using namespace std;
int arr[5050];
int dp[5050];
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=n-1; i>=1; i--){
        for(int j=i-1; j>=0; j--){
            if(arr[i]>arr[j]){
                dp[j] = max(dp[j], dp[i]+1);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]);
    }
    cout << ans + 1 << endl;
}