#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        vector<pair<int, int>>ranges(n+1, {n+1, -1});
        multiset<int>ms;
        map<int, int>mp;
        for(int i=0; i<n; i++){
            cin >> v[i];
            // if(i!=0){
            //     ms.insert(i-(v[i]-1));
            // }
            mp[v[i]]++;
            ranges[v[i]].first = min(ranges[v[i]].first, i);
            ranges[v[i]].second = max(ranges[v[i]].second, i);
        }
        int minn = n-1;
        int maxx = 0;
        int l = 0, r= n-1;
        bool t = false;
        for(int i=1; i<=n; i++){
            if(mp[i]==0) continue;
            minn = min(minn, ranges[i].first);
            maxx = max(maxx, ranges[i].second);
            if(maxx-minn+1<=i){
                l = max(l, maxx-i+1);
                r = min(r, minn+i-1);

                // minn = min(minn, min(ranges[i].first, ranges[i].second-i+1));
                // maxx = max(maxx, max(ranges[i].second, ranges[i].first+i-1));
            }
            else{
                t = true;
                cout << 0 << endl;
                break;
            }
            // if(ranges[i].second-ranges[i].first+1<=i){
            //     minn = max(minn, min(ranges[i].first, ranges[i].second-i+1));
            //     // minn = max(minn, 0);
            //     maxx = min(maxx, max(ranges[i].second, ranges[i].first+i-1));
            //     // maxx = min(maxx, n-1);
            // }
            // else{
            //     t = true;
            //     cout << 0 << endl;
            //     break;
            // }
        }
        if(!t){
            if(l > r){
                cout << 0 << endl;
            }
            else cout << r-l+1 << endl;
        }

        // int ans = 0;
        // multiset<int>ms2;
        // for(int i=0; i<n; i++){
        //     if(i==0){
        //         if(*ms.rbegin()<=i){
        //             ans++;
        //         }
        //     }
        //     else if(i==n-1){
        //         if(*ms2.begin()>=i){
        //             ans++;
        //         }
        //     }
        //     else{
        //         if(*ms.rbegin()<=i && *ms2.begin()>=i){
        //             ans++;
        //         }
        //         ms.erase(ms.find(i-(v[i]-1)));
        //     }
        //     ms2.insert(i+(v[i]-1));
        // }
        // cout << ans << endl;
        
    }
}