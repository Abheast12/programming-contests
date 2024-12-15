#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int val = 1e5;
    vector<bool> isPrime(val + 1, true);
    // vector<vector<int>> factors(1e6 + 1);
    vector<int>largestFactor(val+1, -1);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= val; i++) {
        if (isPrime[i]) {
            // factors[i].push_back(i);
            for (int j = i * 2; j <= val; j += i) {
                isPrime[j] = false;
                if(largestFactor[j]==-1){
                    largestFactor[j] = j/i;
                }
                // factors[j].push_back(i);
            }
        }
    }
    // cout <<"finished" << endl;

    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        // cout << t << endl;
        cin >> n>> m;
        set<int> s;
        for(int i=0; i<m; i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        
        if(n==1){
            cout << *s.begin() << endl;
            continue;
        }
        vector<int>v;
        v.insert(v.end(), s.begin(), s.end());
        sort(v.begin(), v.end());
        vector<int>dp(n+1);
        bool tt = true;
        dp[1] = v.size();
        for(int i=2; i<=n; i++){
            if(isPrime[i]){
                dp[i] = v.size()-1;
            }
            else{
                dp[i] = dp[largestFactor[i]]-1;
            }
            if(dp[i] == 0){
                    cout << -1 << endl;
                    tt = false;
                    break;
                }
        }
        if(tt){
            for(int i=1; i<=n; i++){
                cout << v[dp[i]-1] << " ";
            }
            cout << endl;
        }
        // vector<int> a(n+1);
        // bool tt = true;
        // for(int i=1; i<=n; i++){
        //     set<int>temps = s;
        //     for(int j=0; j<factors[i].size(); j++){
        //         if(temps.find(factors[i][j]) != temps.end()){
        //             temps.erase(factors[i][j]);
        //         }
        //         if(temps.size()==0){
        //             cout << -1 << endl;
        //             tt = false;
        //             break;
        //         }
        //     }
        //     if(!tt){
        //         break;
        //     }
        //     a[i] = *temps.rbegin();
        // }
        // if(tt){
        //     for(int i=1; i<=n; i++){
        //         cout << a[i] << " ";
        //     }
        //     cout << endl;
        // }



    }
}