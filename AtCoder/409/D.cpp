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
        int l = -1;
        for(int i=0; i<n-1; i++){
            if(s[i] > s[i+1]){
                l = i;
                break;
            }
        }
        if(l == -1){
            cout << s << endl;
            continue;
        }
        int r=n-1;
        for(int i=l+2; i<n; i++){
            if(s[i] > s[l]){
                r = i-1;
                break;
            }
        }
        string tmps = "";
        for(int i=l+1; i<=r; i++){
            tmps += s[i];
        }
        tmps+= s[l];
        string ans = s.substr(0, l) + tmps + s.substr(r+1);
        cout << ans << endl;
    }

    
}