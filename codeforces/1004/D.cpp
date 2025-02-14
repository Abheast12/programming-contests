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
        if(n==-1){
            return 0;
        }
        vector<int>v(n);
        set<int>s;
        for(int i=0; i<n; i++){
            cin >> v[i];
            s.insert(v[i]);
        }
        bool tt = false;
        int tmp = -1;
        for(int i=1; i<=n; i++){
            if(s.find(i)==s.end()){
                tmp = i;
                tt = true;
                break;
            }
        }
        if(tt){
            int f = v[0];
            int ff = -1;
            for(int i=1; i<n; i++){
                if(v[i] != f){
                    ff = v[i];
                    break;
                }
            }
            cout << "? " << tmp << " " << f << endl;
            cout.flush();
            int x;
            cin >> x;
            cout << "? " << tmp << " " << ff << endl;
            cout.flush();
            int xx;
            cin >> xx;
            if(x == 0 && xx == 0){
                cout << "! A" << endl;
            }
            else{
                cout << "! B" << endl;
            }
            cout.flush();
        }
        else{
            int l, r;
            for(int i=0; i<n; i++){
                if(v[i] == 1){
                    l = i;
                }
                if(v[i] == n){
                    r = i;
                }
            }
            cout << "? " << l+1 << " " << r+1 << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x<n-1){
                cout << "! A" << endl;
            }
            else{
                cout << "? " << r+1 << " " << l+1 << endl;
                cout.flush();
                int xx;
                cin >> xx;
                if(xx == x){
                    cout << "! B" << endl;
                }
                else{
                    cout << "! A" << endl;
                }
                cout.flush();
            }
            // random_device rd;
            // mt19937 gen(rd());
            // uniform_int_distribution<> dis(0, n - 1);
            // int x;
            // bool gg = false;
            // int prevr1, prevr2;
            // while(true){
            //     int r1 = dis(gen);
            //     int r2 = dis(gen);
            //     if(r1 == r2){
            //         continue;
            //     }
            //     prevr1 = r1;
            //     prevr2 =r2;
            //     cout << "? " << r1+1 << " " << r2+1 << endl;
            //     cout.flush();
                
            //     cin >> x;
            //     if(x < abs(v[r1]-v[r2])){
            //         cout << "! A" << endl;
            //         cout.flush();
            //         gg = true;
            //     }
            //     break;
            // }
            // if(!gg){
            //     while(true){
            //         int r1 = dis(gen);
            //         int r2 = dis(gen);
            //         if(r1 == r2  || (r1 == prevr1 && r2 == prevr2)){
            //             continue;
            //         }
            //         cout << "? " << r1+1 << " " << r2+1 << endl;
            //         cout.flush();
                    
            //         cin >> x;
            //         if(x < abs(v[r1]-v[r2])){
            //             cout << "! A" << endl;
            //             cout.flush();
            //             gg = true;
            //         }
            //         break;
            //     }
            //     if(!gg){
            //         cout << "! B" << endl;
            //         cout.flush();
            //     }
            // }
            
            
        }
    }
}