#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    long long dp[101][5001];
    vector<int>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());


}