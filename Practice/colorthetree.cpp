#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>v[100100];
queue<pair<int, int>>q;
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int weights[100100];
        vector<int>depth[100100];
        int kids[1000100];
        for(int i=0; i<n; i++){
            int w;
            cin >> w;
            weights[i] = w;
        }
        for(int i=0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            if(a<b){
                v[a].push_back(b);
            }
            else{
                v[b].push_back(a);
            }
        }
        q.push({0, 1});

        while(!q.empty()){
            int d = q.front().first;
            int nd = q.front().second;
            depth[d].push_back(nd);
            q.pop();
            if(v[nd].size()>0){
                kids[d]++;
            }
            for(int i=0; i<v[nd].size(); i++){
                q.push({d+1, v[nd][i]});
            }
        }


    }
}