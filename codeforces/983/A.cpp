#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ones = 0;
        for(int i=0; i<2*n; i++){
            int a;
            cin >> a;
            if(a==1){
                ones++;
            }
        }
        int mn, mx;
        mn = ones%2;
        if(ones <= n){
            mx = ones;
        }
        else{
            mx = n-(ones-n);
        }
        cout << mn << " " << mx << endl;
    }
}