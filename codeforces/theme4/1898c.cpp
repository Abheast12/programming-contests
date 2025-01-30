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
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        int sm = n+m-2;
        if(sm%2 != k%2){
            cout << "NO" << endl;
            continue;
        }
        if(k < sm){
            cout << "NO" << endl;
            continue;
        }
        int dif = k-sm;
        vector<vector<char>>v(n, vector<char>(m-1, 'R'));
        vector<vector<char>>v2(n-1, vector<char>(m, 'B'));
        cout << "YES" << endl;
        if(dif%4==0){
            int xpos = 0;
            int ypos = 0;
            int col = 1;
            while(xpos < n-1){
                if(col == 1){
                    v2[xpos][ypos] = 'R';
                }
                col = 1-col;
                xpos++;
            }
            while(ypos < m-1){
                if(col == 0){
                    v[xpos][ypos] = 'B';
                }
                col = 1-col;
                ypos++;
            }
            if(col == 1) v2[n-2][m-1] = 'R';
            if(col == 1) v[n-2][m-2] = 'B';
            if(col == 1) v2[n-2][m-2] = 'R';
        }
        else if(dif%4 == 2){
            int xpos = 2;
            int ypos = 0;
            int col = 1;
            while(xpos < n-1){
                if(col == 1){
                    v2[xpos][ypos] = 'R';
                }
                col = 1-col;
                xpos++;
            }
            // cout << col << " " << xpos << " " << ypos << endl;
            // xpos--;
            while(ypos < m-1){
                if(col == 0){
                    v[xpos][ypos] = 'B';
                }
               
                col = 1-col;
                 ypos++;
            }
            if(col == 1) v2[n-2][m-1] = 'R';
            if(col == 1) v[n-2][m-2] = 'B';
            if(col == 1) v2[n-2][m-2] = 'R';
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m-1; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        for(int i=0; i<n-1; i++){
            for(int j=0; j<m; j++){
                cout << v2[i][j] << " ";
            }
            cout << endl;
        }
    }
}