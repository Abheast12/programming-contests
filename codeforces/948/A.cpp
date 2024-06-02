#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n%2 == m%2 && n>=m){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}