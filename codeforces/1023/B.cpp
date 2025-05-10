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
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        int sm = 0;
        map<int, int>mp;
        for(int i=0; i<n; i++){
            cin >> v[i];
            sm += v[i];
            mp[v[i]]++;
        }
    
        sort(v.begin(), v.end()); 
        if(v[v.size()-1]-v[0]-1 > k || (mp[v[v.size()-1]] > 1 && v[v.size()-1]-v[0]>k)){
            cout << "Jerry" << endl;
        }
        else{
            if(sm%2 == 0){
                cout << "Jerry" << endl;
            }
            else{
                cout << "Tom" << endl;
            }
        }
    }
}