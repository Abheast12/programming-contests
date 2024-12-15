#include<iostream>
#include<vector>
using namespace std;

int main(){
    int r, c;
    char a[11][11];
    int ai[11][11];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            char g;
            cin >> g;
            a[i][j] = g;
        }
    }

}