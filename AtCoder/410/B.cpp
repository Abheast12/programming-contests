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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;

    cin >> n >> q;
    vector<int>v(q);
    for(int i=0; i<q; i++){
        cin >> v[i];
    }
    vector<int>balls(n+1, 0);
    vector<int>ans;
    for(int i=0; i<q; i++){
   
        if(v[i] == 0){
            int mn = 1e9;
            int idx = -1;
            for(int j=1; j<=n; j++){
                if(balls[j] < mn){
                    mn = balls[j];
                    idx = j;
                }
            }
            balls[idx]++;
            ans.push_back(idx);
        }
        else{
            balls[v[i]]++;
            ans.push_back(v[i]);
        }
    }
    for(int i=0; i<q; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}