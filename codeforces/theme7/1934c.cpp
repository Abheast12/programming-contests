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
        int n, m;
        cin >> n >> m;
        // int res1, res2, res3, res4;
        vector<int>res;
        cout << "? " << 1 << " " << 1 << endl;
        cout.flush();
        int d1;
        cin >> d1;
        int y1 = min(d1+1, n);
        int x1 = d1-y1+2;
        cout << "? " << y1 << " " << x1 << endl;
        cout.flush();
        int d2;
        cin >> d2;
        int x2 = min(d1+1, m);
        int y2 = d1-x2+2;
        cout << "? " << y2 << " " << x2 << endl;
        cout.flush();
        int d3;
        cin >> d3;
        int val;
        cout << "? " << y1-d2/2 << " " << x1+d2/2 << endl;
        cout.flush();
        cin >> val;
        if(val == 0){
            cout << "! " << y1-d2/2 << " " << x1+d2/2 << endl;
        }
        else{
            cout << "! " << y2+d3/2 << " " << x2-d3/2 << endl;
        }
        // cout << "? " << x+1 << " " << 1 << endl;
        // cout.flush();
        // cin >> x3;
        // int val1 = (2+x3)/2;
        // int val2 = x-((2+x3)/2-1)+1;
        // cout << "? " << val2 << " " << val1 << endl;
        // cout.flush();
        // int x4;
        // cin >> x4;
        // if(x4 == 0){
        //     cout << "! " << val2 << " " << val1 << endl;
        //     cout.flush();
        // }
        // else{

        //     int val1 = (2+x2)/2;
        //     int val2 = x-((2+x2)/2-1)+1;
        //     cout << "! " << val1 << " " << val2 << endl;
        //     cout.flush();
        // }
        // res.push_back(x);
        // cout << "? " << 1 << " " << m << endl;
        // cout.flush();
        // cin >> x;
        // res.push_back(x);
        // cout << "? " << n << " " << m << endl;
        // cout.flush();
        // cin >> x;
        // res.push_back(x);
        // cout << "? " << n << " " << 1 << endl;
        // cout.flush();
        // cin >> x;
        // res.push_back(x);
        
        // for(int i=0; i<4; i++){
        //     int l = (i+3)%4;
        //     int r = (i+1)%4;
        //     int dist = res[i]+res[l];
        //     if(i==2){
        //         int val = 2*m+n-1-dist;
        //         if(val < 0 || val%2!=0){
        //             continue;
        //         }
        //         int b = val/2;

        //     }
        // }


    }
}