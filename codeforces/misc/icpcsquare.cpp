#include<iostream>
using namespace std;

int main(){
    long long n, d, s;
    cin >> n >> d >> s;
    d/=s;
    n/=s;
    // if(d<=1){
    //     cout << s << endl;
    //     return 0;
    // }
    if(d == 0 || n==0){
        cout << s << endl;
        return 0;
    }
    if(d*2 <=n){
        // cout << "here" << endl;
        cout << d*2*s << endl;
    }
    else{
        bool t = false;
        for(long long i=2; i*i<=n; i++){
            if(n%i == 0){
                if(n-n/i <= d){
                    // cout << "here" << i << endl;
                    t = true;
                    break;
                }
                else if(n-i <= d){
                    t = true;
                    break;
                }
            }
        }
        if(t || n == 1 || n%2==0){
            cout << n*s << endl;
        }
        else{
            if(d+1<=n){
                cout << max(d+1, n-1)*s << endl;
            }
            else cout << (n-1)*s << endl;
        }
    }

}