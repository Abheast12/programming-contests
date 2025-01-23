#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int l = 0, r = 0;
        int best = -1001;
        int next;
        int cur =0;
        int parity = -1;
        while(r < n){
            if(parity == -1){
                parity = abs(v[r])%2;
                cur+=v[r];
            }
            else if(abs(v[r])%2 == parity){
                cur = v[r];
                parity = abs(v[r])%2;
            }
            else{
                cur+=v[r];
                parity = 1-parity;
            }
            if(cur > best){
                best = cur;
            }
            if(cur < 0){
                l = r+1;
                r++;
                cur = 0;
            }
            else{
                r++;
            }
        }
        cout << best << endl;
    }
}