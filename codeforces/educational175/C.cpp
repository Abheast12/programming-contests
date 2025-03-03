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
bool check(vector<int>&v, int k, int mid, string &s){
    int tot =0;
    bool streak = false;
    for(int i=0; i<v.size(); i++){
        if(v[i] <= mid){
            continue;
        }
        if(streak && s[i] == 'B'){
            continue;
        }
        else if(streak && s[i] == 'R'){
            streak = false;
        }
        else if(!streak && s[i] == 'B'){
            streak = true;
            tot++;
        }
    }
    return tot <= k;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        int l =0, r = 1e9+1;
        int ans =-1;
        while(l<r){
            int mid = (l+r)/2;
            if(check(v, k, mid, s)){
                r = mid;
                ans = mid;
            }
            else l = mid+1;
        }
        cout << ans << endl;
    }
}