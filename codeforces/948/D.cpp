#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>>v(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        int ans = 0;
        
    }
}