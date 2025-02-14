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
        int x, y;
        cin >> x >> y;
        if(y == x+1){
            cout << "YES" << endl;
        }
        else{
            int tmp = x;
            bool tt = false;
            while(tmp >= 0){
                if(tmp+1 == y){
                    tt = true;
                    break;
                }
                tmp-=9;
            }
            if(tt){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}