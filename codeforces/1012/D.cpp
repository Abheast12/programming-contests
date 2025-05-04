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
    int m = 1e6;
    vector<bool> isPrime(m+1, true);
    isPrime[0] = isPrime[1] = false;
    // vector<vector<int>> factors(m+1);
    vector<int>primes;
    for (int i = 2; i <= m; i++) {
        if (isPrime[i]) {
            // factors[i].push_back(i);
            primes.push_back(i);
            for (int j = i * 2; j <= m; j += i) {
                isPrime[j] = false;
                // factors[j].push_back(i);
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // vector<int>v(n);
        // for(int i=0; i<n; i++){
        //     cin >> v[i];
        // }
        set<int>s;
        for(int i=1; i<=n; i++){
            s.insert(i);
        }
        int tot = 0;
        int cur = 0;
        vector<int>ans;
        for(int i=1; i<=n; i++){
            while(cur < primes.size()){
                // cout << i <<  " " << cur << endl;
                auto it = lower_bound(s.begin(), s.end(), primes[cur]*i-tot);
                if(it == s.end()){
                    cur++;
                    continue;
                }
                double x = tot+*it;
                x/=(double)i;
                if(isPrime[(int)ceil(x)]){
                    // cout << *it << endl;
                    ans.push_back(*it);
                    tot+=*it;
                    // cout << "hi" << endl;
                    s.erase(it);
                    
                    break;
                }
                cur++;
            }
            // cout << "here" << endl;
        }
        if(!s.empty()){
            for(int p : s){
                ans.push_back(p);
            }
        }
        
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}