#include<iostream>
using namespace std;
int n, t, ans;
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;

        cout << "Case #" << i+1 << ": " << (n-1)/5+1 << endl;
    }
}