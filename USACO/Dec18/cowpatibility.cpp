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

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

int32_t main(){
    setIO("cowpatibility");

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int n;
    cin >> n;
    // vector<int>v(n);
    map<vector<int>, int>mp;
    int ans =0;
    for(int i=0; i<n; i++){
        vector<int>v;
        for(int j=0; j<5; j++){
            int x;
            cin >> x;
            // v[i] = x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int val = 0;
        for(int j=1; j<32; j++){
            
            vector<int>tmp;
            int ct = 0;
            for(int k=0; k<5; k++){
                if((j>>k)&1){
                    ct++;
                    tmp.push_back(v[k]);
                }
            }
            if(ct%2==0){
                val-=mp[tmp];
            }
            else{
                val+=mp[tmp];
            }
            mp[tmp]++;
        }
        ans += (i-val);
    }
    cout << ans << endl;

}