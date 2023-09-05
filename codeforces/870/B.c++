#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

int a[101000];

bool isPalindrome(int n){
    for(int i=0; i<n/2; i++){
        if(a[i] != a[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> a[j];
        }
        bool b = false;
        if(isPalindrome(n)){
            cout << 0 << endl;
            // cout <<"here" << endl;
        }
        else{
            int dif = abs(a[n-1]-a[0]);
            for(int j=1; j<n/2; j++){
                int dif2 = abs(a[j]-a[n-j-1]);
                if(dif2!=0 && dif ==0){
                    dif = dif2;
                }
                else if(dif!=0 && dif2!=0){
                    if(dif % dif2 == 0){
                        dif = dif2;
                    }
                    if(dif%dif2 != 0 && dif2%dif !=0){
                        dif = gcd(dif, dif2);
                    }
                }
                if(dif == 1) break;
                // if(dif2 != 0 && dif%dif2 == 0){
                //     dif = dif2;
                // }
                // else if(dif == 0 && dif2 !=0){
                //     dif = dif2;
                // }
                // else if(dif!=0 && dif2 !=0 && dif2%dif != 0 && dif%dif2 !=0){
                //     cout << 1 << endl;
                //     b = true;
                //     break;
                // }
            }
            cout << dif << endl;
        }
    }
}