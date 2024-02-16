#include<iostream>
#include<vector>
using namespace std;
vector<long long>v[300300];
int vis[300300];
long long dp[300300];
long long dfs(long long cur){
    vis[cur] = 1;
    long long tot = 1;
    for(auto i: v[cur]){
        if(vis[i]==0){
            tot*=dfs(i);
            tot%=998244353;
        }
    }
    dp[cur] = tot;
    return tot+1;
}
int main(){
    long long t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        for(int j=0; j<n-1; j++){
            long long a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        long long ans = 1;
        for(int j=1; j<=n; j++){
            ans+=dp[j];
        }
        ans%=998244353;
        cout << ans << endl;
        for(int j=1; j<=n; j++){
            v[j].clear();
            vis[j] = 0;
            dp[j] = 0;
        }
    }
}