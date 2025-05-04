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
        vector<int>v(n);
        int mx = n;
        int mn = 1;
        for(int i=n-1; i>=1; i--){
            if(s[i-1] == '>'){
                v[i] = mx;
                mx--;
            }
            else{
                v[i] = mn;
                mn++;
            }
        }
        v[0] = mn;
        for(int i=0; i<n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}