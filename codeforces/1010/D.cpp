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
        int inv = 0;
        int f = -1;
        int l = -1;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(i!=0 && v[i] < v[i-1]){
                inv++;
                l = i;
                if(f==-1){
                    f = i-1;
                }
            }
        }
        if(inv%2==0){
            if(v[l]-v[f] >= l-f){
                cout << inv/2 << endl;
            }
            else{
                cout << inv/2 + 1 << endl;
            }
        }
        else{
            cout << inv/2 + 1 << endl;
        }

    }
}