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
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        if(k+1 > n){
            cout << 0 << endl;
            continue;
        }
        priority_queue<int>pq;
        for(int i=n-1; i>=0; i--){
            
            int time = n-i;
            if((pq.size()+1)*(k+1)> time){
                if(!pq.empty() && -1*pq.top() < v[i]){
                    // cout << pq.top() << " " << v[i] << endl;
                    pq.pop();
                    pq.push(-1*v[i]);
                }
            }
            else{
                pq.push(-1*v[i]);
            }
        }
        int ans = 0;
        while(!pq.empty()){
            ans += -1*pq.top();
            // cout << pq.top() << " ";
            pq.pop();
        }
        // cout << endl;
        cout << ans << endl;
    }
}