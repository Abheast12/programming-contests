#include<iostream>
using namespace std;
int main(){
    int n, t;
    cin >> t;
    for(int i=0; i<t; i++){
        int a;
        cin >> n;
        int tot =0;
        int prev;
        for(int j=0; j<n; j++){
            cin >> a;
            if(j==0){
                tot+=(a/120);
            }
            else{
                tot+=((a-prev)/120);
                // if(a-prev>=120)tot++;
            }
            prev = a;
            if(j==n-1){
                tot+=((1440-a)/120);
            }
        }
        if(tot>=2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}