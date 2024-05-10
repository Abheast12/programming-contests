#include<iostream>
#include<string>
using namespace std;

int t;
int check(int cur, string s, int n){
    int ct = 0;
    int pos = 0;
    string ss = s.substr(0, cur);
    // cout << ss << endl;
    while(pos < n){
        if(pos + cur > n){
            break;
        }
        else{
            string sss = s.substr(pos, cur);
            if(sss == ss){
                ct++;
                pos+=cur;
            }
            else{
                pos++;
            }
        }
    }
    return ct;
}
int main(){
    cin >> t;
    int a[200200];
    int ans[200200];
    for(int i=0; i<t; i++){
        int n, l, r;
        string s;
        cin >> n >> l >> r;
        cin >> s;
        for(int j=1; j<=n; j++){
            a[j] = n/j;
        }
        int cur = 1;
        
        int ct = n/2 + 1;
        int mid = 1;
        while(mid <=n){
            
            ct = check(mid, s, n);
            // cout << ct << endl;
            ans[ct] = mid;
            if(a[ct] == mid){
                mid++;
            }
            else{
                int high = n/ct;
                int low = mid;
                mid = (low+high+1)/2;
            }
        }
        for(int j=n; j>=1; j--){
            if(ans[j+1]!=0 && ans[j] == 0){
                ans[j] = ans[j+1];
            }
        }
        for(int j=l; j<=r; j++){
            cout << ans[j] << " ";
        }
        cout << endl;
        for(int j=0; j<=n; j++){
            ans[j] = 0;
            a[j] = 0;
        }
    }
}