#include<iostream>
#include<vector>
#include<set>
using namespace std;
long long choose(long long n, long long k){
    if(n==0 || n==1){
        return 1;
    }
    if(k==0 || k==n){
        return 1;
    }
    if (k > n - k) {
        k = n - k;
    }
    long long result = 1;
    for (long long i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
        result = result % (long long)(1e9+7);
    }
    return result;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        // cout << n << m1 << m2 << endl;
        vector<int>pre(m1);
        vector<int>suf(m2);
        set<int>pre_set;
        set<int>suf_set;
        bool flag = false;
        long long mod = 1e9+7;
        for(int i=0; i<m1; i++){
            cin >> pre[i];
            pre_set.insert(pre[i]);
        }
        for(int i=0; i<m2; i++){
            cin >> suf[i];
            suf_set.insert(suf[i]);
            if(pre_set.find(suf[i])!=pre_set.end() && suf[i]!=pre[m1-1]){
                // cout << 0 << endl;
                flag = true;
            }
        }
        if(pre[0]!=1 || suf[m2-1]!=n){
            flag = true;
        }
        if(pre[m1-1]!=suf[0]){
            flag = true;
        }
        if(!flag){
        for(int i=0; i<m1; i++){
            if(suf_set.find(pre[i])!=suf_set.end() && pre[i]!=suf[0]){
                flag = true;
                break;
            }
        }
        }
        // cout << "here" << endl;
        // cout << choose(5, 2)<< endl;
        if(!flag){
        long long ans = 1;
        long long tot = pre[m1-1]-1;
        for(int i=m1-2; i>=0; i--){
            long long dif = pre[i+1]-pre[i]-1;
            tot--;
            for(int j=0; j<dif; j++){
                // ans = (ans*tot)%mod;
                long long temp = 0;
                for(int k=0; k<tot; k++){
                    temp+=ans;
                    temp = temp%mod;
                }
                ans = temp;
                tot--;
            }
        }
        // cout << ans << endl;
        tot = n-suf[0];
        for(int i=1; i<m2; i++){
            long long dif = suf[i]-suf[i-1]-1;
            tot--;
            for(int j=0; j<dif; j++){
                // ans = (ans*tot)%mod;
                long long temp = 0;
                for(int k=0; k<tot; k++){
                    temp+=ans;
                    temp = temp%mod;
                }
                ans = temp;
                tot--;
            }
        }
        // cout << ans << endl;
        long long res = choose(n-1, pre[m1-1]-1);
        ans = (ans*res)%mod;
        cout << ans << endl;
        
        }
        else cout << 0 << endl;
        pre.clear();
        suf.clear();
        pre_set.clear();
        suf_set.clear();
    }
}