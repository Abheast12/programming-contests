#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;  

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char>v(n);
        for(int i=0; i<n; i++){
            char c;
            cin >> v[i];
        }
        int ppos = -1;
        int spos = -1;
        for(int i=0; i<n; i++){
            if(v[i] == 'p'){
                ppos = i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(v[i] == 's'){
                spos = i;
                break;
            }
        }
        if(spos != -1 && ppos !=-1 && spos > ppos){
            cout << "NO" << endl;
        }
        else if(spos == -1 || ppos == -1){
            cout << "YES" << endl;
        }
        else{
            if(ppos == n-1 || spos == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}