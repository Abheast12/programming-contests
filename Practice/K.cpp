#include<iostream>
#include<algorithm>
using namespace std;


int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 20000;
    for(int i=0; i<4; i++){
        int ab;
        bool t = false;
        if(i==0){
            t = true;
            ab = a+b;
        }
        else if(i==1){
            t = true;
            ab = a-b;
        }
        else if(i==2){
            t= true;
            ab = a*b;
        }
        else{
            if(b!=0 && a%b==0){
                t = true;
                ab = a/b;
            }
        }
        if(t){
            int bc;
            for(int j=0; j<4; j++){
                if(j==0){ 
                    bc = ab+c;
                }
                else if(j==1){
                    // t = true;
                    bc = ab-c;
                }
                else if(j==2){
                    // t= true;
                    bc = ab*c;
                }
                else{
                    if(c!=0 && ab%c==0){
                        // t = true;
                        bc = ab/c;
                    }
                }
                if(bc>=0) ans = min(ans, bc);
            }
        }
    }
    cout << ans << endl;
}