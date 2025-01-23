#include<iostream>
#include<vector>
#include<numeric>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        vector<long long>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        long long g = v[0];
        for(int i=1; i<n; i++){
            g = gcd(g, v[i]);
        }
        if(n==1){
            if(v[0] <= k-1){
                cout << k << endl;
            }
            else {
                cout << k-1 << endl;
            }
        }
        else{
            long long val = g*(n-1)*(g-1)/g;
            if(val < k){
                val = k-val;
                cout << g*(n-1)+val << endl;
            }
            else{
                long long tmp = k/(g-1);
                long long rem = k%(g-1);
                if(rem !=0){
                    cout << g*tmp + rem << endl;
                }
                else{
                    cout << g*tmp-1 << endl;
                }
            }
        }
    }
}