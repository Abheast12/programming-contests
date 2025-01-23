#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
using namespace std;
#define int long long

const int N = 2e5+5;
const int logN = 20;
int sparse_table[N][logN];

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, q;
        cin >> n >> q;
        
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        for(int i=1; i<n; i++){
            sparse_table[i-1][0] = v[i]-v[i-1];
        }
        for (int j = 1; (1 << j) <= n; j++) { 
            for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
                sparse_table[i][j] = gcd(sparse_table[i][j - 1], sparse_table[i + (1 << (j - 1))][j - 1]); 
            } 
        } 
        map<int, int> mp;
        int prev = -1;
        for(int i=n-1; i>=0; i--){
            if(prev!=-1){
                if(v[i] == v[prev]){
                    mp[i] = prev;
                }
                else{
                    mp[i] = i;
                    prev = i;
                }
            }
            else{
                prev = i;
                mp[i] = i;
            }
        }
        for(int i=0; i<q; i++){
            int x, y;
            cin >> x >> y;
            if(x == y) cout << "0 ";
            else{
                x--;
                y--;
                if(mp[x] >= y){
                    // cout << "here" << endl;
                    cout << "0 ";
                }
                else{
                    y--;
                    // cout << x << " " << y << endl;
                    int l = y-x+1;
                    int k = 0;
                    while((1<<(k+1)) <= l) k++;
                    int ans = gcd(sparse_table[x][k], sparse_table[y-(1<<k)+1][k]);
                    cout << ans << " ";
                }
            }  
        }
        cout << endl;
        
    }
}