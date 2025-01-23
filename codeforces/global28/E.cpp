#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(m<=2*n-1){
            
            cout << "YES" << endl;
            vector<int>v(2*n);
            for(int i=0; i<2*n; i++){
                v[i] = i/2+1;
            }
            for(int i=0; i<2*n; i++){
                for(int j=i; j<i+m; j++){
                    cout << v[j%(2*n)] << " ";
                }
                cout << endl;
            }
        }
        else cout << "NO" << endl;
    }
}