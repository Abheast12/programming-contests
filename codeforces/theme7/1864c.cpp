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
        vector<int>ans;
        ans.push_back(n);
        while(n>=1){
            if(n==1){
                // ans.push_back(1);
                break;
            }
            int ct = __builtin_popcount(n);
            if(ct == 1){
                n/=2;
                ans.push_back(n);
            }
            else{
                int lsb = n&-n;
                n-=lsb;
                ans.push_back(n);
            }
        }
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;

    }
}