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
    while(true){
        cout << n << " ";
        if(n == 1){
            cout << endl;
            break;
        }
        if(n % 2 == 0){
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
}