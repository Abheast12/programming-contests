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
        int n;
        cin >> n;
        vector<vector<int>>v(510, vector<int>(510, -1));
        int curx = (n+1)/2;
        int cury = (n+1)/2;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int val =0;
        int dir = 3;
        while(val < n*n){
            v[curx][cury] = val;
            int nx = curx + dx[(dir+1)%4];
            int ny = cury + dy[(dir+1)%4]; 
            if(v[nx][ny] == -1){
                curx = nx;
                cury = ny;
                dir = (dir+1)%4;
            }
            else{
                curx = curx + dx[dir];
                cury = cury + dy[dir];
            }
            val++;
        }

        // vector<pair<int, pair<int, int>>>numSubgrids;
        // for(int i=1; i<=n; i++){
        //     for(int j=1; j<=n; j++){
        //         numSubgrids.push_back({i*(n+1-i)*j*(n+1-j), {i, j}});
        //     }
        // }
        // sort(numSubgrids.begin(), numSubgrids.end());
        // int val = 0;
        // for(int i=numSubgrids.size()-1; i>=0; i--){
        //     v[numSubgrids[i].second.first][numSubgrids[i].second.second] = val;
        //     val++;
        // }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
}