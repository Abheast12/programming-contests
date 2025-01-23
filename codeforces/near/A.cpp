#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        vector<long long> v(n);
        for(long long i=0; i<n; i++){
            cin >> v[i];
        }
        bool t = false;
        for(long long i=1; i<n; i++){
            long long a = v[i-1];
            long long b = v[i];
            if(a>b){
                swap(a, b);
            }
            if(2*a>b){
                t = true;
                break;
            }
        }
        if(t) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}