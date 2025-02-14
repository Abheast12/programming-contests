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
        for(int i=0; i<n; i++){
            cin >> v[i];
            mp[v[i]]++;
        }
        
        sort(v.begin(), v.end());
        int tmp = v[0];
        bool gg = false;
        map<int, int>mp2;
        // cout << mp[1] << endl;
        while(tmp <=v[n-1]+1000){
            // cout << tmp << endl;
            if(mp[tmp] == 0){
                tmp++;
                continue;
            }
            mp2[tmp]++;
            mp[tmp]--;
            // cout << mp[tmp] << endl;
            if(mp[tmp] == 0){
                gg = true;
                cout << "NO" << endl;
                break;
            }
            mp[tmp+1]+=(mp[tmp]-1);
            mp[tmp] = 1;
            tmp++;
            // if(mp[tmp]%2==1){
            //     bool tt = false;
            //     for(int i=tmp-1; i>0; i--){
            //         if(mp[i]-1 >= tmp-i){
            //             tt = true;
            //             for(int j=i+1; j<=tmp; j++){
            //                 mp[j]++;
            //             }
            //             mp[i]-=(tmp-i);
            //             break;
            //         }
            //     }
            //     if(!tt){
            //         gg = true;
            //         cout << "NO" << endl;
            //         break;
            //     }
            // }
            // tmp--;
        }
        if(!gg){
            cout << "YES" << endl;
        }
    }
}