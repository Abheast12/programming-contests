#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        v[n-2] = 1;
        v[n-1] = 2;
        int x =3;
        for(int i=3; i<n-2; i++){
            v[i] = x;
            x++;
        }
        for(int i=0; i<n; i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}