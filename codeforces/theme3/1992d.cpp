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
        vector<char>v;
        v.push_back('L');
        for(int i=1; i<=n; i++){
            char c;
            cin >> c;
            v.push_back(c);
        }
        // v[0] = 'L';
        int cur = 0;
        bool land = true;
        int swim = 0;
        while(cur <= n){
            // cout << cur << endl;
            if(v[cur] == 'L'){
                if(cur + m > n){
                    cout << "YES" << endl;
                    break;
                }
                int prev = cur;
                for(int i=prev+1; i<=prev+m; i++){
                    // cout << "here " << i << endl;
                    if(v[i] == 'L'){
                        cur = i;
                        land = true;
                        break;
                    }
                    if(v[i] == 'W'){
                        cur = i;
                        land = false;
                    }
                }
                if(cur == prev){
                    cout << "NO" << endl;
                    break;
                }
            }
            else if(v[cur] == 'W'){
                swim++;
                if(swim > k){
                    cout << "NO" << endl;
                    break;
                }
                cur++;
                if(cur > n){
                    cout << "YES" << endl;
                    break;
                }
            }
            else if(v[cur] == 'C'){
                cout << "NO" << endl;
                break;
            }
        }

    }
}