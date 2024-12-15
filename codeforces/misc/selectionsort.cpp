#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    long long n;
    cin >>n;
    vector<long long>v(n);
    vector<long long>sorted(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
        sorted[i] = v[i];
    }
    sort(sorted.begin(), sorted.end());
    long long l = 0, r = n;
    for(long long i=0; i<n; i++){
        if(v[i] != sorted[i]){
            l = i;
            break;
        }
    }
    for(long long i=n-1; i>=0; i--){
        if(v[i] != sorted[i]){
            r = i+1;
            break;
        }
    }
    long long ans = min((n-l)*(n-l), (n-r)*(n-r));
    

}