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
        int n, k;
        cin >> n >> k;
        vector<int>ans(n);
        if(k%2==0){
            for(int i=0; i<n; i++){
                if(i==n-2){
                    ans[i] = n;
                    continue;
                }
                ans[i] = n-1;
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(i == n-1){
                    ans[i] = n-1;
                    continue;
                }
                ans[i] = n;
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}