#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    if(s == string(s.rbegin(), s.rend())){
        for(int i=1; i<n; i++){
            if(s[i]!=s[i-1]){
                cout << n-1 << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    }
    else cout << n << endl;
    
}