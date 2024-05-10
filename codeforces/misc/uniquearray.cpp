#include<iostream>
#include<set>
using namespace std;

int main(){
    int t, n;
    int a[300200];
    int b[300200];
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        set<int>s;
        for(int j=0; j<n; j++){
            cin >> a[j];
            if(s.find(a[j])==s.end()){
                s.insert(a[j]);
                b[j] = 1;
            }
            else{
                b[j] = -1;
            }
        }
        

    }
}