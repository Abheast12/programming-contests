#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<cstring>
using namespace std;
int visited[42][720];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag = false;
int maxx = -1;
int dfss(int x, int y, int (&vis)[42][720], int (&dfs)[42][720]){
    // cout << x << " " << y << endl;
    vis[x][y] = 1;
    // if(x > maxx){
    //     cout << x << " " << y << endl;
    //     maxx = x;
    // }
    if(x == 41){
        flag = true;
        return 1;
    }
    for(int i=0; i<4; i++){
        int newx = x + dx[i];
        int newy = y + dy[i];
        newy = (newy + 720) % 720;
        if(newx >=0 && newx < 42 && newy >= 0 && newy < 720 && vis[newx][newy] == 0 && dfs[newx][newy] == 0){
            int g = dfss(newx, newy, vis, dfs);
            if(g == 1){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int dfs[42][720];

    int t;
    cin >> t;
    vector<pair<pair<char, int>, pair<int, int>>>q;
    while(t--){
        memset(dfs, 0, sizeof(dfs));
        memset(visited, 0, sizeof(visited));
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            char c;
            cin >> c;
            int r1, r2, r3;
            cin >> r1 >> r2 >> r3;
            q.push_back({{c, r1}, {r2, r3}});
            // cout << "here" << endl;
            
        }
        for(int i=0; i<n; i++){
            char c = q[i].first.first;
            int r1 = q[i].first.second;
            int r2 = q[i].second.first;
            int r3 = q[i].second.second;
            if(c=='S'){
                for(int j=r1*2; j<=r2*2; j++){
                    dfs[j][r3*2] = 1;
                }
            }
            else if(c=='C'){
                // if(r2 > r3){
                //     swap(r2, r3);
                // }
                // cout << "here2" << endl;
                int cur = r2*2;
                while(cur != r3*2){
                    dfs[r1*2][cur] = 1;
                    cur = (cur + 1) % 720;
                }
                dfs[r1*2][r3*2] = 1;
                // for(int j=r2*2; j<=r3*2; j++){
                //     dfs[r1*2][j%720] = 1;
                // }
            }
        }
        // for(int i=1; i<=5; i++){
        //     for(int j=0; j<720; j++){
        //         cout << dfs[i][j] << " ";
        //     }
        //     cout << "______" << endl;
        // }
        // cout << maxx << endl;
        flag = false;
        dfss(0, 0, visited, dfs);
        q.clear();
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}