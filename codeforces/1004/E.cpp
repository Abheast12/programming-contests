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
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        vector<int>v2;
        int idx =-1;
        bool seen = false;
        for(int i=0; i<n; i++){
            if(v[i] != 0){
                v2.push_back(v[i]);
            }
            else{
                if(!seen){
                    idx = i;
                    v2.push_back(0);
                    seen = true;
                }
            }
        }
        vector<int>mn(v2.size());
        vector<int>mx(v2.size());
        set<int>s;
        for(int i=0; i<=n+1; i++){
            s.insert(i);
        }
        for(int i=v2.size()-1; i>=0; i--){
            s.erase(v2[i]);
            mx[i] = *s.begin();
        }
        bool ok = true;
        for(int i=0; i<idx; i++){
            if(i==0){
                mn[i] = v[i];
            }
            else{
                mn[i] = min(mn[i-1], v[i]);
            }
            if(mn[i] < mx[i+1]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << v2.size() << endl;
        }
        else{
            cout << v2.size()-1 << endl;
        }


    }
}