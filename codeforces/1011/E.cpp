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
    // cout << 3%1 << endl;
    cin >> t;
    int ct =0;
    while(t--){
        ct++;
        int n;
        cin >> n;
        // if(ct == 503){
        //     cout << n << ";";
        // }
        vector<int>v1(n);
        vector<int>v2(n);
        for(int i=0; i<n; i++){
            cin >> v1[i];
            // if(ct == 503){
            //     cout << v1[i] << ";";
            // }
        }
        
        int mx = 0;
        for(int i=0; i<n; i++){
            cin >> v2[i];
            mx = max(mx, v2[i]);
            // if(ct == 503){
            //     cout << v2[i] << ";";
            // }
        }
        int diff =0;
        for(int i=0; i<n; i++){
            diff += v1[i] - v2[i];
        }
        if(diff == 0){
            // if(ct==503){
            //     cout << 1e12 << endl;
            //     continue;
            // }
            sort(v1.begin(), v1.end());
            sort(v2.begin(), v2.end());
            if(v1 == v2){
                cout << mx+1 << endl;
            }
            else{
                cout << -1 << endl;
            }
            continue;
        }
        if(diff < 0){
            cout << -1 << endl;
            continue;
        }
        vector<int>factors;
        factors.push_back(1);
        factors.push_back(diff);
        if(diff%2==0){
            factors.push_back(2);
            factors.push_back(diff/2);
        }
        if(diff%3==0){
            factors.push_back(3);
            factors.push_back(diff/3);
        }
        for(int i=4; i*i<=diff; i++){
            if(diff%i == 0){
                factors.push_back(i);
                if(i != diff/i){
                    factors.push_back(diff/i);
                }
            }
        }
        // if(diff%2 == 0)
        vector<int>v3 = v2;
        sort(v3.begin(), v3.end());
        
        bool flag = false;
        for(int f : factors){
            // cout << f << endl;
            vector<int>v4(n);
            for(int i=0; i<n; i++){
                v4[i] = v1[i]%f;
            }
            sort(v4.begin(), v4.end());
            if(v3 == v4){
                cout << f << endl;
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << -1 << endl;
        }
    }
}