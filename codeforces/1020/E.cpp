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
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int>v(n);
        map<int, int>mp;
        for(int i=0; i<n; i++){
            cin >> v[i];
            mp[v[i]] = i;
        }
        for(int i=0; i<q; i++){
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            r--;
            int larger =0;
            int smaller =0;
            if(mp[k] < l || mp[k] > r){
                cout << -1 << " ";
                continue;
            }
            int sv = k-1, lv = n-k;
            while(l <= r){
                
                int md = (l+r)/2;
                // cout << smaller << " " << larger << " " << l << " " << r <<  " " << md << endl;
                if(v[md] == k){
                    break;
                }
                else{
                    if(v[md] < k){
                        if(mp[k] < md){
                            larger++;
                            r = md-1;
                        }
                        else {
                            sv--;
                            l=md+1;
                        }
                    }
                    else{
                        if(mp[k] > md){
                            smaller++;
                            l=md+1;
                        }
                        else{ 
                            lv--;
                            r=md-1;
                        }
                    }
                }
            }
            
            if(smaller <= sv && larger <= lv){
                int tmp = smaller+larger-2*min(smaller, larger);
                cout << tmp*2+2*min(smaller, larger) << " ";
            }
            else cout << -1 << " ";
        }
        cout << endl;
    }
}