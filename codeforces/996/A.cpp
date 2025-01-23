#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        int dif = abs(a-b)-1;
        if(dif%2==1){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}