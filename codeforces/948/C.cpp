#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<numeric>
#include<algorithm>
using namespace std;
//test
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>v(n);
        vector<long long>divs;
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long lm = 1;
        for(int i=0; i<n; i++){
            lm = lcm(lm, v[i]);
            if(lm > v[n-1]) break;
        }
        // cout << lcm(100003, 103391) << endl;
        if(lm > v[n-1]){
            cout << n << endl;
        }
        else{
            
            for(long long i=1; i*i<=v[n-1]; i++){
                if(v[n-1]%i==0){
                    if(find(v.begin(), v.end(), i) == v.end()) divs.push_back(i);
                    if(v[n-1]/i != i){
                        if(find(v.begin(), v.end(), v[n-1]/i) == v.end()) divs.push_back(v[n-1]/i);
                    }
                }
            }
            sort(divs.begin(), divs.end());
            // cout << divs.size() << endl;
            long long mx = 0;
            for(int i=0; i<divs.size(); i++){
                long long l = 1;
                long long temp = 0;
                for(int j=0; j<n; j++){
                    if(divs[i] % v[j] == 0 && lcm(l, v[j])<=divs[i]){
                        l = lcm(l, v[j]);
                        temp++;
                    }
                }
                if(l==divs[i])mx = max(mx, temp);
            }
            cout << mx << endl;
        }
        divs.clear();
        v.clear();
    }
}