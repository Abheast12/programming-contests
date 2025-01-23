#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<char>>v(n, vector<char>(m));
        char c[5] = {'n', 'a', 'r', 'e', 'k'};
        set<char>s;
        s.insert('n');
        s.insert('a');
        s.insert('r');
        s.insert('e');
        s.insert('k');
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        vector<vector<int>>dp(n, vector<int>(5, -1e6-2));
        
        int idx =0;
        int tot = 0;
        int tot2 =0;
        vector<int>tmp(5, 0);
        for(int j=0; j<m; j++){
            if(v[0][j] == c[idx]){
                tot++;
                tmp[idx] = tot;
                idx++;
                idx%=5;
            }
            if(s.find(v[0][j]) != s.end()){
                tot2++;
            }
        }
        for(int i=0; i<5; i++){
            if(tmp[i] > 0) dp[0][i] = 2*tmp[i] - tot2;
        }
        dp[0][4] = max(0, dp[0][4]);
        for(int i=1; i<n; i++){
            
            for(int k=0; k<5; k++){
                if(k!=4 && dp[i-1][k] == -1e6-2){
                    continue;
                }
                tmp = vector<int>(5, 0);
                idx =(k+1)%5;
                tot = 0;
                tot2 =0;
                for(int j=0; j<m; j++){
                    if(v[i][j] == c[idx]){
                        tot++;
                        tmp[idx] = max(tmp[idx], tot);
                        idx++;
                        idx%=5;
                    }
                    if(s.find(v[i][j]) != s.end()){
                        tot2++;
                    }
                }
                for(int j=0; j<5; j++){
                    dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    if(tmp[j] >0) dp[i][j] = max(dp[i][j], dp[i-1][k] +  2*tmp[j] - tot2);
                    
                }
            } 
        }
        int ans = 0;
        for(int i=0; i<5; i++){
            ans = max(ans, dp[n-1][i] - (((i+1)%5) * 2));
        }
        cout << ans << endl;
        
    }
}