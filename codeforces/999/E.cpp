#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;  

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int>v(n);
        vector<int>b(m);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
        }
        vector<vector<int>>dp(m+1);
        for(int i=0; i<(1<<m); i++){
            int val = (1LL<<31)-1;
            int ct =0;
            for(int j=0; j<m; j++){
                if(i&(1<<j)){
                    val = val&b[j];
                    ct++;
                }
            }
            dp[ct].push_back(val);
        }
        // for(int i=0; i<=m; i++){
        //     for(int j=0; j<dp[i].size(); j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<vector<int>>dp2(n, vector<int>(m+1, (1LL<<31)-1));
        vector<int>difs;
        int sm = 0;
        for(int i=0; i<n; i++){
            sm+=v[i];
            for(int j=0; j<m+1; j++){
                for(int k=0; k<dp[j].size(); k++){
                    dp2[i][j] = min(dp2[i][j], dp[j][k]&v[i]);
                }
                if(j==0){
                    difs.push_back(v[i]-dp2[i][j]);
                }
                else{
                    difs.push_back(dp2[i][j-1]-dp2[i][j]);
                }
            }
        }
        sort(difs.begin(), difs.end());
        int pos = difs.size()-1;
        int diff = 0;   
        while(k){
            if(pos<0){
                break;
            }
            diff+=difs[pos];
            pos--;
            k--;
        }
        cout << sm-diff << endl;
    }
}