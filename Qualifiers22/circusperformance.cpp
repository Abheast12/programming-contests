#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<pair<int, int>>v;
vector<int>ans;
int vis[1010];
int main(){
    int n;
    cin >> n;
    int a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        v.push_back({a, b});
    }
    int bc1, bc2;
    float bang = -1;
    for(int i=1; i<v.size(); i++){
        for(int j=1; j<v.size(); j++){
            if(i!=j){
                int x1 = v[i].first-v[0].first;
                int y1 = v[i].second-v[0].second;
                int x2 = v[i].first-v[j].first;
                int y2 = v[i].second-v[j].second;
                int dot = x1*x2 + y1*y2;
                int det = x1*y2 - y1*x2;
                float angle = atan2(det, dot);
                if(angle>bang){
                    bang = angle;
                    bc1 = i;
                    bc2 = j;
                }
            }
        }
    }
    ans.push_back(1);
    vis[1] = 1;
    ans.push_back(bc1+1);
    vis[bc1+1] = 1;
    ans.push_back(bc2+1);
    vis[bc2+1] = 1;
    int left = n-3;
    
    while(left>0){
        int vx1 = v[v.size()-2].first;
        int vx2 = v[v.size()-1].first;
        int vy1 = v[v.size()-2].second;
        int vy2 = v[v.size()-1].second;
        bang = -1;
        for(int j=1; j<v.size(); j++){
            if(vis[j]!=1){
                int x1 = vx2-vx1;
                int y1 = vy2-vy1;
                int x2 = vx2-v[j].first;
                int y2 = vy2-v[j].second;
                int dot = x1*x2 + y1*y2;
                int det = x1*y2 - y1*x2;
                float angle = atan2(det, dot);
                if(angle>bang){
                    bang = angle;
                    bc1 = j;
                }
            }
        }
        ans.push_back(bc1+1);
        vis[bc1+1] = 1;
        left--;
    }
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
}