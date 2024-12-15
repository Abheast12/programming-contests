#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        // vector<vector<int>>difs(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        bool tt=false;
        int idx = -1;
        for(int i=0;i<n;i++){
            bool t = false;
            for(int j=0;j<n;j++){
                if(i!=j){
                    // difs[i].push_back(abs(v[i]-v[j]));
                    if(abs(v[i]-v[j])%k==0){
                        t = true;
                        break;
                    }
                }
            }
            if(!t){
                tt = true;
                idx = i+1;
                break;
            }
        }
        if(tt){
            cout << "YES" << endl;
            cout << idx << endl;
        }
        else cout << "NO" << endl;
    }
}