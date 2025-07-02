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
    int l, r;
    cin >> l >> r;
    int m = 1e7;
    vector<bool> isPrime(m+1, true);
    vector<bool> mp(m+1, true);
    isPrime[0] = isPrime[1] = false;
    // vector<vector<int>> factors(m+1);
    for (int i = 2; i <= m; i++) {
        if (isPrime[i]) {
            // factors[i].push_back(i);
            for (int j = i * 2; j <= m; j += i) {
                isPrime[j] = false;
                // factors[j].push_back(i);
            }
            for(int j = i*(l/i + 1); j <= r; j += i){
                mp[j-l] = false;
            }
        }
    }
    vector<int>primes;
    for(int i=2; i<=m; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
    for(int p: primes){
        int cur = 1;
        while(cur <= r){
            if(cur>=l){
                mp[cur-l] = true;
            }
            cur *= p;
        }
    }
    int ans =0;
    for(int i=0; i<=r-l; i++){
        if(mp[i]){
            ans++;
        }
    }
    cout << ans << endl;
    

}