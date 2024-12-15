#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>red;
vector<int>black;
queue<pair<pair<int, int>, int>>q;
int dp[200][200];
int main(){
    int a, b;
    cin >> a >> b;
    red.push_back(1);
    red.push_back(4);
    black.push_back(2);
    black.push_back(3);
    black.push_back(5);
    black.push_back(6);
    q.push({{0, 0}, 0});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        if(z!=3){
            for(int i : red){
                q.push({{x+i, y}, z+1});
            }
            for(int i : black){
                q.push({{x, y+i}, z+1});
            }
        } else {
            dp[x][y] = 1;
        }
    }
    if(dp[a][b]==1) cout << "Yes" << endl;
    else cout << "No" << endl;
}