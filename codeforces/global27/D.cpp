#include<iostream>
#include<vector>
#include<stack>
#include<map>
using namespace std;
inline long long getbase(long long n){
    int ct = 0;
    while(n%2==0){
        ct++;
        n/=2;
    }
    return ct;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>a(n);
        vector<pair<long long, long long>>peaks;
        vector<pair<long long, long long>>bases(n);
        peaks.reserve(n+15);
        for(int i=0; i<n; i++){
            cin >>a[i];
            long long base = getbase(a[i]);
            bases[i] = {a[i]/(1<<base), base};
        }
        vector<long long> ans(n);
        // map<long long, long long>bases;
        ans[0] = a[0];
        peaks.push_back(bases[0]);
        long long sum = a[0];
        long long mod = 1e9+7;
        for(int i=1; i<n; i++){
            pair<long long, long long> newa = bases[i];
            while(!peaks.empty()){
                pair<long long, long long> back = peaks.back();             
                if(newa.second >= 32 || back.first < newa.first*(1<<newa.second)){
                    newa.second+=back.second;
                    long long base = 1;
                    long long p = 2;
                    long long exp = back.second;
                    while(exp){
                        if(exp%2){
                            base*=p;
                            base%=mod;
                        }
                        p*=p;
                        p%=mod;
                        exp/=2;
                    }
                    base = (base*back.first)%mod;
                    sum = (sum-base+mod)%mod;
                    sum = (sum+back.first)%mod;
                    peaks.pop_back();
                }
                else{
                    break;
                }
            }
            peaks.push_back(newa);
            long long base = 1;
            long long p = 2;
            long long exp = newa.second;
            while(exp){
                if(exp%2){
                    base*=p;
                    base%=mod;
                }
                p*=p;
                p%=mod;
                exp/=2;
            }
            base = (base*newa.first)%mod;
            sum = (sum+base)%mod;
            ans[i] = sum;
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        
    }
}