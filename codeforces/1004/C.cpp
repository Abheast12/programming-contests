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
bool check(int x){
    while(x > 0){
        if(x%10 == 7){
            return true;
        }
        x/=10;
    }
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // vector<int>v(n);
        // for(int i=0; i<n; i++){
        //     cin >> v[i];
        // }
        vector<int>nines;
        int tmp = 9;
        for(int i=0; i<10; i++){
            nines.push_back(tmp);
            tmp = tmp*10 + 9;
        }
        int ans = 23;
        for(int i=0; i<nines.size(); i++){
            int t_ans =0;
            tmp = n;
            while(true){
                if(check(tmp)){
                    break;
                }
                tmp+=nines[i];
                t_ans++;
            }
            ans = min(ans, t_ans);
        }
        cout << ans << endl;
    }
}