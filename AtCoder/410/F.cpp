#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int h,w;
        cin >> h >> w;
        vector<vector<int>>grid(h, vector<int>(w, 0));
        for(int i=0; i<h; i++){
            string s;
            cin >> s;
            for(int j=0; j<w; j++){
                if(s[j] == '#') grid[i][j] = 1;
                else grid[i][j] = -1;
            }
        }
        if(h > w){
            vector<vector<int>>newGrid(w, vector<int>(h, 0));
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    newGrid[j][i] = grid[i][j];
                }
            }
            swap(h, w);
            grid = newGrid;
        }
        vector<vector<int>>pref(h, vector<int>(w, 0));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(i > 0) pref[i][j] = pref[i-1][j];
                pref[i][j] += grid[i][j];
            }
        }
        int ans =0;
        vector<int>vals(h*w*2+1, 0);
        vals[h*w] = 1;
        vector<int>used(w);
        for(int i=0; i<h; i++){
            for(int j=i; j<h; j++){
                
                
                int tot =0;
                for(int k=0; k<w; k++){
                    int val = pref[j][k];
                    if(i > 0) val -= pref[i-1][k];
                    tot += val;
                    ans+=vals[tot+h*w];
                    vals[tot+h*w]++;
                    used[k] = tot+h*w;
                }
                for(int k=0; k<w; k++){
                    vals[used[k]]--;
                }
            }
        }
        cout << ans << endl;
    }
    
}