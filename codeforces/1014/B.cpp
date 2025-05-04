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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        int ct1 = 0;
        int ct2 = 0;
        int val1 =0;
        int val2 =0 ;
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                if(a[i] == '0'){
                    ct1++;
                }
                if(b[i] == '0'){
                    ct2++;
                }
                val1++;
            }
            if(i%2==1){
                if(a[i] == '0'){
                    ct2++;
                }
                if(b[i] == '0'){
                    ct1++;
                }
                val2++;
            }
        }
        if(ct1 >= val1 && ct2 >= val2){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        
    }
}