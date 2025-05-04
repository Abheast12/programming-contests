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


int modinv()


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int md = 1e9+7;
    int gg = 1;
    for(int i=0; i<n; i++){
        gg*=26;
        gg%=md;
    }
    int val1 = 1, val2 = 1, val3 = 1;
    int tmp = 1;
    for(int i=1; i<=s.length()+n; i++){
        tmp*=i;
        tmp%=md;
        if(i == n){
            val1 = tmp;
        }
        else if(i == s.length()){
            val2 = tmp;
        }
        else if(i == s.length()+n){
            val3 = tmp;
        }
    }


}
