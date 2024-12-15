#include<iostream>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,k;
        cin >> n >> k;
        long long cur = 1;
        long long prev =1;
        long long idx = 2;
        long long cycle_len;
        long long steps = 0;
        while(cur != 0){
            long long temp = cur;
            cur = (cur+prev)%k;
            prev = temp;
            idx++;
        }
        if(k==1){
            cycle_len = 1;
        }
        else{
            cycle_len = idx;
        }
        // cout << cycle_len << endl;
        long long mod = 1e9+7;
        // long long pos = n%((mod+1)*2);
        // pos = (pos*cycle_len)%((mod+1)*2);
        long long pos = n%mod;
        pos = (pos*cycle_len)%mod;
        cout << pos << endl;
        // if(pos == 0){
        //     cout << 0 << endl;
        // }
        // else if(pos <= 2){
        //     cout << 1 << endl;
        // }
        // else{
        //     long long exp = pos-2;
        //     long long t11 = 0, t12 = 1, t21 = 1, t22 = 1;
        //     long long a11 = 1, a12 = 0, a21 = 0, a22 = 1;
        //     while(exp){
        //         if(exp%2){
        //             long long nt11 = (a11*t11+a12*t21)%mod;
        //             long long nt12 = (a11*t12+a12*t22)%mod;
        //             long long nt21 = (a21*t11+a22*t21)%mod;
        //             long long nt22 = (a21*t12+a22*t22)%mod;
        //             a11 = nt11;
        //             a12 = nt12;
        //             a21 = nt21;
        //             a22 = nt22;
        //         }
        //         long long nt11 = t12%mod;
        //         long long nt12 = (t11+t12)%mod;
        //         long long nt21 = t22%mod;
        //         long long nt22 = (t21+t22)%mod;
        //         t11 = nt11;
        //         t12 = nt12;
        //         t21 = nt21;
        //         t22 = nt22;
        //         exp/=2;
        //     }
        //     cout << (a11+a12)%mod << endl;
        // }
    }
}