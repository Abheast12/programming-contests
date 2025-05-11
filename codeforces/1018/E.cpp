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
        vector<int>v(n+1, 0);
        for(int i=0; i<n; i++){
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
        cout << inv/2+inv%2 << endl;
    }
}