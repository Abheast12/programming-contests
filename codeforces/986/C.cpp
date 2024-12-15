#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;
// bool check(vector<long long>&pref1, vector<long long>&pref2, vector<long long>&a, long long val, long long m){
    
    
    
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, m, v;
        cin >> n >> m >> v;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        long long sum = 0;
        vector<long long>pref2(n+1);
        pref2[n] = 0;
        for(int i=n-1; i>=0; i--){
            sum += a[i];
            pref2[i] = pref2[i+1];
            if(sum >= v){
                pref2[i]++;
                sum = 0;
            }
        }
        sum = 0;
        vector<long long>pref1(n+1);
        pref1[0] = 0;
        for(int i=0; i<n; i++){
            sum += a[i];
            if(i!=0) pref1[i] = pref1[i-1];
            if(sum >= v){
                pref1[i]++;
                sum = 0;
            }
        }
        if(pref1[n-1] < m && pref2[0] < m){
            cout << -1 << endl;
            continue;
        }


        long long ans = 0;
        int lb = 0, rb = 0;
        long long cur_val = a[0];
        while(rb < a.size()){
            long long cur_tot = 0;
            if(lb > 0){
                cur_tot+=pref1[lb-1];
            }
            cur_tot+=pref2[rb+1];
            if(cur_tot >=m){
                ans = max(ans, cur_val);
                rb++;
                cur_val+=a[rb];
            }
            else{
                cur_val-=a[lb];
                lb++;
                if(lb > rb){
                    rb++;
                    cur_val+=a[rb];
                }
            }
        }
        cout << ans << endl;
        
    }
}