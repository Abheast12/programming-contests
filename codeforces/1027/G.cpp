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
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        int ops = 0;
        vector<int>reductions(32, 0);
        set<int>powers;
        for(int i=1; i<32; i++){
            powers.insert(1LL << i);
        }
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            v[i] = x;
            int tmp =1;
            vector<int>fs;
            fs.push_back(tmp);
            while(x>1){
                if(x%2 == 0){
                    x/=2;
                    tmp*=2;
                    fs.push_back(tmp);
                }
            }
            ops+=tmp;
            reverse(fs.begin(), fs.end());
            for(int i=1; i<fs.size(); i++){
                reductions[i] += fs[i];
            }
            
        }
        cout << ops << endl;
        if(ops < k){
            cout << "NO" << endl;
            continue;
        }
        int dif = ops-k;
        
        for(int i=30; i>=1; i--){
            dif -= min(dif/((1LL << i)-1LL), reductions[i]) * ((1LL << i) - 1LL);
        }
        if(dif == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;


    }
}