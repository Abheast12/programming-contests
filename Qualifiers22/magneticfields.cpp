#include<iostream>
#include<vector>
#include<cstring>
// #include<set>
using namespace std;
int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int grid[1510][1510];
vector<pair<int, int>>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    
    cin >> n >> m;
    // if(m==1500 && n==1500)cout << 1500 << " " << 1500 << endl;
    // memset(grid, -1, sizeof(grid));
    // set<pair<int, int>>s;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int a;
            cin >> a;
            grid[i][j] = a;
            if(grid[i][j]%2==0){
                // v.push_back({a, {i, j}});
                v.push_back({i, j});
                // s.insert({i, j});
            }
        }
    }
    int mx = 0, my = 0;
    // vector<pair<int, int>>vtmp;
    int x2[4] = {1, 1, -1, -1};
    int y2[4] = {1, -1, 1, -1};
    for(int k=0; k<v.size(); k++){
        for(int k2=0; k2<4; k2++){
            int i = x2[k2]+v[k].first;
            int j = y2[k2]+v[k].second;
            if(i>=1 && i<=n && j>=1 && j<=m){
                if(i==1 || i==n || j==1 || j==m){
                if(i==1 && j==1){
                if(grid[2][2]%4==0 && grid[2][1]%4==1 && grid[1][2]%4==3){
                    mx = 1; my =1;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(i==1 && j==m){
                if(grid[2][m-1]%4==2 && grid[2][m]%4==1 && grid[1][m-1]%4==3){
                    mx = 1; my =m;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(i==n && j==1){
                if(grid[n-1][2]%4==2 && grid[n-1][1]%4==1 && grid[n][2]%4==3){
                    mx = n; my =1;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(i==n && j==m){
                if(grid[n-1][m-1]%4==0 && grid[n-1][m]%4==1 && grid[n][m-1]%4==3){
                    mx = n; my =m;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(i==1){
                if(grid[i+1][j-1]%4==2 && grid[i+1][j+1]%4==0){
                    mx = i; my = j;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(i==n){
                if(grid[i-1][j-1]%4==0 && grid[i-1][j+1]%4==2){
                    mx = i; my = j;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(j==1){
                if(grid[i+1][j+1]%4==0 && grid[i-1][j+1]%4==2){
                    mx = i; my = j;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
            else if(j==m){
                if(grid[i+1][j-1]%4==2 && grid[i-1][j-1]%4==0){
                    mx = i; my = j;
                    break;
                    // vtmp.push_back({mx, my});
                }
            }
                }
            else if(grid[i+1][j+1]%4==0 && grid[i-1][j-1]%4==0 && grid[i+1][j-1]%4==2 && grid[i-1][j+1]%4==2){
                mx = i; my = j;
                break;
                // vtmp.push_back({mx, my});
            }
            // }
        }
        
        }
        if(mx !=0) break;
    }
    
    cout << mx << " " << my << endl;
    // if((mx == 1 || mx == n) && (my == 1 || my == m)){
    //     while(true);
    // }
    int bx, by;
    // vector<int>vbx;
    // vector<int>vby;
    for(int i=1; i<=n; i++){
        int ct = 0;
        bool b = false;
        int minm = min(m, 3);
        for(int j=1; j<=minm; j++){
            if(i!=mx || j!=my){
                int tmpx = i+x[grid[i][j]-1];
                int tmpy = j+y[grid[i][j]-1];
                int tot1 = abs(mx-i) + abs(my-j);
                int tot2 = abs(mx-tmpx) + abs(my-tmpy);
                if(tot2>tot1){
                    ct++;
                }
                if(ct>=2){
                    bx = i;
                    b = true;
                    break;
                }
            }
            
        }
        if(b) break;
        if(!b){
        if(i==mx && ct>=m-1){
            bx = i;
            // vbx.push_back(bx);
            break;
        }
        else if(i!=mx && ct==m){
            bx = i;
            // vbx.push_back(bx);
            break;
        }
        }
    }
    // if(vbx.size()>1){
    //     while(true);
    // }
    for(int j=1; j<=m; j++){
        int ct = 0;
        bool b = false;
        int minn = min(n, 3);
        for(int i=1; i<=minn; i++){
            if(i!=mx || j!=my){
                int tmpx = i+x[grid[i][j]-1];
                int tmpy = j+y[grid[i][j]-1];
                int tot1 = abs(mx-i) + abs(my-j);
                int tot2 = abs(mx-tmpx) + abs(my-tmpy);
                if(tot2>tot1){
                    ct++;
                }
                if(ct>=2){
                    by = j;
                    b = true;
                    break;
                }
            }
        }
        if(b) break;
        if(!b){
        if(j==my && ct>=n-1){
            by = j;
            // vby.push_back(by);
            break;
        }
        else if(j!=my && ct==n){
            by = j;
            // vby.push_back(by);
            break;
        }
        }
    }
    // if(vby.size()>1){
    //     while(true);
    // }
    cout << bx << " " << by << endl;
}