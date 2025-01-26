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
        string s;
        cin >> s;
        int m; 
        cin >> m;
        string l, r;
        cin >> l;
        cin >> r;
        set<int>st[10];
        for(int i=0; i<s.length(); i++){
            st[s[i]-'0'].insert(i);
        }
        int cur = -1;
        bool flag = false;
        for(int i=0; i<m; i++){
            int l1 = l[i]-'0';
            int r1 = r[i]-'0';
            int gg =-1;
            // cout << cur << endl;
            for(int j=l1; j<=r1; j++){
                auto it = lower_bound(st[j].begin(), st[j].end(), cur+1);
                gg = max(gg, *it);
                if(it == st[j].end()){
                    flag = true;
                    break;
                }
            }
            cur = gg;
            if(flag){
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}