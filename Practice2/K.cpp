#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int a, b;
    cin >> a >> b;
    x*=60;
    int tot = 0;
    if(a+b<=x){
        x-=(a+b);
        tot++;
        tot+=(x/max(a, b));
        cout << tot << endl;
    }
    else cout << 0 << endl;
}