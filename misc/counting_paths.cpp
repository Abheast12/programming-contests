#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>>paths;
void calculatePath(int u, int r, vector<int>&v){
    if(r==0 && u ==0){
        paths.push_back(v);
        return;
    }
    if(r!=0){
        v.push_back(1);
        calculatePath(u, r-1, v);
        v.pop_back();
    }
    if(u!=0){
        v.push_back(0);
        calculatePath(u-1, r, v);
        v.pop_back();
    }
}
int main(){
    vector<int>v = {};
    calculatePath(6, 4, v);
    // cout << paths.size() << endl;
    int sub = 0;
    for(int i=0; i<paths.size(); i++){
        for(int j=0; j<paths[i].size(); j++){
            if(j>1){
                if(paths[i][j] == paths[i][j-1] && paths[i][j] == paths[i][j-2]){
                    sub++;
                    break; 
                }
            }
        }
    }
    cout << paths.size()-sub << endl;
}