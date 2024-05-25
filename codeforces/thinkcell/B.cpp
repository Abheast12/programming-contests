#include<iostream>

using namespace std;

int main(){
    long long t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        // long long ans = 0;
        long long f = 1;
        long long l = n;
        for(int j=1; j<=n; j++){
            if(j!=n){
                if(j%2==1){
                    cout << f << " ";
                    f++;
                }
                else{
                    cout << l << " ";
                    l--;
                }
            }
            else{
                if(n%2==1){
                    cout << f << endl;
                }
                else{
                    cout << l << endl;
                }
            }
        }
        // cout << ans << endl;
    }
}