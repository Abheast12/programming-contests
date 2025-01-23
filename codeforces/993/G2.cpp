#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>>adj(n+1);
        vector<vector<int>>adj2(n+1);
        // map<int, int>mp;
        for(int i=1; i<=n; i++){
            int a;
            cin >> a;
            adj[i].push_back(a);
            adj2[a].push_back(i);

        }
        vector<int>vis(n+1, 0);
        int mxd = 0;
        map<int, int>cycle;
        for(int i=1; i<=n; i++){
            stack<int>q;
            int cur = i;  
            while(!vis[cur]){
                vis[cur] = i;
                q.push(cur);
                cur = adj[cur][0];
            }
            if(!q.empty() && vis[cur] == i){
                // int tmp = q.top();
                cycle[cur] = 1;
                // q.pop();
                while(!q.empty()){
                    if(q.top() == cur){
                        break;
                    }
                    cycle[q.top()] = 1;
                    q.pop();
                }
            }
            
        }
        // cout << "here" << endl;
        queue<int>q;
        for(int i=1; i<=n; i++){
            // cout << i << " " << cycle[i] << endl;
            if(cycle[i]){
                int tmpd= 0;
                for(int c : adj2[i]){
                    if(!cycle[c]) q.push(c);
                    int dd = 0;
                    while(!q.empty()){
                        int cur = q.front();
                        dd++;
                        q.pop();
                        for(int cc : adj2[cur]){
                            if(!cycle[cc]) q.push(cc);
                        }
                    }
                    tmpd = max(tmpd, dd);
                }
                // cout << i << " " << tmpd << endl;
                mxd = max(mxd, tmpd);
            }
        }
        // while(!q.empty()){
        //     int cur = q.front().first;
        //     int d = q.front().second;
        //     q.pop();
        //     mxd = max(mxd, d);
        //     for(int c : adj2[cur]){
        //         if(!cycle[c]) q.push({c, d+1});
        //     }
        // }
        cout << 2 + mxd << endl;

    }
}