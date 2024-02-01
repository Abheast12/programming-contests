#include<iostream>
using namespace std;
int grid[40][40];
int main(){
    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i+1][j+1];
            grid[i][n+1]+=grid[i+1][j+1];
            grid[n+1][j]+=grid[i+1][j+1];
        }
    }
    int ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][n+1] < grid[n+1][j]) ans++;
        }
    }
    cout << ans << endl;
    
}