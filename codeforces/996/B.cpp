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
        vector<int>v2(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=0; i<n; i++){
            cin >> v2[i];
        }
        int idx = -1;
        int dif = -1;
        for(int i=0; i<n; i++){
            if(v[i] < v2[i]){
                dif = v2[i] - v[i];
                idx = i;
                break;
            }
        }
        if(idx == -1){
            cout << "YES" << endl;
        }
        else{
            bool t = true;
            for(int i=0; i<n; i++){
                if(i==idx) continue;
                if(v[i]-v2[i] < dif){
                    t = false;
                    break;
                }
            }
            if(t){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
}