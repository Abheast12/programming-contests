#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            // long long a;
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long ans = 1e6;
        for(int i=0; i<n-1;i++){
            long long s = v[i] + v[i+1];
            auto it = lower_bound(v.begin(), v.end(), s);
            it--;
            long long idx = distance(v.begin(), it);
            ans = min(ans, i+n-idx-1);
        }
        cout << ans << endl;



        v.clear();
    }
}