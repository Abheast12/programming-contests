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
        map<int, int>m;
        int n;
        cin >> n;
        for(int i=0; i<n; i++){
            int a, b;
            cin >> a >> b;
            m[b] = max(m[b], a);
        }
        int ans = 0;
        bool t = true;
        for(int i=1;i<=10; i++){
            if(m[i] != 0){
                ans += m[i];
            }
            else{
                cout << "MOREPROBLEMS" << endl;
                t = false;
                break;
            }
        }
        if(t){
            cout << ans << endl;
        }
        m.clear();
    }
}