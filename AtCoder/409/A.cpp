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
    int n;
    cin >> n;
    string a, t;
    cin >> a >> t;
    for(int i=0; i<n; i++){
        if(a[i] == 'o' && t[i] == 'o'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}