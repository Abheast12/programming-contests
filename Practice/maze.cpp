#include<iostream>
#include<vector>
#include<string>
using namespace std;
int vis[105][105];
string grid[105][105];
vector<pair<int, int>>v;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int touched = 0;
int n, m;
bool useful = false;
void dfs(int x, int y){
    // cout << x << " " << y << endl;
    vis[x][y] = 1;
    for(int j=0; j<4; j++){
        int newx = dx[j]+x;
        int newy = dy[j]+y;
        if(newx>=0 && newx<n && newy>=0 && newy<m && vis[newx][newy] != 1){
            if(grid[newx][newy]=="."){
                useful = true;
                touched++;
                dfs(newx, newy);
            }
            else if(grid[newx][newy]==" "){
                dfs(newx, newy);
            }
        }
    }
    return;
}
int main(){
    // int n, m;
    cin >> n >> m;
    int dots = 0;
    for(int i=0; i<n; i++){
        string s;
        getline(cin >> ws, s);
        for(int j=0; j<m; j++){
            // char c;
            // cout << "a" << endl;
            
            // cin >> c;
            // if(s[j]==' ') cout << "here" << endl;
            grid[i][j] = s[j];
            if(grid[i][j]=="."){
                dots++;
            }
            else if(grid[i][j] != "X" && grid[i][j] != " "){
                v.push_back({i, j});
            }
        }
        // cout << "here" << endl;
    }
    // cout << "a" << endl;
    int u = 0;
    for(int i=0; i<v.size(); i++){
        useful = false;
        for(int j=0; j<4; j++){
            int newx = dx[j]+v[i].first;
            int newy = dy[j]+v[i].second;
            // cout << i << endl;
            if(newx>=0 && newx<n && newy>=0 && newy<m){
                if((grid[newx][newy]=="." || grid[newx][newy]==" ") && vis[newx][newy] == 0){
                    break;
                    // dfs(newx, newy);
                }
            }
        }
        dfs(v[i].first, v[i].second);
        if(useful) u++;
    }
    cout << u << " " << dots - touched << endl;

}