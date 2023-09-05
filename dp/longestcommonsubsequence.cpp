#include<iostream>
#include<map>
using namespace std;
int arr[5050];
int dp[5050];
int main(){
    map<int, int>m1;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        m1[a] = i;
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        cin >> arr[i];
        if(m1.count(arr[i])){
            dp[i]++;
            ans = 1;
        }
    }
    
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(m1.count(arr[j]) && m1.count(arr[i])){
                if(m1[arr[j]]> m1[arr[i]]){
                    dp[j] = max(dp[j], dp[i]+1);
                    ans = max(dp[j], ans);
                }
            }
        }
    }
    cout << ans << endl;
}