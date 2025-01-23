#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<int>ans(2e5+1, 0);
    for(int i=1; i<=2e5; i++){
        int x = i;
        int cnt = 0;
        while(x){
            cnt++;
            x/=3;
        }
        ans[i] = cnt;
    }
    vector<int>pre(2e5+1, 0);
    for(int i=1; i<=2e5; i++){
        pre[i] = pre[i-1]+ans[i];
    }
    while(t--){
        int l, r;
        cin >> l >> r;
        cout << pre[r]-pre[l-1]+ans[l] << endl;
    }
}