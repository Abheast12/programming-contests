#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int x[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int y[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int grid[1510][1510];
vector<pair<int, pair<int, int>>>v;
int main(){
    int n, m;
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n >> m;
    // if(m>100 && n > 100)while(true);
    memset(grid, -1, sizeof(grid));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int a;
            cin >> a;
            grid[i][j] = a;
            if(grid[i][j]%2==0){
                v.push_back({a, {i, j}});
            }
        }
    }
    int mx = 0, my = 0;
    vector<pair<int, int>>vtmp;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(i==1 && j==1){
                if(grid[2][2]%4==0 && grid[2][1]%4==1 && grid[1][2]%4==3){
                    mx = 1; my =1;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(i==1 && j==m){
                if(grid[2][m-1]%4==2 && grid[2][m]%4==1 && grid[1][m-1]%4==3){
                    mx = 1; my =m;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(i==n && j==1){
                if(grid[n-1][2]%4==2 && grid[n-1][1]%4==1 && grid[n][2]%4==3){
                    mx = n; my =1;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(i==n && j==m){
                if(grid[n-1][m-1]%4==0 && grid[n-1][m]%4==1 && grid[n][m-1]%4==3){
                    mx = n; my =m;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(i==1){
                if(grid[i+1][j-1]%4==0 && grid[i+1][j+1]%4==2){
                    mx = i; my = j;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(i==n){
                if(grid[i-1][j-1]%4==0 && grid[i-1][j+1]%4==2){
                    mx = i; my = j;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(j==1){
                if(grid[i+1][j+1]%4==0 && grid[i-1][j+1]%4==2){
                    mx = i; my = j;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(j==m){
                if(grid[i+1][j-1]%4==2 && grid[i-1][j-1]%4==0){
                    mx = i; my = j;
                    // break;
                    vtmp.push_back({mx, my});
                }
            }
            else if(grid[i+1][j+1]%4==0 && grid[i-1][j-1]%4==0 && grid[i+1][j-1]%4==2 && grid[i-1][j+1]%4==2){
                mx = i; my = j;
                // break;
                vtmp.push_back({mx, my});
            }
        }
        if(mx !=0) break;
    }
    
    cout << mx << " " << my << endl;
    // if((mx == 1 || mx == n) && (my == 1 || my == m)){
    //     while(true);
    // }
    int bx, by;
    vector<int>vbx;
    vector<int>vby;
    for(int i=1; i<=n; i++){
        int ct = 0;
        for(int j=1; j<=m; j++){
            if(i!=mx || j!=my){
                int tmpx = i+x[grid[i][j]-1];
                int tmpy = j+y[grid[i][j]-1];
                int tot1 = abs(mx-i) + abs(my-j);
                int tot2 = abs(mx-tmpx) + abs(my-tmpy);
                if(tot2>tot1){
                    ct++;
                }
            }
            
        }
        if(i==mx && ct>=m-1){
            bx = i;
            vbx.push_back(bx);
            // break;
        }
        else if(i!=mx && ct==m){
            bx = i;
            vbx.push_back(bx);
            // break;
        }
    }
    // if(vbx.size()>1){
    //     while(true);
    // }
    for(int j=1; j<=m; j++){
        int ct = 0;
        for(int i=1; i<=n; i++){
            if(i!=mx || j!=my){
                int tmpx = i+x[grid[i][j]-1];
                int tmpy = j+y[grid[i][j]-1];
                int tot1 = abs(mx-i) + abs(my-j);
                int tot2 = abs(mx-tmpx) + abs(my-tmpy);
                if(tot2>tot1){
                    ct++;
                }
            }
        }
        if(j==my && ct>=n-1){
            by = j;
            vby.push_back(by);
            // break;
        }
        else if(j!=my && ct==n){
            by = j;
            vby.push_back(by);
            // break;
        }
    }
    // if(vby.size()>1){
    //     while(true);
    // }
    cout << bx << " " << by << endl;
}

// for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         // if(s.find({i+1, j+1}) != s.end() || s.find({i-1, j+1}) != s.end() || s.find({i-1, j-1}) != s.end() || s.find({i+1, j-1}) != s.end()){
    //         if(i==1 && j==1){
    //             if(grid[2][2]%4==0 && grid[2][1]%4==1 && grid[1][2]%4==3){
    //                 mx = 1; my =1;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(i==1 && j==m){
    //             if(grid[2][m-1]%4==2 && grid[2][m]%4==1 && grid[1][m-1]%4==3){
    //                 mx = 1; my =m;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(i==n && j==1){
    //             if(grid[n-1][2]%4==2 && grid[n-1][1]%4==1 && grid[n][2]%4==3){
    //                 mx = n; my =1;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(i==n && j==m){
    //             if(grid[n-1][m-1]%4==0 && grid[n-1][m]%4==1 && grid[n][m-1]%4==3){
    //                 mx = n; my =m;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(i==1){
    //             if(grid[i+1][j-1]%4==2 && grid[i+1][j+1]%4==0){
    //                 mx = i; my = j;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(i==n){
    //             if(grid[i-1][j-1]%4==0 && grid[i-1][j+1]%4==2){
    //                 mx = i; my = j;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(j==1){
    //             if(grid[i+1][j+1]%4==0 && grid[i-1][j+1]%4==2){
    //                 mx = i; my = j;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(j==m){
    //             if(grid[i+1][j-1]%4==2 && grid[i-1][j-1]%4==0){
    //                 mx = i; my = j;
    //                 break;
    //                 // vtmp.push_back({mx, my});
    //             }
    //         }
    //         else if(grid[i+1][j+1]%4==0 && grid[i-1][j-1]%4==0 && grid[i+1][j-1]%4==2 && grid[i-1][j+1]%4==2){
    //             mx = i; my = j;
    //             break;
    //             // vtmp.push_back({mx, my});
    //         }
    //         // }
    //     }
    //     if(mx !=0) break;
    // }
    // if(vtmp.size()>1 || (mx ==0 && my == 0)){
    //     // mx = vtmp[1].first;
    //     // my = vtmp[1].second;
    //     while(true);
    // }
    // else{
    //     mx = vtmp[0].first;
    //     my = vtmp[0].second;
    // }
    // bool found = false;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=m; j++){
    //         int ct = 0;
    //         int outc = 0;
    //         for(int p=0; p<8; p++){
    //             int tct = 0;
    //             int tmpx = i;
    //             int tmpy = j;
    //             bool out = false;
                
    //             for(int q=0; q<=3; q++){
                    
    //                 // if(i==2 && j==1){
    //                 //     cout << tct << endl;
    //                 // }
    //                 // cout << tct << endl;
    //                 tmpx+=x[p];
    //                 tmpy+=y[p];
    //                 if(tmpx>0 && tmpx<=n && tmpy>0 && tmpy<=m){
    //                     if(grid[tmpx][tmpy] == (p+5)%8){
    //                         tct++;
    //                     }
    //                 }
    //                 else{
    //                     if(q==0) outc++;
    //                     out = true;
    //                     break;
    //                 }
    //             }
    //             if((out && tct>=1)||tct>=2){
    //                 ct++;
    //             }
    //         }
    //         if(outc > 4 && ct>=2){
    //             mx = i;
    //             my = j;
    //             found = true;
    //             break;
    //         }
    //         else if(outc < 4 && outc + ct>=5){
    //             mx = i;
    //             my = j;
    //             found = true;
    //             break;
    //         }
    //         if(i==2 && j==1) cout << ct << endl;
    //     }
    //     if(found) break;
    // }
    // for(int i=0; i<v.size(); i++){
    //     if(v[i].first == 2){
    //         int newx = v[i].second.first+x[v[i].first-1];
    //         int newy = v[i].second.second+y[v[i].first-1];
    //         if(newx>0 && newx<=n && newy>0 && newy<=m){
    //             if(grid[newx][v[i].second.second] == 3 && grid[v[i].second.first][newy] == 1){
    //                 mx = newx;
    //                 my = newy;
    //                 break;
    //             }
    //             else{
    //                 mx = newx+2;
    //                 my = newy-2;
    //                 break;
    //             }
    //         }
    //         else{
    //             mx = newx+2;
    //             my = newy-2;
    //             break;
    //         }
    //     }
    //     else if(v[i].first == 4){
    //         int newx = v[i].second.first+x[v[i].first-1];
    //         int newy = v[i].second.second+y[v[i].first-1];
    //         if(newx>0 && newx<=n && newy>0 && newy<=m){
    //             if(grid[newx][v[i].second.second] == 3 && grid[v[i].second.first][newy] == 5){
    //                 mx = newx;
    //                 my = newy;
    //                 break;
    //             }
    //             else{
    //                 mx = newx-2;
    //                 my = newy-2;
    //                 break;
    //             }
    //         }
    //         else{
    //             mx = newx-2;
    //             my = newy-2;
    //             break;
    //         }
    //     }
    //     else if(v[i].first == 6){
    //         int newx = v[i].second.first+x[v[i].first-1];
    //         int newy = v[i].second.second+y[v[i].first-1];
    //         if(newx>0 && newx<=n && newy>0 && newy<=m){
    //             if(grid[newx][v[i].second.second] == 7 && grid[v[i].second.first][newy] == 5){
    //                 mx = newx;
    //                 my = newy;
    //                 break;
    //             }
    //             else{
    //                 mx = newx-2;
    //                 my = newy+2;
    //                 break;
    //             }
    //         }
    //         else{
    //             mx = newx-2;
    //             my = newy+2;
    //             break;
    //         }
    //     }
    //     else if(v[i].first == 8){
    //         int newx = v[i].second.first+x[v[i].first-1];
    //         int newy = v[i].second.second+y[v[i].first-1];
    //         if(newx>0 && newx<=n && newy>0 && newy<=m){
    //             if(grid[newx][v[i].second.second] == 7 && grid[v[i].second.first][newy] == 1){
    //                 mx = newx;
    //                 my = newy;
    //                 break;
    //             }
    //             else{
    //                 mx = newx+2;
    //                 my = newy+2;
    //                 break;
    //             }
    //         }
    //         else{
    //             mx = newx+2;
    //             my = newy+2;
    //             break;
    //         }
    //     }
    // }