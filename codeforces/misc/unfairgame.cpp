#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int ans = 0;
        if(d%2==1){
            d--;
        }
        ans+=d/2;
        if(a%2==1 && b%2==1 && c%2==1){
            ans++;
            ans+=a/2;
            ans+=b/2;
            ans+=c/2;
        }
        else{
            if(a%2==1){
                a--;
                
            }
            if(b%2==1){
                b--;
                
            }
            if(c%2==1){
                c--;
                
            }
            ans+=a/2;
            ans+=b/2;
            ans+=c/2;
        }
        cout << ans << endl;
    }
}