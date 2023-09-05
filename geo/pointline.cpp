#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long a1, a2, b1, b2, c1, c2;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
        if((b2-a2)*(c1-a1) - (b1-a1)*(c2-a2) > 0){
            cout << "RIGHT" << endl;
        }
        else if((b2-a2)*(c1-a1) - (b1-a1)*(c2-a2) < 0){
            cout << "LEFT" << endl;
        }
        else cout << "TOUCH" << endl;
    }
}