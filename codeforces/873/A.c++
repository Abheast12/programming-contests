#include<iostream>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        if(n%2==0){
            for(int j=1; j<n; j++){
                cout << 2*j << " ";
            }
            cout << 2*n << endl;
        }
        else{
            for(int j=1; j<n; j++){
                cout << j << " ";
            }
            cout << n << endl;
        }
    }
}