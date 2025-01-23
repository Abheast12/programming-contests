#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;
long long get_inverse(long long x){
    long long mod = 998244353;
    long long ans = 1;
    long long exp = mod-2;
    long long base = x;
    while(exp){
        if(exp%2==1){
            ans = (ans*base)%mod;
        }
        base = (base*base)%mod;
        exp/=2;
    }
    return ans;
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); std::cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        long long n, q;
        cin >> n >> q;
        long long mod = 998244353;

        vector<long long> a(n);
        vector<pair<long long, long long>>a2(n);
        vector<long long> b(n);
        vector<pair<long long, long long>>b2(n);
        map<long long, long long> apos;
        map<long long, long long> bpos;
        for(long long i=0; i<n; i++){
            cin >> a[i];
            a2[i] = {a[i], i};
        }
        for(long long i=0; i<n; i++){
            cin >> b[i];
            b2[i] = {b[i], i};
        }
        sort(a2.begin(), a2.end());
        sort(b2.begin(), b2.end());
        long long ans = 1;
        for(int i=0; i<n; i++){
            apos[a2[i].second] = i;
            bpos[b2[i].second] = i;
            ans = (ans * min(a2[i].first, b2[i].first))%mod;
        }
        cout << ans << " ";
        for(int i=0;i<q; i++){
            long long o, x;
            cin >> o >> x;
            x--;
            if(o==1){
                long long old = a[x];
                long long oldposa = apos[x];
                long long prev_min = min(a2[oldposa].first, b2[oldposa].first);
                auto it = upper_bound(a2.begin(), a2.end(), make_pair(old, n+1));
                
                it--;
                long long newposa = distance(a2.begin(), it);
                a2[oldposa].first = old+1;
                a[x] = old+1;
                long long new_min;
                long long new_min2 = 1;
                long long prev_min2 = 1;
                if(newposa != oldposa){
                   
                    prev_min2 = min(a2[newposa].first, b2[newposa].first);
                    swap(a2[oldposa], a2[newposa]);
                    apos[x] = newposa;
                    apos[a2[oldposa].second] = oldposa;
                    new_min = min(a2[oldposa].first, b2[oldposa].first);
                    new_min2 = min(a2[newposa].first, b2[newposa].first);
                }
                else{
                    new_min = min(a2[oldposa].first, b2[oldposa].first);
                }
                long long tmp1 = (prev_min*prev_min2)%mod;
                tmp1 = get_inverse(tmp1);
                long long tmp2 = (new_min*new_min2)%mod;
                long long tmp = (tmp1*tmp2)%mod;
                ans = (ans*tmp)%mod;
                
            }
            else{
                long long old = b[x];
                long long oldposb = bpos[x];
                long long prev_min = min(a2[oldposb].first, b2[oldposb].first);
                auto it = upper_bound(b2.begin(), b2.end(), make_pair(old, n+1));
            
                it--;
                long long newposb = distance(b2.begin(), it);
                b2[oldposb].first = old+1;
                b[x] = old+1;
                long long new_min;
                long long new_min2 = 1;
                long long prev_min2 = 1;
                if(newposb != oldposb){
                    // cout  << "here" << endl;
                    // cout << oldposb << " " << newposb << endl;
                    prev_min2 = min(a2[newposb].first, b2[newposb].first);
                    swap(b2[oldposb], b2[newposb]);
                    bpos[x] = newposb;
                    bpos[b2[oldposb].second] = oldposb;
                    new_min = min(a2[oldposb].first, b2[oldposb].first);
                    new_min2 = min(a2[newposb].first, b2[newposb].first);
                    
                }
                else{
                    new_min = min(a2[oldposb].first, b2[oldposb].first);
                }
                long long tmp1 = (prev_min*prev_min2)%mod;
                tmp1 = get_inverse(tmp1);
                long long tmp2 = (new_min*new_min2)%mod;
                long long tmp = (tmp1*tmp2)%mod;
                ans = (ans*tmp)%mod;
                
            }
            // cout << "vector: " << endl;
            // for(int i=0; i<n; i++){
            //     cout << a2[i].first << " " << b2[i].first << endl;
            // }
            // cout << endl;
            cout << ans << " ";
        }
        cout << endl;

    }
}