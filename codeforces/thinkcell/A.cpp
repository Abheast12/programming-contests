#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long> v;
int main(){
    long long t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        long long ans = 0;
        for(int j=0; j<2*n; j++){
            long long a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        for(int j=2*n-2; j>=0; j-=2){
            ans += v[j];
        }
        cout << ans << endl;
        v.clear();
    }
}