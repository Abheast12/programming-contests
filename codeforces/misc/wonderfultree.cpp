#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;
vector<int>adj[5002];
long long bfs(int cur, long long dif, vector<long long>&difs){
    priority_queue<pair<pair<long long, int>, int>>pq;
    for(int j : adj[cur]){
        pq.push({{difs[j], j}, 1});
    }
    long long tot = 0;
    long long ans = 0;
    while(!pq.empty()){
        long long f = pq.top().first.first;
        int s = pq.top().first.second;
        int g = pq.top().second;
        pq.pop();
        if(f >= dif-tot){
            if(f!= LLONG_MAX) difs[s] -= (dif-tot);
            ans+=(dif-tot)*g;
            break;
        }
        else if(f > 0){
            ans+=(f)*g;
            difs[s] = 0;
            tot+=f;
        }
        for(int j : adj[s]){
            pq.push({{difs[s], s}, g+1});
        }
    }
    difs[cur] = 0;
    return ans;
}
long long dfs(int cur, vector<long long>&v, vector<long long>&difs){
    long long sum = 0;
    for(int j : adj[cur]){
        // long long dif_before = difs[j];
        sum += dfs(j, v, difs);
        // long long dif_after = difs[j];
        // difs[cur] += (dif_after-dif_before);
    }
    if(difs[cur] < 0){
        // for (long long asdf : difs){
        //     cout << asdf << " ";
        // }
        // cout << endl;
        sum += bfs(cur, difs[cur]*-1, difs);
        // for (long long asdf : difs){
        //     cout << asdf << " ";
        // }
        // cout << endl;
        // cout << cur << " " << sum << endl;
    }
    return sum;
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>v(n+1);
        vector<long long>difs(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        for(int i=2; i<=n; i++){
            int gg;
            cin >> gg;
            adj[gg].push_back(i);
            // adj[gg].push_back(i);
        }
        for(int i=1; i<=n; i++){
            long long sum = 0;
            for(int a : adj[i]){
                sum+=v[a];
            }
            if(adj[i].size() == 0){
                difs[i] = LLONG_MAX;
            }
            else difs[i] = (sum - v[i]);
            // cout << difs[i] << " ";
        }
        // cout << endl;
        long long ans = dfs(1, v, difs);
        cout << ans << endl;
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }

    }
}