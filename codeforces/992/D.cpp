#include<iostream>
#include<vector>

using namespace std;
// bool isPrime(int p){
//     for(int i=2; i*i<=p; i++){
//         if(p%i==0){
//             return false;
//         }
//     }
// }
int lastUsed = 0;
void dfs(vector<vector<int>>&v, vector<int>&visited, int cur, int par, vector<int>&res){
    visited[cur] = 1;
    int dif = lastUsed-res[par];
    // cout << "cur: " << cur << " par: " << par << " lastUsed: " << lastUsed<< endl;
    if(dif==0){
        lastUsed++;
        res[cur] = lastUsed;
    }
    else if(dif==1 || dif==2){
        res[cur] = res[par]+4;
        lastUsed = res[par]+4;
    }
    else if(dif%2==0){
        res[cur] = lastUsed+2;
        lastUsed = lastUsed+2;
    }
    else{
        res[cur] = lastUsed+1;
        lastUsed = lastUsed+1;
    }
    for(int i=0; i<v[cur].size(); i++){
        if(v[cur][i]==par){
            continue;
        }
        if(visited[v[cur][i]]==1){
            continue;
        }
        dfs(v, visited, v[cur][i], cur, res);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>v(n+1);
        for(int i=0; i<n-1;i++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int start =-1;
        for(int i=1; i<=n; i++){
            if(v[i].size()==1){
                start = i;
                break;
            }
        }
        vector<int>res(n+1, 0);
        vector<int>visited(n+1, 0);
        lastUsed =0;
        dfs(v, visited, start, 0, res);
        for(int i=1; i<=n; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
}