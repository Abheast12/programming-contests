#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;

long long bexp(long long bs, long long pw){
    long long res = 1;
    long long md = 1e9+9;
    while(pw > 0){
        if(pw%2 == 1){
            res = (res*bs);
            res %= md;
        }
        bs = (bs*bs);
        bs %= md;
        pw >>= 1;
    }
    return res;
}

vector<long long> compute_hash(string const& s) {
    const int p = 29;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    vector<long long>hashes(s.length());
    for (int i=0; i<s.length(); i++) {
        if(i!=0){
            hashes[i] = hashes[i-1]*p + (s[i] - '0' + 1);
            hashes[i] %= m;
        }
        else{
            hashes[i] = (s[i] - '0' + 1);
            hashes[i] %= m;
        }
    }
    return hashes;
}
vector<long long> compute_suffix_hash(string const& s){
    const int p = 29;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    vector<long long>hashes(s.length());
    for (int i=s.length()-1; i>=0; i--) {
        if(i!=s.length()-1){
            hashes[i] = hashes[i+1]*p + (s[i] - '0' + 1);
            hashes[i] %= m;
        }
        else{
            hashes[i] = (s[i] - '0' + 1);
            hashes[i] %= m;
        }
    }
    return hashes;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<long long>hashes1 = compute_hash(s);
        string tmp = s;
        vector<long long>hashes2 = compute_suffix_hash(s);
        string ones = "";
        string zeros = "";
        for(int i=0; i<k; i++){
            ones += "1";
            zeros += "0";
        }
        string s1 = "";
        string s2 = "";
        int bt = 0;
        while(s1.length() < n){
            if(bt == 0){
                s1 += ones;
                s2 += zeros;
                bt = 1;
            }
            else{
                s1 += zeros;
                s2 += ones;
                bt = 0;
            }
        }
        vector<long long>hashes31 = compute_hash(s1);
        reverse(s1.begin(), s1.end());
        vector<long long>hashes32 = compute_hash(s1);
        vector<long long>hashes41 = compute_hash(s2);
        reverse(s2.begin(), s2.end());
        vector<long long>hashes42 = compute_hash(s2);
        bool tt = false;
        int md = 1e9+9;
        int bst = -1;
        for(int i=0; i<n; i++){
            int tmp = hashes1[i] * bexp(29, n-i-1) + hashes2[i+1];
            tmp %= md;
            if(tmp == hashes31[n-1] || tmp == hashes41[n-1]){
                bst = i;
                break;
            }
        }
        if(s == s1 || s == s2){
            cout << n << endl;
        }
        else if(bst == -1){
            cout << -1 << endl;
        }
        else{
            cout << bst+1 << endl;
        }
        // int cur = 0;
        // int cut =-1;
        // int ln = -1;
        // char prev = '2';
        // bool tt = true;
        // while(cur < n){
        //     char st = s[cur];
        //     if(st == prev){
        //         cut = cur;
        //         ln == 1;
        //         for(int i=cur+1; i<min(n, cur+k); i++){
        //             if(s[i] == st){
        //                 ln++;
        //             }
        //         }
        //         if(ln == k){
        //             if(cur + k < n && s[cur+k] == st){
        //                 tt = false;
        //             }
        //         }
        //         break;
        //     }
        //     for(int i=cur+1; i<cur+k; i++){
        //         if(s[i] != st){
        //             cut = i;
        //             ln = i-cur;
        //             break;
        //         }
        //     }
        //     if(cut != -1) break;
        //     cur += k;
        // }
        // cur = cut+1;
        
        // while(cur+k < n){
        //     char st = s[cur];
        //     for(int i=cur+1; i<min(n,cur+k); i++){
        //         if(s[i] != st){
        //             tt= false;
        //             break;
        //         }
        //     }
        //     if(!tt) break;
        // }
        // char gg = s[cur];
        // int elen =1;
        // for(int i=cur; i<n; i++){
        //     if(s[i] != gg){
        //         tt = false;
        //         break;
        //     }
        //     elen++;
        // }
        // if(cut == -1){
        //     cout << k << endl;
        // }
        // else{
        //     if(!tt){
        //         cout << -1 << endl;
        //     }
        //     else if(ln == k){
        //         if(s[n-1] != s[cut]){
        //             cout << cut << endl;
        //         }
        //     }
        //     else if(elen+ln == k){
        //         cout << cut << endl;
        //     }
        //     else{
        //         cout << -1 << endl;
        //     }
        // }
    }
}