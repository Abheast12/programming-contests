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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int ans =0;
        int l = 0, r = n-1;
        int x = 0;
        while(l<=r){
            // cout << l << " " << r << " " << x << endl;
            if(l==r){
                int tmp = (v[l]-x)/2;
                if(2*tmp+x>=v[l]){
                    ans+=(tmp+1);
                    break;
                }
                else{
                    if(tmp+1 >= v[l]){
                        ans+=(tmp+1);
                        break;
                    }
                    ans+=(tmp+2);
                    break;
                }
                // if(x>1){
                //     ans++;
                //     v[l]-=x;
                //     if(v[l]<=0){
                //         break;
                //     }
                //     if(v[l]<=2){
                //         ans+=v[l];
                //         break;
                //     }
                //     ans+=ceil((double)v[l]/(double)2) +1;
                //     break; 
                // }
                // else if(x==1){
                //     if(v[l]<=2){
                //         ans+=v[l];
                //         break;
                //     }
                //     ans+=v[l]/2+1;
                //     break;
                // }
                // else{
                //     if(v[l]<=2){
                //         ans+=v[l];
                //         break;
                //     }
                //     ans+=ceil((double)v[l]/(double)2) + 1;
                //     break;
                // }
            }
            else{
                if(v[l] + x >= v[r]){
                    ans+=v[r]-x;
                    v[l]-=(v[r]-x);
                    ans++;
                    v[r] = 0;
                    r--;
                    x=0;
                    if(v[l] == 0){
                        l++;
                    }
                }
                else{
                    ans+=v[l];
                    x+=v[l];
                    l++;
                }
            }
        }
        cout << ans << endl;
    }
}