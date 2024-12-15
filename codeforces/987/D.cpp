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
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        vector<int>maxx(n);
        vector<int>minn(n);
        int mx = -1;
        int mn = INT_MAX;
        for(int i=0; i<n; i++){
            if(mx < v[i]){
                mx = v[i];
            }
            maxx[i] = mx;
        }
        for(int i=n-1; i>=0; i--){
            if(mn > v[i]){
                mn = v[i];
            }
            minn[i] = mn;
        }
        vector<int>ans(n+1, 0);
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                ans[n-1] = maxx[n-1];
            }
            else{
                if(maxx[i] > minn[i+1]){
                    ans[i] = ans[i+1];
                }
                else{
                    ans[i] = maxx[i];
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}