#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n, k;
        cin >> n >> k;
        long long a = 2*(2*n-2);
        if(a>=k){
            if(k%2==0){
                cout << k/2 << endl;
            }
            else{
                cout << k/2 + 1 << endl;
            }
        }
        else{
            long long ans = k-a + 2*n-2;
            cout << ans << endl;
        }
    }
}