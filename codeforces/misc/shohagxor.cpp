#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x, m;
        cin >> x >> m;
        long long ans = 0;
        if(m<=x){
            for(int i=1;i<=m; i++){
                long long xr = x^i;
                if(xr % i == 0 || xr % x == 0){
                    ans++;
                }
            }
            cout << ans << endl;
        }
        else{
            ans=1;
            for(int i=1;i<x; i++){
                long long xr = x^i;
                if(xr % i == 0 || xr % x == 0){
                    ans++;
                }
            }
            // cout << ans << endl;
            // ans+=(m/x-1);
            // cout << ans << endl;
            long long r= 1e18/x+1;
            long long l = 2;
            long long tans = 0;
            // long long over = 0;
            while(l < r){
                long long mid = (l+r)/2;
                long long xr = x^(x*mid);
                if(xr <= m){
                    // cout << xr << " " <<  x*mid << endl;
                    tans = mid - 1;
                    l = mid+1;
                }
                else{
                    r = mid;
                }
            }
            ans+=tans;
            cout << ans << endl;
        }
        
    }
}