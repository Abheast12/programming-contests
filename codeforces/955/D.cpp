#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<numeric>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        long long val[201][201];
        int type[201][201];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> val[i][j];
            }
        }
        long long tot0 = 0;
        long long tot1 = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         typ[i][j] = 0;
        //     }
        // }
        for(int i=0; i<n; i++){
            string s;
            cin >> s;
            // if(s.length() != m)return 0;
            for(int j=0; j<m; j++){
                // char c;
                // cin >> c;
                // int asdf = '3'-'0';
                type[i][j] = s[j]-'0';
                if(type[i][j] == 0){
                    tot0 += val[i][j];
                }
                else{
                    tot1 += val[i][j];
                }
            }
        }
        // cout << "here" << endl;
        long long dif = abs(tot0-tot1);
        int pref[501][501];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // pref[i][j] = 0;
                int tmp = 0;
                if(j>0){
                    tmp += pref[i][j-1];
                }
                if(i>0){
                    tmp += pref[i-1][j];
                }
                if(i>0 && j>0){
                    tmp -= pref[i-1][j-1];
                }
                tmp+=type[i][j];
                pref[i][j] = tmp;
            }
        }
        // cout << "here" << endl;
        vector<int>v;
        for(int i=0; i<=n-k; i++){
            for(int j=0; j<=m-k; j++){
                int tmp = pref[i+k-1][j+k-1];
                if(i>0){
                    tmp -= pref[i-1][j+k-1];
                }
                if(j>0){
                    tmp -= pref[i+k-1][j-1];
                }
                if(i>0 && j>0){
                    tmp += pref[i-1][j-1];
                }
                if(tmp !=0)v.push_back(tmp);
            }
        }
        bool g = true;
        // int gg;
        if(v.size()>0){
            int gg = v[0];
            for(int i=1; i<v.size(); i++){
                gg = gcd(gg, v[i]);
            }
            if(dif % gg == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            if(dif == 0){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        
        v.clear();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                val[i][j] = 0;
                type[i][j] = 0;
                pref[i][j] = 0;
            }
        }


    }
}