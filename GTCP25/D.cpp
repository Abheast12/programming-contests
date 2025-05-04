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
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        bool cc = false; 
        vector<int>mx(n+1);
        for(int i=0; i<n-1; i++){
            bool c1 = false;
            bool c2 = false;
            
            for(int j=i+1; j<n; j++){
                if(v[j] > v[i]){
                    c1 = true;
                    mx[v[i]] = max(mx[v[i]], v[j]);
                }
                if(v[j] < v[i]){
                    c2 = true;
                }
                if(c1 && c2){
                    cc = true;
                    break;
                    
                }
            }
            if(cc) break;
        }
        if(cc){
            cout << -1 << endl;
        }
        else{
            // for(int i=0; i<n; i++){
            //     cout << v[i] << " " ;
            // }
            // for(int i=0; i<n; i++){
            //     cout << n-v[i]+1 << " ";
            // }
            
            cout << endl;
        }
    }
}