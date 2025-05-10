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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >>s;
        vector<int>v(n);
        vector<int>pre(n, 0);
        vector<bool>bigger(n, false);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        vector<int>prez(n, 0);
        vector<int>sufz(n, 0);
        vector<int>prel(n, 0);
        vector<int>sufl(n, 0);
        for(int i=0; i<n; i++){
            if(i == 0){
                prel[0] = v[0];
                if(s[0] == '1'){
                    prez[0] = v[0];
                }
                else{
                    prez[0] = 0;
                }
            }
            else{
                if(s[i-1] =='0'){
                    prel[i] = v[i];
                }
                else{
                    prel[i] = max(prel[i-1], 0LL) + v[i];
                }
                // prel[i] = max(prel[i-1], 0LL) +v[i];
                if(s[i] == '1'){
                    prez[i] = max(prez[i-1], 0LL) + v[i];
                }
                else{
                    prez[i] = 0;
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            if(i==n-1){
                sufl[i] = v[i];
                if(s[i] == '1'){
                    sufz[i] = v[i];
                }
                else{
                    sufz[i] = 0;
                }
            }
            else{
                if(s[i+1]== '0'){
                    sufl[i] = v[i];
                }
                else sufl[i] = max(sufl[i+1], 0LL)+v[i];
                if(s[i] == '1'){
                    sufz[i] = max(sufz[i+1], 0LL)+v[i];
                }
                else{
                    sufz[i] = 0;
                }
            }
        }
        int val = -1e18;
        int idx =-1;
        int tmp = -1e18;
        int tmp2 = -1e18;
        // for(int i=0; i<n; i++){
        //     cout << prel[i] << " " << sufl[i] << endl;
        // }
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                int cur = sufl[i] +prel[i];
                if(cur > val){
                    val = cur;
                    idx = i;
                }
            }
            else{
                int cur = sufz[i] + prez[i] - v[i];
                tmp = max(tmp, cur);
            }
            tmp2 = max(tmp2, sufl[i]+prel[i]-v[i]);
        }
        if(val == -1e18){
            if(tmp2 != k){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
                for(int i=0; i<n; i++){
                    cout << v[i] << " ";
                }
                cout << endl;
            }
        }
        else{
            // cout << tmp << " " << val << endl;
            if(tmp > k){
                cout << "No" << endl;
            }
            else if(tmp == k){
                // cout << "here" << endl;
                cout << "Yes" << endl;
                for(int i=0; i<n; i++){
                    if(s[i] == '0'){
                        v[i] = -1e18;
                    }
                    cout << v[i] << " ";
                }
                cout << endl;
            }
            else{
                v[idx] = k-val;
                cout << "Yes" << endl;
                for(int i=0; i<n; i++){
                    if(i!=idx && s[i] == '0'){
                        v[i] = -1e18;
                    }
                    cout << v[i] << " ";
                }
                cout << endl;
            }
        }


        // int mx =-1e18;
        // for(int i=n-1; i>=0; i--){
        //     if(mx > pre[i]){
        //         bigger[i] = true;
        //     }
        //     mx = max(mx, pre[i]);
        // }
        // int maxl= -1, maxr = -1;
        // int l = 0, r = 0;   
        // int best = -1e18;
        // vector<int>bestr(n, 0);
        
        // while(r < n){
        //     int cur = pre[r] - (l == 0 ? 0 : pre[l-1]);
        //     bestr[l] = r;
        //     if(cur > best){
        //         best = cur;
        //         maxl = l;
        //         maxr = r;
        //     }
        //     if(bigger[r]){
        //         r++;
        //     }
        //     else{
        //         l++;
        //         if(l > r){
        //             r = l;
        //         }
        //     }
        // }
        // if(best > k){
        //     cout << "No" << endl;
        //     continue;
        // }
        // if(best <= 0){
        //     for(int i=0; i<n; i++){
        //         if(s[i] == '0'){
        //             v[i] = k;
        //             break;
        //         }
        //     }
        //     cout << "Yes" << endl;
        //     for(int i=0; i<n; i++){
        //         cout << v[i] << " ";
        //     }
        //     cout << endl;
        //     continue;
        // }
        // bool flag = false;
        // int idx =-1;
        // for(int i=maxl; i<=maxr; i++){
        //     if(s[i] == '1'){
        //         flag = true;
        //         idx = i;
        //         break;
        //     }
        // }
        
        // if(flag){
        //     int val = k-best;
        //     if(val > k){
        //         cout << "No" << endl;
        //     }
        //     else{
        //         cout << "Yes" << endl;
        //         v[idx] = val;
        //         for(int i=0; i<n; i++){
        //             cout << v[i] << " ";
        //         }
        //         cout << endl;
        //     }
        // }
        // else{
        //     for(int i=0; i<n; i++){

        //     }
        // }
    }
}