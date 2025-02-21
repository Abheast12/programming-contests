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
        string s;
        cin >> s;
        int ans = 0;
        bool streak = false;
        int ct = 0;
        int st = 0;
        bool here = false;
        for(int i=0; i<n; i++){
            
            if(s[i] == '1'){
                st = i;
                here = true;
                break;
            }
        }
        if(!here){
            cout << 0 << endl;
            continue;
        }
        for(int i=st; i<n; i++){
            if(s[i] == '0'){
                if(!streak){
                    ct++;
                    streak = true;
                }
            }
            else{
                if(streak){
                    streak = false;
                }
            }
        }
        if(ct == 0){
            cout << 1 << endl;
        }
        else{
            ans = ct*2;
            if(s[n-1] == '1'){
                ans++;
            }
            cout << ans << endl;
        }
    }
}