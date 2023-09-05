#include<numeric>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    if(a/2 > b){
        cout << -1 << endl;
        return 0;
    }
    if(a/2 == b){
        for(int i=1; i<=a; i++){
            cout << i << " ";
        }
        cout << endl;
        return 0;
    }
    if(a%2==0){
        int tot = 0;
        for(int i=1; i<=a; i++){
            if(i==a-1){
                cout << i << " " << i*(b-tot) << endl;
            }
            else{
                cout << i << " ";
                tot++;
            }
        }
    }
    else{
        int tot = 0;
        for(int i=1; i<=a; i++){
            if(i==a-2){
                cout << i << " " << i*(b-(tot/2)) << " ";
                i++;
            }
            else{
                cout << i << " ";
                tot++;
            }
        }
        cout << endl;
    }
}