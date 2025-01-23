#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<cmath>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        map<int, int>mp;
        sort(v.begin(), v.end());
        bool t = false;
        int best = -1;
        for(int i=n-1; i>=1; i--){
            if(v[i] == v[i-1]){
                t = true;
                best = i;
                break;
            }
        }
        if(!t){
            cout << -1 << endl;
            continue;
        }
        int min_dist = 1e9;
        int idx1 = -1;
        int idx2 = -1;
        for(int i=0; i<n-1; i++){
            if(i == best || i == best-1)continue;
            if(i==best-2){
                if(i+3<=n-1){
                    if(v[i+3] - v[i] < min_dist){
                        min_dist = v[i+3] - v[i];
                        idx1 = i;
                        idx2 = i+3;
                    }
                }
            }
            else{
                if(v[i+1] - v[i] < min_dist){
                    min_dist = v[i+1] - v[i];
                    idx1 = i;
                    idx2 = i+1;
                }
            }
        }
        if((double)min_dist/(double)2 < (double)v[best]){
            cout << v[idx1] << " " << v[idx2] << " " << v[best] << " " << v[best] << endl;
        }
        else cout << -1 << endl;

    }
}