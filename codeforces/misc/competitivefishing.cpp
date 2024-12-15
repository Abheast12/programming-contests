#include<iostream>
#include<vector> 
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    int ct=0;
    while(t--){
        ct++;
        long long n, k;
        cin >> n >> k;
        vector<char>v(n);
        // if(ct==48){
        //     string s;
        //     cin >> s;
        //     cout << n << "-" << k << "-" << s << endl;
        // }
        int o=0, z=0;
        vector<long long>dif(n);
        for(int i=0; i<n; i++){
            char c;
            cin >> c;
            if(c=='1'){
                v[i] = 1;
            }
            else{
                v[i] = 0;
            }
        }
        for(int i=n-1; i>0; i--){
            if(v[i]==0){
                z++;
            }
            else{
                o++;
            }
            dif[i] = o-z;
        }
        sort(dif.begin(), dif.end());
        long long tot =0;
        long long ans =-1;
        for(int i=n-1; i>=0; i--){
            tot+=dif[i];
            if(tot>=k){
                ans = n-i+1;
                break;
            }
        }
        cout << ans << endl;
        // long long tans =0;
        // long long ans =-1;
        // long long tot=0;
        // long long groups = 0;
        // for(int i=0; i<n; i++){
        //     // if(v[i]==1 && i+1 < n && v[i+1] == 1 && dif[i+1]>0){
        //     //     tot+=groups;
        //     //     groups++;
        //     // }
        //     // else if(v[i]==0 && i+1 < n && v[i+1] == 1 && dif[i+1]>0){
        //     //     tot-=groups;
        //     //     groups++;
        //     // }
        //     if(i+1<n && dif[i+1]>0){
        //         if(v[i]==1){
        //             tot+=groups;
        //         }
        //         else if(v[i]==0){
        //             tot-=groups;
        //         }
        //         groups++;
        //     }
        //     else {
        //         if(v[i]==1){
        //             tot+=groups;
        //         }
        //         else if(v[i]==0){
        //             tot-=groups;
        //         }
        //     }
        //     long long tmp = 0;
        //     if(i+1<n){
        //         tmp = dif[i+1];
        //     }
        //     if(tot+tmp*groups>=k){
        //         ans = groups+1;
        //         break;
        //     }
        // }
        // cout << ans << endl;


    }
}