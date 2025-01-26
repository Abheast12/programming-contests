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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int best = 1e18;
        for(int i=0; i<n-1; i++){
            int gg = -1;
            for(int j=0; j<n; j++){
                int si;
                if(j == i+1) continue;
                if(j==i){
                    si = stoi(s.substr(j, 2));
                }
                else si = s[j]-'0';
                if(gg==-1){
                    gg = si;
                }
                else{
                    if(si*gg <= si+gg){
                        gg = si*gg;
                    }
                    else{
                        gg = si+gg;
                    }
                }
            }
            best = min(best, gg);
        }
        cout << best << endl;
    }
}