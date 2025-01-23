#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        vector<pair<long long, long long>> v(n);
        map<long long, long long> m;
        set<long long>free;
        for(int i=1; i<=2*n; i++){
            free.insert(i);
        }
        for(long long i=0; i<n; i++){
            long long l, r;
            cin >> l >> r;
            v[i] = {l, r};
            if(l==r){
                m[l]++;
                free.erase(l);
            }
        }
        for(int i=0; i<n; i++){
            long long l = v[i].first;
            long long r = v[i].second;
            if(l==r){
                if(m[l]>1){
                    cout << "0";
                }
                else cout << "1";
            }
            else{
                auto it = free.lower_bound(l);
                if(it!=free.end() && *it<=r){
                    cout << "1";
                }
                else cout << "0";
            }
        }
        cout << endl;


    }
}