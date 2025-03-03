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
        int n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >>s;
        int pos = x;
        int time =0;
        for(int i=0; i<n; i++){
            if(s[i] == 'L'){
                pos--;
            }
            else pos++;
            if(pos == 0){
                time = i+1;
                break;
            }
        }
        // cout << time << endl;
        if(time > k || time == 0){
            cout << 0 << endl;
            continue;
        }
        if(time == k){
            cout << 1 << endl;
            continue;
        }
        k-=time;
        pos = 0;
        time =0;
        for(int i=0; i<n; i++){
            if(s[i] == 'L'){
                pos--;
            }
            else pos++;
            if(pos == 0){
                time = i+1;
                break;
            }
        }
        if(time > k || time == 0){
            cout << 1 << endl;
            continue;
        }
        else cout << 1 + (k/time) << endl;
    }
}