#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    long long n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        long long mx = 0;
        // if(n==6) while(1);
        for(long long i=1; i<=n; i++){
            cout << "? 1 " << i*n << endl;
            cout << flush;
            long long ans;
            cin >> ans;
            if(ans==n){
                mx = i;
                break;
            }
        }
        // if(mx ==0) while(1);
        long long best = -1;
        for(long long i=1; i<=n/k; i++){
            
            long long cur = 1;
            for(int j=1; j<=k; j++){
                cout << "? " << cur << " " << i*mx << endl;
                cout << flush;
                long long ans;
                cin >> ans;
                if(ans == n){
                    if(j == k){
                        best = i*mx;
                    }
                    break;
                }

                if(ans == n+1){
                    break;
                }
                else{
                    cur = ans+1;
                }
            }
        }
        cout << "! " << best << endl;
        cout << flush;
        long long res;
        cin >> res;
        if(res == -1) break;
    }
}