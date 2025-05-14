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
    int ct=0;
    while(t--){
        ct++;
        
        int n, k;
        cin >> n >> k;
        // if(ct ==93){
        //     cout << n << " " << k << endl;
        // }
        vector<int>a(k+1);
        vector<int>b(k+1);
        for(int i=1; i<=k; i++){
            cout << "? " << i << endl;
            cout.flush();
            cin >> a[i];
        }
        vector<int>tmpb(k+1);
        int val = n%k == 0 ? 0 : k-n%k;
        for(int i=k-1; i>=0; i--){
            cout << "? " << n-i << endl;
            cout.flush();
            cin >> tmpb[k-i];
        }
        for(int i=1; i<=k; i++){
            if((val+i)%k==0){
                b[i] = tmpb[k];
            }
            else b[i] = tmpb[(val+i)%k];
        }
        // for(int i=1; i<=k; i++){
        //     cout << b[i] << " ";
        // }
        // cout << endl;
       
        int idx =-1;
        for(int i=1; i<=k; i++){
            if(a[i] != b[i]){
                idx = i;
                break;
            }
        }
        // if(n==2*k){
        //     cout << "! " << k << " " << k << endl;
        //     cout.flush();
        //     continue;
        // }
        if(idx == -1){
            if(n == 2*k){
                cout << "! " << k << " " << k << endl;
                cout.flush();
                continue;
            }
            cout << "! -1" << endl;
            cout.flush();
            continue;
        }
        // if(n%k==0 && idx!=1){
        //     cout << "! -1" << endl;
        //     cout.flush();
        //     continue;
        // }
        // n+=val;
        // cout << val << " " << n << endl;
        int al=k, bl=n-k+1 ,l, r;
        if(idx!=-1){
        int l = 2, r = n/k-1;
        al = idx;
        bl = r*k+idx;
        // cout << al << " " << bl << endl;
        while(l <= r){
            int m = (l+r)/2;
            cout << "? " << (m-1)*k+idx << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x == a[idx]){
                al = (m-1)*k+idx;
                l = m+1;
            }
            else{
                bl = (m-1)*k+idx;
                r = m-1;
            }
        }
        }
        // cout << al << " " << bl << endl;
        l = max(k+1, al+1);
        al = l-1;
        r = min(n-k, bl-1);
        // cout << l << " " << r << endl;
        bl = r+1;
        // cout << al << " " << bl << endl;
        // cout << l << " " << r << " " << al << " " << bl << endl;
        bool flag = false;  
        while(l<bl){
            
            
            int idx2 = l%k;
            if(l%k==0){
                idx2 = k;
            }
            if(a[idx2] == b[idx2]){
                l++;
                if(l == bl){
                    cout << "! -1" << endl;
                    cout.flush();
                    flag = true;
                    break;
                }
                continue;
            }
            cout << "? " << l << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x == a[idx2] && x!= b[idx2]){
                al = l;
                break;
            }
            else if(x == b[idx2] && x!= a[idx2]){
                bl = l;
                r = bl-1;
                break;
            }
            l++;
            if(l == bl){
                cout << "! -1" << endl;
                cout.flush();
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        // cout << l << " " << r << " " << al << " " << bl << endl;
        while(l < r){
            cout << "? " << r << endl;
            cout.flush();
            int x;
            cin >> x;
            int idx2 = r%k;
            if(r%k==0){
                idx2 = k;
            }
            if(x == b[idx2] && x!= a[idx2]){
                bl = r;
                break;
            }
            r--;
            if(l == r){
                cout << "! -1" << endl;
                cout.flush();
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        // cout << l << " " << r << endl;
        while(l<=r){
            int m = (l+r)/2;
            cout << "? " << m << endl;
            cout.flush();
            int x;
            cin >> x;
            int idx2 = m%k;
            if(m%k==0){
                idx2 = k;
            }
            if(x == a[idx2] && x!= b[idx2]){
                al = m;
                l = m+1;
            }
            else if(x == b[idx2] && x!= a[idx2]){
                bl = m;
                r = m-1;
            }
            else{
                cout << "! -1" << endl;
                cout.flush();
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
       
        // n-=val;
        cout << "! " << al << " " << n-bl+1 << endl;
        cout.flush();
    }
}