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
        int n, c;
        cin >> n >> c;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<pair<int, int>>dif;
        for(int i=2; i<=n; i++){
            dif.push_back({i*c-v[i], i});
        }
        sort(dif.begin(), dif.end());
        int sum = v[1];
        bool flag = false;
        for(int i=0; i<dif.size(); i++){
            if(dif[i].first <= sum){
                sum+=v[dif[i].second];
            }
            else{
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
        // bool flag = false;

        // while(dif.size() > 0){
        //     // cout << sum << endl;
        //     auto it = lower_bound(dif.begin(), dif.end(), make_pair(sum, (long long)1e9));
        //     // cout << it->first << " " << it->second << endl;
        //     if(it==dif.end()){
        //         cout << "Yes" << endl;
        //         flag = true;
        //         break;
        //     }
        //     if(it == dif.begin() && it->first > sum){
        //         cout << "No" << endl;
        //         flag = true;
        //         break;
        //     }
        //     if(it->first > sum){
        //         it--;
        //     }
        //     int idx = distance(dif.begin(), it);
        //     // cout << idx << endl;
        //     for(int i=idx; i>=0; i--){
        //         sum+=v[dif[i].second];
        //     }
        //     dif.erase(dif.begin(), dif.begin()+idx+1);
        // }
        // if(!flag){
        //     cout << "Yes" << endl;
        // }
    }
}