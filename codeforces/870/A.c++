#include<iostream>
#include<string.h>
using namespace std;
int arr[1010];
int n, t;
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            arr[a]++;
        }
        bool b = false;
        for(int j=1; j<=n; j++){
            arr[j]+=arr[j-1];
        }
        for(int j=0; j<=n; j++){
            if(j!=n){
                if(j == n-arr[j]){
                    cout << j << endl;
                    b = true;
                    break;
                }
                else if(j>n-arr[j]){
                    break;
                }
            }
        }
        if(!b) cout << -1 << endl;
        memset(arr, 0, sizeof(arr));
    }
}