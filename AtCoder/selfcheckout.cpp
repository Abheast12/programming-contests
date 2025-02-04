#include<iostream>
#include<vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(2, 0));
    long long mod = 998244353;
    bool t = true;
    int consec2 =0;
    for(int i=n-1; i>=0; i--){
        if(v[i]==2){
            consec2++;
        }
        else break;
    }
    int consec = 0;
    if(v[n-1]==1){
        dp[n-1][1] = 1;
        t = false;
    }
    else if(v[n-1]==2){
        dp[n-1][0] = 1;
        dp[n-1][1] = 1;
    }
    else if(v[n-1]==3){
        dp[n-1][1] = 2;
        consec=1;
    }
    
    for(int i=n-2; i>=0; i--){
        if(v[i] == 1){
            cout << 0 << endl;
            return 0;
        }
        else if(v[i]==2){
            dp[i][1] = dp[i+1][1] + dp[i+1][0];
            dp[i][0] = dp[i+1][0];
            consec =0;
        }
        else if(v[i] == 3){
            long long tmp = 0;
            if(dp[i+1][0] > 0){
                tmp = n-i-1;
            }
            dp[i][0] = 0;
            dp[i][1] = 2*(dp[i+1][1]+dp[i+1][0]) + tmp;
            if(tmp==0 && consec+consec2==n-i-1){
                dp[i][1] += n-i-1;
            }
            else if(tmp==0 && consec>0){
                dp[i][1]+=consec;
            }
            consec++;
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    long long ans = dp[0][1] + dp[0][0];
    ans %= mod;
    cout << ans << endl;
}