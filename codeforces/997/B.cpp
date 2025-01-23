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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<char>>v(n+1, vector<char>(n+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> v[i][j];
            }
        }
        vector<int>ans(n);
        // int st =0;
        for(int i=n; i>=1; i--){
            int ct  =0;
            for(int j=1; j<=n; j++){
                if(i==j) continue;
                if(j < i && v[i][j] == '1'){
                    ct++;
                }
                if(j > i && v[i][j] == '0'){
                    ct++;
                }
            }
            ans[ct] = i;
        }
        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}