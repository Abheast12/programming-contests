#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if(b==0 && c==0 && a==1){
        cout << "YES" << endl;
        cout << 0 << endl;
    }
    else if(a>(b+c)){
        cout << "YES" << endl;
        cout << 2*(b + c)+1<< endl;
    }
    else{
        cout << "NO" << endl;
    }
}