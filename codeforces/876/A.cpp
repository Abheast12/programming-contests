#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, t, k;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> k;
        if(k==1){
            cout << n << endl;
        }
        else if(ceil((double)n/(double)k) == ceil(((double)(n-1))/(double)k)){
            cout << ceil((double)n/(double)k) + 1 << endl;
        }
        else cout << ceil((double)n/(double)k) << endl;
    }
}