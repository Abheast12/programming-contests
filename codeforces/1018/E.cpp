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
#include<stack>
#define int long long
using namespace std;  

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // int val = 0;
    while(t--){
        // val++;
        int n;
        cin >> n;
        string s;
        cin >> s;
        // if(val==43) cout << s << endl;
        // stack<char>st;
        // int bs = 0;
        vector<int>v(n+1, 0);
        // for(int i=0; i<n; i++){
        //     st.push(s[i]);
        // }
        // bool flag = true;
        // if(s[s.length()-1] == 'P'){
        //     flag = false;
        // // }
        // int ans =0;
        // while(!st.empty()){
        //     while(!st.empty() && st.top() == 'B'){
        //         bs++;
        //         st.pop();
        //     }
        //     int ps = 0;
        //     while(!st.empty() && st.top() == 'P'){
        //         ps++;
        //         st.pop();
        //     }
        //     ans+=(bs*ps+1)/2;
        // }
        // cout << ans << endl;

        int bs = 0;
        int bso = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'B'){
                bs++;
            }
            if(i%2==1 && s[i] == 'B'){
                bso++;
            }
            if(s[i]=='P'){
                v[i+1] = v[i]+1;
            }
            else{
                v[i+1] = v[i];
            }
        }
        int inv = 0;
        for(int i=0; i<n; i++){
            if(s[i] == 'B'){
                inv += v[i+1];
            }
        }
        int d =abs(bs/2-bso);
        cout << (inv+d)/2 << endl;
        // cout << inv/2+inv%2 << endl;
    }
}