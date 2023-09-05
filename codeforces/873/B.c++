#include<iostream>
#include<algorithm>
#include<numeric>
// #include<vector>

using namespace std;
// vector<int>v;
int main(){
    int n, t;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int ans = 0;
        for(int j=1; j<=n; j++){
            int a;
            cin >> a;
            if(ans == 0) ans = abs(a-j);
            else{
                if(abs(a-j) != 0){
                    ans = gcd(ans, abs(a-j));
                }
            }

        }
        cout << ans << endl;
    }
}