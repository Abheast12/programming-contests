#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, k;
        cin >> n >> k;
        long long x = 1;
        vector<long long>ans;
        
        if(k<n && ((k+1)&k!=0)) ans.push_back(k+1);
        // if(k&(k-1) == 0){
        //     if(k*2+k <= n) ans.push_back(k*2+k);
        // }
        // else{
        //     if(k<n) ans.push_back(k+1);
        // }
        while(x <= k){
            x*=2;
        }
        if(x+k <= n) ans.push_back(x+k);
        x/=2;
        long long xx =1;
        while(xx < x){
            if(k&xx){
                ans.push_back(xx);
            }
            xx*=2;
        }
        x/=2;
        long long y = 1;
        while(y <=x){
            ans.push_back(y);
            y*=2;
        }
        // if(k!=n) cout << k+1 << " ";
        y*=2;
        while(y <= n){
            ans.push_back(y);
            y*=2;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        // cout << ans[0] << " ";
        for(int j=0; j<ans.size(); j++){
            cout << ans[j] << " ";
            // if(!(ans[j]==ans[j-1] && ans[j] >= y/2)) cout << ans[j] << " ";
        }
        cout << endl;
        ans.clear();
    }
}