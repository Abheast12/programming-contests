#include<iostream>
#include<vector>

using namespace std;
pair<long long, long long> calculateProb(vector<long long>&v, vector<long long>&prob, long long bit){
    long long x = 1<<bit;
    long long mod = 1e9+7;
    long long num = 1;
    long long den = 1;
    int ct=0;
    // bool t =false;
    for(int i=0; i<v.size(); i++){
        if(v[i]&x){
            long long tmp = ((long long)1e4-2*prob[i]+mod)%mod;
            num = (num*tmp)%mod;
            den = (den*(long long)1e4)%mod;
            // t = true;
            ct++;
            if(num<0 || den<0){
                cout << "YES" << endl;
            }
        }
    }
    if(ct==0){
        return {-1,-1};
    }
    num = (den-num+mod)%mod;
    den = (den*2)%mod;
    int op = v.size()-ct;
    while(op){
        num = (num*(long long)1e4)%mod;
        den = (den*(long long)1e4)%mod;
        op--;
    }
    cout << num << " " << den << " " << bit << endl;
    return {num, den};
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        vector<long long>prob(n);
        for(int i=0; i<n; i++){
            cin >> prob[i];
        }
        long long mod = 1e9+7;

        vector<long long>dp(1024, 0);
        dp[0] = 1;
        for(int i=0; i<n; i++){
            vector<long long>tmp(1024, 0);
            for(int j=0; j<1024; j++){
                long long mul = (dp[j]*prob[i])%mod;
                long long mul2 = (dp[j]*((long long)1e4-prob[i]))%mod;
                tmp[j^v[i]] = (tmp[j^v[i]]+mul)%mod;
                tmp[j] = (tmp[j]+mul2)%mod;
            }
            dp = tmp;
        }
        long long exp = n;
        long long base = 1e4;
        long long res = 1;
        while(exp){
            if(exp%2==1){
                res = (res*base)%mod;
            }
            base = (base*base)%mod;
            exp/=2;
        }
        long long num_sm = 0;
        for(int i=0; i<1024; i++){
            long long tmpi = (dp[i]*i)%mod;
            tmpi = (tmpi*i)%mod;
            num_sm = (num_sm+tmpi)%mod;
        }
        exp = mod-2;
        base = res;
        res = 1;
        while(exp){
            if(exp%2==1){
                res = (res*base)%mod;
            }
            base = (base*base)%mod;
            exp/=2;
        }
        res = (res*num_sm)%mod;
        cout << res << endl;











        // long long global_den = -1;
        // vector<pair<long long, long long>>bit_prob(10);
        // for(int i=0; i<10; i++){
        //     bit_prob[i] = calculateProb(v, prob, i);
        //     if(bit_prob[i].second!=-1){
        //         global_den = bit_prob[i].second;
        //     }
        // }
        // // vector<pair<long long, long long>>numerical_probs(1024);
        // long long num_sm = 0;
        // long long cum_den = 0;
        // for(int i=1; i<=1023; i++){
        //     int tmp = i;
        //     int ct =0;
        //     long long num =1;
        //     long long den = 1;
        //     bool t = true;
        //     for(int j=0; j<10; j++){
        //         ct = j;
        //         if(tmp&(1<<j)){
        //             if(bit_prob[ct].first==-1){
        //                 t = false;
        //                 break;
        //             }
        //             num = (num*bit_prob[ct].first)%mod;
        //             den = (den*bit_prob[ct].second)%mod;
        //         }
        //         else{
        //             if(bit_prob[ct].first!=-1){
        //                 long long tmp_num = (bit_prob[ct].second-bit_prob[ct].first+mod)%mod;
        //                 num = (num*tmp_num)%mod;
        //                 den = (den*bit_prob[ct].second)%mod;
        //             }
        //             else{
        //                 num = (num*global_den)%mod;
        //                 den = (den*global_den)%mod;
        //             }
        //         }
        //     }
        //     if(!t){
        //         continue;
        //     }
        //     // cout << num << " " << den << endl;
        //     // cout << den << endl;
        //     if(den!=683261743){
        //         cout << "BAD" << endl;
        //     }
        //     if(num<0 || den<0) cout << "yes" << endl;
        //     long long tmpi = (num*i)%mod;
        //     tmpi = (tmpi*i)%mod;
        //     num_sm = (num_sm+tmpi)%mod;
        //     if(num_sm<0 || den<0) cout << "yesnt" << endl;
        //     cum_den = den;
        // }
        // long long exp = mod-2;
        // long long base = cum_den;
        // long long res = 1;
        // while(exp){
        //     if(exp%2==1){
        //         res = (res*base)%mod;
        //     }
        //     base = (base*base)%mod;
        //     exp/=2;
        // }
        // cout << res << " " << num_sm << endl;
        // res = (res*num_sm)%mod;
        // cout << res << endl;

    }
}