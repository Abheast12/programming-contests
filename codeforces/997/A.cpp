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
        int n, m;
        cin >> n >> m;
        vector<int>v(n);
        // vector<vector<int>>grid(200, vector<int>(200, 0));
        long long ans =0;
        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            if(i==0) ans+=4*m;
            else{
                int val = 2*x+2*y;
                ans+=val;
            }
        }
        cout << ans << endl;
    }
}