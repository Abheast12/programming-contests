#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, q;
        cin >> n >> m >> q;
        vector<int>v(n);
        vector<int>b(m);
        vector<set<int>>idx(n+1);
        map<int, int>mp;
        for(int i=0; i<n;i++){
            cin >> v[i];
            mp[v[i]] = i;
            idx[v[i]].insert(m);
        }
        for(int i=0; i<m; i++){
            cin >> b[i];
            idx[b[i]].insert(i);
        }

        int c = 0;
        for(int i=1; i<n; i++){
            if(*idx[v[i-1]].begin() <= *idx[v[i]].begin()){
                c++;
            }
        }
        if(c==n-1){
            cout << "YA" << endl;
        }
        else cout << "TIDAK" << endl;
        for(int i=0; i<q; i++){
            int l, r;
            cin >> l >> r;
            l--;
            int change = 0;
            int x = mp[b[l]];
            auto it = idx[b[l]].begin();
            auto it2 = next(it);
            int init = 0;
            int f = 0;
            if(l == *it && x<n-1){
                if(*it <= *idx[v[x+1]].begin() && *it2>*idx[v[x+1]].begin()){
                    change--;
                }
                // cout << change << endl;
                
            }
            if(l==*it && x>0){
                if(*it<*idx[v[x-1]].begin() && *it2 >= *idx[v[x-1]].begin()){
                    change++;
                }
            }
            idx[v[x]].erase(l);
            x = mp[r];
            it = idx[r].begin();
            init = 0;
            f = 0;
            if(x<n-1){
                if(*it > *idx[v[x+1]].begin() && l <= *idx[v[x+1]].begin()){
                    change++;
                }
            }
            if(x>0){
                if(*it >= *idx[v[x-1]].begin() && l < *idx[v[x-1]].begin()){
                    change--;
                }
            }
            // cout << change << endl;
            c+=change;
            b[l] = r;
            idx[r].insert(l);
            if(c==n-1){
                cout << "YA" << endl;
            }
            else cout << "TIDAK" << endl;

        }
    }
}