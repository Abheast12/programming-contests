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
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<vector<int>>v(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> v[i][j];
            }
        }
        
        vector<int>csum(m, 0);
        vector<int>rsum(n, 0);
        for(int i=0; i<n; i++){
            int sm = 0;
            for(int j=0; j<m; j++){
                sm+=v[i][j];
            }
            rsum[i] = sm;
        }
        for(int j=0; j<m; j++){
            int sm = 0;
            for(int i=0; i<n; i++){
                sm+=v[i][j];
            }
            csum[j] = sm;
        }
        // cout << "here" << endl;
        vector<int>run(n, 0);
        vector<int>cun(m, 0);
        map<pair<int, int>, int>mp;
        int xpos = 0;
        int ypos = 0;
        int k=-1;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'D'){
                int totk = 1-run[xpos];
                run[xpos] += totk;
                cun[ypos] += totk;
                int sm = rsum[xpos];
                rsum[xpos] -= sm;
                csum[ypos] -= sm;
                mp[{xpos, ypos}] = totk;
                v[xpos][ypos]-=sm;
                xpos++;
            }
            else {
                int totk = 1-cun[ypos];
                run[xpos] += totk;
                cun[ypos] += totk;
                int sm = csum[ypos];
                rsum[xpos] -= sm;
                csum[ypos] -= sm;
                mp[{xpos, ypos}] = totk;
                v[xpos][ypos]-=sm;
                ypos++;
            }
        }
        // cout << "here" << endl;
        if(s[s.length()-1] == 'D'){
            int totk = 1-run[xpos];
            run[xpos] += totk;
            cun[ypos] += totk;
            int sm = rsum[xpos];
            rsum[xpos] -= sm;
            csum[ypos] -= sm;
            mp[{xpos, ypos}] = totk;
            v[xpos][ypos]-=sm;

            sm = csum[ypos];
            if(1-cun[ypos]==0){
                k = 1;
            }
            else k = sm/(1-cun[ypos]);
        }
        else {
            int totk = 1-cun[ypos];
            run[xpos] += totk;
            cun[ypos] += totk;
            int sm = csum[ypos];
            rsum[xpos] -= sm;
            csum[ypos] -= sm;
            mp[{xpos, ypos}] = totk;
            v[xpos][ypos]-=sm;
            sm = rsum[xpos];
            if(1-run[xpos]==0){
                k = 1;
            }
            else k = sm/(1-run[xpos]);
        }
        // cout << "here" << endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v[i][j] += mp[{i, j}]*k;
                cout << v[i][j] << " ";
            }
            cout << endl;
        }

    }
}