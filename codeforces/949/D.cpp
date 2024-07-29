#include<iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            if(i==1%4 || i==0%4){
                cout << 1 << " ";
            }
            else{
                cout << 2 << " ";
            }
        }
        cout << endl;
    }
    
}