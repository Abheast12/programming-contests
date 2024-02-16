#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long>v;
int main(){
    int t;
    cin >> t;
    
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            long long a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        long long tot = 0;
        for(int j=1; j<n; j++){
            tot+=(v[j]-v[j-1]);
        }
        cout << tot << endl;
        v.clear();
    }
}