#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if((k==1 || k==n)){
            if(n==1){
                cout << 1 << endl;
                cout << 1 << endl;
            }
            else{
                cout << -1 << endl; 
            }
        }
        else{
            if((k-1)%2==0){
                cout << 5 << endl;
                cout << 1 << " " << 2 << " " << k << " " << k+1 << " " << n << endl;
            }
            else{
                cout << 3 << endl;
                cout << 1 << " " << k << " " << k+1 << endl;
            }
        }
        // if(k == n/2+1){
        //     cout << 1 << endl;
        //     cout << 1 << endl;
        // }
        // else{
        //     cout << -1 << endl;
        // }
    }
}