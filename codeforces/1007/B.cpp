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
using ll = long long;
using namespace std;  
bool check(ll n){
    ll val = ((n+1)*n)/2LL;
    val = n;
    bool flag = false;
    for(int i=2; i*i<=val; i++){
        if(i*i==val){
            // cout << -1 << endl;
            return true;
            break;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // check(100);
    // if(check(100)){
    //     cout << "YES" << endl;
    // }
    // else{
    //     cout << "NO" << endl;
    // }
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n==1){
            cout << -1 << endl;
        }
        else{
            
            
            ll val = ((n+1)*n)/2LL;
            ll x = (ll)floor(sqrt(val));
            if(x*x==val){
                cout << -1 << endl;
                continue;
            }

            vector<ll>ans;
            ans.push_back(2);
            ans.push_back(1);
            for(ll i=3; i<=n; i++){

                // ans.push_back(i+1);
                // ans.push_back(i);
                ll j =i;
                while(true){
                    ll tmp = (j*(j+1))/2LL;
                    x = (ll)floor(sqrt(tmp));
                    if(x*x == tmp){
                        j++;
                    }
                    else break;
                }
                ll tmpj = j;
                while(j>=i){
                    ans.push_back(j);
                    j--;
                }
                i = tmpj;
                // if(x*x == tmp){
                    
                //     ans.push_back(i+1);
                //     ans.push_back(i);
                //     i++;
                // }
                // else{
                //     ans.push_back(i);
                // }
            }
            // if(n%2==1){
            //     ans.push_back(n);
            // }
            for(auto x: ans){
                cout << x << " ";
            }
            cout << endl;
        }
    }
}