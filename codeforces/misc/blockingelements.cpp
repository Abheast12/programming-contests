#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
long long a[100100];
long long dp[100100];
bool check(long long val, long long n){
    multiset<long long> s;
    long long l = 0;
    long long r = 0;
    long long prev =0;
    while(r !=n){
        if(a[r] > val){
            return false;
        }
        
        if(r==0){
            dp[r] = a[r];
        }
        else{
            prev += a[r-1];
            if(prev > val){
                while(prev > val){
                    // cout << prev << " " << val << " " << r << endl;
                    prev -= a[l];
                    // cout << "erasing " << dp[l] << endl;
                    s.erase(s.find(dp[l]));
                    l++;
                    // cout << a[l] << endl;
                    
                }
                
            }
            auto it = s.begin();
            // cout << *it << " " << l << " " << r << endl;
            // cout << l << " " << r << endl;
            if(l!=0){
                // if(r==3) cout << *it << " " << dp[l-1] << endl;
                if(s.size()!=0) dp[r] = min(*it, dp[l-1]) + a[r];
                else dp[r] = dp[l-1] + a[r];
            }
            else dp[r] = a[r];
        }
        // cout << "inserting " << dp[r] << endl;
        s.insert(dp[r]);
        // for(int gg : s){
        //     cout << gg << " ";
        // }
        // cout << endl;
        // cout << distance(s.begin(), s.find(1)) << endl;
        r++;
    }
    // cout << "val: " << val << endl;
    // for(int k=0; k<n; k++){
    //     cout << dp[k] << " ";
    // }
    // cout << endl;
    long long sum = 0;
    for(int k=n-1; k>=0; k--){
        if(sum > val){
            break;
        }
        if(dp[k] <= val){
            return true;
        }
        sum+=a[k];
    }
    return false;
    // if(r==n){
    //     prev+=a[n-1];
    //     while(prev > val){
    //         prev -= a[l];
    //         l++;
    //         s.erase(a[l]);
    //     }
    //     auto it = s.begin();
    //     dp[r] = min(*it, dp[l-1]) + a[r];
    // }
    // if(dp[r] <= val) return true;
    // return false;
    // long long temp =0;
    // long long blocked =0;
    // for(int k=0; k<n; k++){
    //     if(a[k] > val){
    //         return false;
    //     }
    //     else{
    //         if(temp + a[k] > val){
    //             temp = 0;
    //             blocked+=a[k];
    //             if(blocked>val){
    //                 return false;
    //             }
    //         }
    //         else{
    //             temp += a[k];
    //         }
    //     }
    // }
    // if(temp>val){
    //     return false;
    // }
    // return true;
}
bool check2(long long val, long long n){
    long long temp =0;
    long long blocked =0;
    for(int k=n-1; k>=0; k--){
        if(a[k] > val){
            return false;
        }
        else{
            if(temp + a[k] > val){
                temp = 0;
                blocked+=a[k];
                if(blocked>val){
                    return false;
                }
            }
            else{
                temp += a[k];
            }
        }
    }
    if(temp>val){
        return false;
    }
    return true;
}
int main(){
    long long t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> a[j];
        }
        long long l = 0;
        long long r = 1e16;
        long long ans;
        while(l < r){
            long long mid = (l + r) / 2;
            if(check(mid, n)){
                r = mid;
                ans = mid;
            }
            else{
                l = mid + 1;
            }
        }
        cout << ans << endl;
    }
}