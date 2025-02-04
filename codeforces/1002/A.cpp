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
        vector<int>a(n);
        vector<int>b(n);
        set<int>s1;
        set<int>s2;
        for(int i=0; i<n; i++){
            cin >> a[i];
            s1.insert(a[i]);
        }
        for(int i=0; i<n; i++){
            cin >> b[i];
            s2.insert(b[i]);
        }
        if(s1.size() == 1){
            if(s2.size() <= 2){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
        else if(s2.size() == 1){
            if(s1.size() <= 2){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
        else{
            cout << "YES" << endl;
        }
    }
}