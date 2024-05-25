#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<long long> v;
set<long long> s;
int main(){
    long long t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        for(int j=0; j<n; j++){
            long long a;
            cin >> a;
            v.push_back(a+j+1);
        }
        sort(v.begin(), v.end());
        
    }
}