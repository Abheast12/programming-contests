#include<iostream>
#include<vector>
using namespace std;
vector<int>v[100100];
int vis[100100];
int tot = 0;
int dfs(int cur, int val){
    vis[cur] = 1;
    int ct = 1;
    for(int i=0; i<v[cur].size(); i++){
        if(vis[v[cur][i]] == 0){
            // vis[v[cur][i]] = 1;
            ct+=dfs(v[cur][i], val);

        }
    }
    if(ct >= val){
        tot++;
        // cout << cur << " " << ct << endl;
        return 0;
    }
    else{
        return ct;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n, k;
        cin >> n >> k;
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int low = 1;
        int high = n;
        int ans = 1;
        while(low <= high){
            tot = 0;
            int mid = (low+high)/2;
            // cout << mid << endl;
            dfs(1, mid);
            
            if(tot >k){
                ans = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
            for(int i=1; i<=n; i++){
            // v[i].clear();
                vis[i] = 0;
            }
        }
        cout << ans << endl;
        for(int i=1; i<=n; i++){
            v[i].clear();
            // vis[i] = 0;
        }

    }
}