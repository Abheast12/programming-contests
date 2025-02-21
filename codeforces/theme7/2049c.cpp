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
        //asdf
        int n, x, y;
        cin >> n >> x >> y;
        if(n%2==0 && (y-x-1)%2==0){
            for(int i=0; i<n; i++){
                cout << i%2 << " ";
            }
            cout << endl;
        }
        else{
            x--, y--;
            int st = x;
            vector<int>ans(n);
            ans[st] = 2;
            int prev = 0;
            for(int i=st+1; i<n+st; i++){
                ans[i%n] = prev;
                prev = 1-prev;
            }
            for(int i=0; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
}