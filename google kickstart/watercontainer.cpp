#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
string c;
vector<int>v[100100];
int vis[100100];
int level[100100];
int t, q, n;
void dfs(int pos, int lvl){
    for(int k=0; k<v[pos].size(); k++){
        if(!vis[v[pos][k]]){
            vis[v[pos][k]] = 1;
            // cout << v[pos][k] << endl;
            level[lvl+1]++;
            dfs(v[pos][k], lvl+1);
        }
    }
    return;
}
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> q;
        for(int j=0; j<n-1; j++){
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        level[0] = 1;
        vis[1] = 1;
        dfs(1, 0);
        // cout << level[1] << endl;
        int curlevel = 0;
        int total = 0;
        int amt = 0;
        for(int j=0; j<q; j++){
            int a;
            cin >> a;
            amt++;
            if(level[curlevel]==amt){
                curlevel++;
                total+=amt;
                amt=0;
            }   
        }
        cout << "Case #" << i+1 << ": " << total << endl;
        memset(level, 0, sizeof(level));
        for(int j=0; j<100100; j++) v[j].clear();
        memset(vis, 0, sizeof(vis));

    }

}