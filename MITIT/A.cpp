#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;
map<long long, long long>mp[500500];
set<long long>st[500500];
int main(){
    int q;
    cin >> q;
    int tot = 0;
    for(int i=0; i<q; i++){
        // cout << i << endl;
        int n;
        cin >> n;
        if(n==1){
            long long m, k;
            cin >> m >> k;
            tot++;
            mp[tot][m] = k;
            st[tot].insert(m);
        }
        else if(n==2){
            long long x, y;
            cin >> x >> y;
            tot++;
            for(auto it : st[x]){
                mp[tot][it] += mp[x][it];
                st[tot].insert(it);
            }
            for(auto it: st[y]){
                mp[tot][it] += mp[y][it];
                st[tot].insert(it);
            }
        }
        else if(n==3){
            long long x, m, k;
            cin >> x >> m >> k;
            tot++;
            for(auto it: st[x]){
                if(it!=m){
                    mp[tot][it] = mp[x][it];
                    st[tot].insert(it);
                }
            }
            if(mp[x][m]>k){
                mp[tot][m] = mp[x][m] - k;
                st[tot].insert(m);
            }
            else if(mp[x][m]<k){
                mp[tot][m] = k + mp[x][m];
                st[tot].insert(m);
            }
        }
        else{
            long long x;
            cin >> x;
            for(auto it: st[x]){
                cout << it << endl;
            }
        }
    }
}