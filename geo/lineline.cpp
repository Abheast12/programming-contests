#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long a1, a2, b1, b2, c1, c2, d1, d2;
        cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
        long long p1, p2, p3, p4;
        p1 = (b2-a2)*(c1-a1) - (b1-a1)*(c2-a2);
        p2 = (b2-a2)*(d1-a1) - (b1-a1)*(d2-a2);
        p3 = (d2-c2)*(b1-c1) - (d1-c1)*(b2-c2);
        p4 = (d2-c2)*(a1-c1) - (d1-c1)*(a2-c2);
        if(p1 == 0){
            if((p3 > 0 && !(p4>0)) || (p4 > 0 && !(p3>0))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if(p2 == 0){
            if((p3 > 0 && !(p4>0)) || (p4 > 0 && !(p3>0))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if(p3 == 0){
            if((p2 > 0 && !(p1>0)) || (p1 > 0 && !(p2>0))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if(p4 == 0){
            if((p2 > 0 && !(p1>0)) || (p1 > 0 && !(p2>0))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else if((p2 > 0 && !(p1>0)) || (p1 > 0 && !(p2>0))){
            if((p3 > 0 && !(p4>0)) || (p4 > 0 && !(p3>0))){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
    }
}