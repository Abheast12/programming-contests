#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
vector<long long>pow2;
vector<long long>v;
int main(){
    int n;
    cin >> n;
    long long k = 1;
    pow2.push_back(k);
    for(int i=1; i<63; i++){
        k*=2;
        pow2.push_back(k);
    }
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        v.push_back(abs(a));
    }
    for(int i=0; i<n; i++){
        int ans = 0;
        
        long long tempval =v[i];
        while(tempval!=0){
            auto it = lower_bound(pow2.begin(), pow2.end(), tempval);
            int idx = it-pow2.begin();
            if(idx==0 || (abs(pow2[idx]-tempval) < abs(pow2[idx-1]-tempval))){
                tempval = abs(pow2[idx]-tempval);
                ans++;
            }
            else{
                tempval = abs(pow2[idx-1]-tempval);
                ans++;
            }
        }
        cout << ans << endl;
    }
}