#include<iostream>
#include<vector>
using namespace std;
long long standard_xor(long long n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    return 0;
}
long long bits(long long n, long long k, long long i){
    if(k>n) return 0;
    long long t = 1LL<<i;
    long long x = (n-k)/t;
    long long y = standard_xor(x);
    long long res = y<<i;
    if(x%2==0){
        res = res | k;
    }
    return res;
}
int main(){
    long long t;
    cin >> t;
    while(t--){
        long long l,r,i,k;
        cin >> l >> r >> i >> k;
        long long xorr = standard_xor(r);
        long long xorl = standard_xor(l-1);
        long long res = xorr^xorl;
        res = res^bits(r,k,i);
        res = res^bits(l-1,k,i);
        cout << res << endl;
    }
}