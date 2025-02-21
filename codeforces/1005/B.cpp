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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        map<int, int>mp;
        vector<int>dis(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
            mp[v[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp[v[i]] == 1){
                dis[i] = 1;
            }
        }
        int l_ans = -1;
        int r_ans = -1;
        int l =0, r=0;
        int best = 0;
        while(r < n){
            if(dis[r] == 1){
                if(r-l+1 > best){
                    best = r-l+1;
                    l_ans = l;
                    r_ans = r;
                }
                r++;
            }
            else{
                r++;
                l=r;
            }
        }
        if(l_ans != -1){
            cout << l_ans+1 << " " << r_ans+1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}