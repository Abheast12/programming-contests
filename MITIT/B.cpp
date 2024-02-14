#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<long long>o;
vector<long long>z;
long long arr[1001000];
long long finish(long long idx, bool isZero, long long k, long long n, long long p, long long r){
    long long tot = 0;
    if(isZero){
        for(int j=0; j<k; j++) {
            tot += (n - z[idx]+1) * p;
            idx++;
        }
    }
    else{
        for(int j=0; j<k; j++) {
            tot += (n-o[idx]+1)*r + (n-o[idx]+1)*p;
//            cout << arr[n] << " " << arr[o[idx]-1] << endl;
//            cout << tot << endl;
            idx++;
        }
    }
    return tot;
}
int main(){
    long long n, x, r, p, k;
    cin >> n >> x >> r >> p >> k;
    string s;
    cin >> s;
    for(long long i=1; i<=n; i++){
        if(s[i-1]=='0'){
            z.push_back(i);
        }
        else{
            o.push_back(i);
        }
    }
//    cout << (int)z.size() << endl;
//    cout << (int)o.size() << endl;
    for(int i=0; i<=n; i++){
        arr[i] = 0;
    }
    for(int i=1; i<=n; i++){

        arr[i] = arr[i-1];
        if(s[i-1]=='1'){
            arr[i]++;
        }
    }
    long long prev = 0;
    long long tot = 0;
    for(int i=1; i<=n; i++){

//        arr[i] = arr[i-1];
        if(s[i-1]=='1'){
            prev++;
        }
        tot+=prev;
    }
    long long zero = 0;
    long long one = 0;
    long long ans = n*x;

//    long long tot;
    ans -= tot*r;
    // cout << ans << endl;
    if(k==0){
        cout << ans << endl;
        return 0;
    }
//    cout << ans << endl;
//    cout << ans << endl;
    if(z.size()==0){
        tot = finish(0, false, k, n, p, r);
        ans+=tot;
        cout << ans << endl;
        return 0;
    }
//    else{
//        zero = z[0];
//    }
    if(o.size()==0){
        tot = finish(0, true, k, n, p, r);
        ans+=tot;
        cout << ans << endl;
        return 0;
    }
//    else{
//        one = o[0];
//    }

    while(k>0){

        if((n-o[one]+1)*r + (n-o[one]+1)*p >= (n-z[zero]+1)*p){
            // cout << "here1" << endl;
            ans+=(n-o[one]+1)*r + (n-o[one]+1)*p;
            // cout << arr[o[one]-1] << endl;
            // cout << (n-arr[o[one]-1])*r + (n-o[one]+1)*p << endl;
            one++;

            if(one==(int)o.size() && k >1){
                tot = finish(zero, true, k-1, n, p, r);
                ans+=tot;
                cout << ans << endl;
                return 0;
            }
        }
        else{
            ans+=(n-z[zero]+1)*p;
            zero++;
//            cout << "here" << endl;
//            cout << ans << endl;
            if(zero==(int)z.size() && k>1){
//                cout << "here0" << endl;
                tot = finish(one, false, k-1, n, p, r);
                ans+=tot;
                cout << ans << endl;
                return 0;
            }
        }
        k--;
    }
    cout << ans << endl;
}