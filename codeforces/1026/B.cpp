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
        string s;
        cin >> s;
        bool ok = false;
        bool ans = true;
        int val  =0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                val++;
            }
            else{
                val--;
            }
            if(val == 0 && i != s.size()-1){
                ans = false;
                break;
            }
        }
        if(!ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}