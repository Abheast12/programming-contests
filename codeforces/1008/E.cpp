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
    int val1 = 0, val2 = 0;
    for(int i=0; i<=29; i++){
        int tmp = 1<<i;
        if(i%2==0){
            val1+=tmp;
        }
        else{
            val2+=tmp;
        }
    }
    while(t--){
        int x, y;
        int sum1, sum2;
        cout << val1 << endl;
        cout.flush();
        cin >> sum1;
        cout << val2 << endl;
        cout.flush();
        cin >> sum2;
        
    }
}