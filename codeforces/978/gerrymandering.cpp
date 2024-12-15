#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<vector<char>>grid(2, vector<char>(n+1, 'X'));
        for(int i=0; i<2; i++){
            for(int j=1; j<=n; j++){
                cin >> grid[i][j];
            }
        }
        vector<vector<long long>>dp(n+1, vector<long long>(3, 0));
        for(int i=0; i<=n; i++){
            for(int j=0; j<3; j++){
                if(j==0){
                    int ct =0;
                    int ad=0;
                    if(i+3<=n){
                        if(grid[0][i+1]=='A')ct++;
                        if(grid[0][i+2]=='A')ct++;
                        if(grid[0][i+3]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        ct=0;
                        if(grid[1][i+1]=='A')ct++;
                        if(grid[1][i+2]=='A')ct++;
                        if(grid[1][i+3]=='A')ct++;
                        if(ct>=2){
                            ad++;
                        }
                        dp[i+3][0] = max(dp[i+3][0], dp[i][j]+ad);
                    }
                    
                    if(i+2<=n){
                        ct=0; ad=0;
                        if(grid[0][i+1]=='A')ct++;
                        if(grid[1][i+1]=='A')ct++;
                        if(grid[1][i+2]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        dp[i+1][2] = max(dp[i+1][2], dp[i][j]+ad);
                        // cout << dp[i+1][2] << " " << i+1  << " " << dp[i][j]+ad << endl;
                        ct=0; ad=0;
                        if(grid[1][i+1]=='A')ct++;
                        if(grid[0][i+1]=='A')ct++;
                        if(grid[0][i+2]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        dp[i+1][1] = max(dp[i+1][1], dp[i][j]+ad);
                    }
                }
                else if(j==1){
                    int ct=0, ad=0;
                    if(i+4<=n){
                        if(grid[0][i+2]=='A')ct++;
                        if(grid[0][i+3]=='A')ct++;
                        if(grid[0][i+4]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        ct=0;
                        if(grid[1][i+1]=='A')ct++;
                        if(grid[1][i+2]=='A')ct++;
                        if(grid[1][i+3]=='A')ct++;
                        if(ct>=2){
                            ad++;
                        }
                        dp[i+3][1] = max(dp[i+3][1], dp[i][j]+ad);
                    }
                    if(i+2<=n){
                        ct=0;ad=0;
                        if(grid[1][i+1]=='A')ct++;
                        if(grid[1][i+2]=='A')ct++;
                        if(grid[0][i+2]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        dp[i+2][0] = max(dp[i+2][0], dp[i][j]+ad);
                    }
                }
                else if(j==2){
                    int ct=0, ad=0;
                    if(i+4<=n){
                        if(grid[1][i+2]=='A')ct++;
                        if(grid[1][i+3]=='A')ct++;
                        if(grid[1][i+4]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        ct = 0;
                        if(grid[0][i+1]=='A')ct++;
                        if(grid[0][i+2]=='A')ct++;
                        if(grid[0][i+3]=='A')ct++;
                        if(ct>=2){
                            ad++;
                        }
                        dp[i+3][2] = max(dp[i+3][2], dp[i][j]+ad);
                    }
                    if(i+2<=n){
                        ct=0;ad=0;
                        if(grid[0][i+1]=='A')ct++;
                        if(grid[0][i+2]=='A')ct++;
                        if(grid[1][i+2]=='A')ct++;
                        if(ct>=2){
                            ad = 1;
                        }
                        dp[i+2][0] = max(dp[i+2][0], dp[i][j]+ad);
                    }
                }
            }
        }
        // for(int i=0; i<=n; i++){
        //     for(int j=0; j<3; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        cout << dp[n][0] << endl;
        // for(int j=0; j<n; j++){
        //     if(j == 2){
        //         int ct =0;
        //         if(grid[0][0]=='A')ct++;
        //         if(grid[0][1]=='A')ct++;
        //         if(grid[0][2]=='A')ct++;
        //         if(ct>=2){
        //             dp[0][2] = 1;
        //         }
        //     }
        //     else if(j>2){
        //         int ct =0;
        //         for(int i=j; i>=j-2; i--){
        //             if(grid[0][i]=='A')ct++;
        //         }
        //         if(ct>=2){
        //             dp[0][j] = dp[0][j-3]+1;
        //         }
        //     }
        // }
        // for(int j=0;j<n; j++){
        //     if(j>=1){
        //         int ct =0;
        //         if(grid[1][j]=='A')ct++;
        //         if(grid[0][j]=='A')ct++;
        //         if(grid[0][j-1]=='A')ct++;

        //     }
        // }
    }
}