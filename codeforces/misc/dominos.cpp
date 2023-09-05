#include<iostream>
using namespace std;
int n, m;
int main(){
    cin >> n >> m;
    if(m==1) cout << n-1 << endl;
    else cout << (m-1)*n << endl;
}