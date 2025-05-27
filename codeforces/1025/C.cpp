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
        cout << "mul 999999999" << endl;
        cout.flush();
        int x;
        cin >> x;
        if(x == -1){
            return 0;
        }
        cout << "digit" << endl;
        cout.flush();
        cin >> x;
        if(x == -1){
            return 0;
        }
        // cout << "digit" << endl;
        // cout.flush();
        // cin >> x;
        // if(x == -1){
        //     return 0;
        // }
        if(n==81){
            cout << "!" << endl;
            cout.flush();
            cin >> x;
            if(x == -1){
                return 0;
            }
            continue;
        }
        cout << "add " << n-81 << endl;
        cout.flush();
        cin >> x;
        if(x == -1){
            return 0;
        }
        cout << "!" << endl;
        cout.flush();
        cin >> x;
        if(x == -1){
            return 0;
        }
    }
}