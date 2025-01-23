#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        long long tmp = n;
        long long ct = 0;
        long long div = 1;
        while(tmp >= k){
            if(tmp%2==1){
                ct+=div;
            }
            tmp /= 2;
            div*=2;
        }
        long long ans = (n+1)*ct/2;
        cout << ans << endl;

    }
}