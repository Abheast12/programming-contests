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
        int n, m;
        cin >> n >> m;
        int maxr =0;
        int maxw = 0;
        for(int i=0; i<m; i++){
            int a, b;
            cin >> a >> b;
            maxr = max(maxr, a);
            maxw = max(maxw, b);
        }
        if(maxr + maxw <= n){
            for(int i=0; i<maxr; i++){
                cout << "R";
            }
            for(int i=0; i<n-maxr; i++){
                cout << "W";
            }
        }
        else{
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }
}