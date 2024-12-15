#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>>v(n, vector<char>(m));
    pair<int, int>start;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c;
            cin >> c;
            v[i][j]=c;
            if(v[i][j]=='S'){
                start = {i, j};
            }
        }
    }
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue<pair<pair<int, int>, pair<int, vector<int>>>>q;
    map<pair<pair<int, int>, pair<int, int>>, int>vis;
    q.push({start, {0, {}}});
    while(!q.empty()){
        pair<int, int>cur = q.front().first;
        int dist = q.front().second.first;
        vector<int>path = q.front().second.second;
        // cout << cur.first << " " << cur.second << " " << dist << endl;
        q.pop();
        int consec = 1;
        if(path.size()>0){
            
            if(path.size()>1 && path[0] == path[1]){
                consec++;
            }
            if(path.size()>2 && path[1] == path[2]){
                consec++;
            }
            if(vis[{cur,{path[0], consec}}] == 1){
                continue;
            }
        }
        if(path.size()>0){
            vis[{cur, {path[0], consec}}] = 1;
        }
        // if(vis[cur]==2){
        //     continue;
        // }
        // cout << vis[cur] << endl;
        // vis[cur]++;
        if(v[cur.first][cur.second]=='T'){
            cout << dist << endl;
            return 0;
        }
        for(int i=0; i<4; i++){
            int nx = cur.first+dx[i];
            int ny = cur.second+dy[i];
            // cout << nx << " " << ny << endl;
            int tmp_consec =1;
            if(path.size()>0){
                if(path.size()>=1 && path[0] == i){
                    tmp_consec++;
                }
                if(path.size()>=2 && path[1] == path[0]){
                    tmp_consec++;
                }
                if(path.size()>=3 && path[2] == path[1]){
                    tmp_consec++;
                }
            }
            if(tmp_consec>3){
                continue;
            }
            if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]!='#' && !vis[{{nx, ny}, {i, tmp_consec}}]){
                vector<int>tmp = path;
                if(tmp.size()==3){
                    tmp.pop_back();
                }
                tmp.insert(tmp.begin(), i);
                // if(tmp.size()<3){
                //     tmp.insert(tmp.begin(), i);
                // }
                // else{
                //     tmp.erase(tmp.begin());
                //     tmp.push_back(i);
                // }
                q.push({{nx, ny}, {dist+1, tmp}});
            }
        }
    }
    cout << -1 << endl;
}