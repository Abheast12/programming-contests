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

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            sum+=v[i];
        }
        while(v.size() > 1){
            vector<int>tmp;
            int nsum = 0;
            for(int i=1; i<v.size(); i++){
                tmp.push_back(v[i]-v[i-1]);
                nsum+=(v[i]-v[i-1]);
            }
            if(nsum < 0){
                for(int i=0; i<tmp.size(); i++){
                    tmp[i]*=-1;
                }
                nsum = -1*nsum;
                
            }
            v = tmp;
            sum = max(sum, nsum);
        }
        cout << sum << endl;
    }
}