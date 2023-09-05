#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

int main(){
    long long t, s;
    vector<long long>v;
    cin >> t >> s;
    long long tAll = 2*t*t + 2*t + 1;
    long long sAll = 0;
    long long tot = 0;
    long long addAmt = 0;
    for(int i=1; i<=s; i++){
        if(i%3==0){
            addAmt++;
        }
        tot+=addAmt;
    }
    long long ts = s;
    if(ts-2>0){
        v.push_back(ts-2);
    }
    ts-=2;
    while(ts>0){
        ts-=3;
        if(ts>0){
            v.push_back(ts);
        }
    }
    // for (int i = 0; i <= s * 2 / 3; i++) {
    //     sAll += s - i - (1 + i) / 2 + 1;
    // }
    // sAll *= 8;
    // sAll -= 4 * (s + 2 + s * 2 / 3) - 1;
    
    if(t>s){
        tAll = 2*s*s + 2*s + 1;
        long long tsum = 0;
        for(int i=0; i<min(t-s, (long long)v.size()); i++){
            // cout << v[i] << endl;
            tsum+=v[i];
        }
        // cout << tsum << endl;
        tAll+=4*tsum;
    }
    sAll = 2*s*s + 2*s + 1 + tot*4;
    long long gd = gcd(tAll, sAll);
    if (tAll >= sAll) {
        cout << 1 << endl;
        return 0;
    }
    tAll/=gd;
    sAll/=gd;
    cout << tAll << "/" << sAll << endl;
}