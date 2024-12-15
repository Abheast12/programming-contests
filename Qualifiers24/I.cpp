#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<long long>people(n);
    vector<long long>stands(m);
    for(int i=0; i<n; i++){
        cin >> people[i];
    }
    for(int i=0; i<m; i++){
        cin >> stands[i];
    }
    // set<long long>huts;
    // for(int i=0; i<n; i++){
    //     huts.insert(i*100);
    // }
    sort(stands.begin(), stands.end());
    long long arr[200200];
    for(int i=0; i<200200; i++){
        arr[i] = 1e10;
    }
    arr[0] = 0;
    for(int i=1; i<=n;i++){
        arr[i] = arr[i-1] + people[i-1];
    }
    long long ans =0;
    int pos;
    if(stands[0]%100  !=0){
        pos = stands[0]/100;
    }
    else{
        pos = stands[0]/100 - 1;
    }
    pos = min(pos, n-1);
    ans = max(ans, arr[pos+1] - arr[0]);
    // cout << ans << endl;
    pos = stands[m-1]/100 + 1;
    pos = min(pos, n);
    ans = max(ans, arr[n] - arr[pos]);
    // cout << ans << endl;
    for(int i=0; i<n; i++){
        auto it = lower_bound(stands.begin(), stands.end(), i*100);
        if(*it == i*100 || i*100 >= stands[m-1]){
            continue;
        }
        else if(it == stands.begin()){
            continue;
        }
        else{
            // cout << "i:" << i << endl;
            long long minn = *it/100;
            if(*it % 100 == 0){
                minn--;
            }
            int tmp = *it;
            it--;
            long long dif = i*100 - *it;
            dif+=i*100;
            if((tmp + dif)%200 == 0){
                minn = min(minn, (tmp+dif)/200 - 1);
            }
            else{
                minn = min(minn, (tmp+dif)/200);
            }
            // cout << "dif" << dif << endl;
            // if(dif%100 == 0){
                
            //     minn = min(dif/100-1, minn);
            // }
            // else{
            //     minn = min(minn, dif/100);
            // }
            minn = min(minn, (long long)n-1);
            ans = max(ans, arr[minn+1] - arr[i]);
        }
    }
    cout << ans << endl;


    // for(int i=0; i<m; i++){
    //     int maxn =-1;
    //     int minn = n+1;
    //     int curmin = stands[i] / 100;
    //     if(stands[i] % 100 == 0){
    //         curmin--;
    //     }
    //     curmin = max(curmin, 0);
    //     int curmax = stands[i] / 100 + 1;
    //     curmax = min(curmax, n-1);
    //     if(i!=0){
            
    //         // double avg = (double)(stands[i] + stands[i-1])/2.0;
    //         int minn = (stands[i] + stands[i-1])/200 + 1;
    //         if(minn > n-1){
    //             minn = n-1;
    //         }
    //         // if((stands[i] + stands[i-1])%2==0){
    //         //     if(((stands[i] + stands[i-1])/2)%100==0){
    //         //         bestn = ((stands[i] + stands[i-1])/2)/100 + 1;
    //         //     }
    //         //     else{
    //         //         bestn = ((stands[i] + stands[i-1])/2)/100;
    //         //     }
    //         // }
    //     }
    //     else{
    //         minn = 0;
    //     }
    //     if(i!=m-1){
    //         maxn = (stands[i] + stands[i+1])/200;
    //         if((stands[i] + stands[i+1]) % 200 == 0){
    //             maxn--;
    //         }
    //         if(maxn < 0){
    //             maxn = 0;
    //         }
    //     }
    //     else{
    //         maxn = n-1;
    //     }
    //     cout << curmin << " " << curmax << " " << minn << " " << maxn << endl;
    //     ans = max(ans, arr[maxn+1] - arr[curmax]);
    //     ans = max(ans, arr[curmin+1] - arr[minn]);
    //     // auto it = huts.lower_bound(stands[i]);
    //     // if(it == huts.end()){
    //     //     cout << -1 << " ";
    //     // }
    //     // else{
    //     //     cout << *it << " ";
    //     //     huts.erase(it);
    //     // }
    // }
    // cout << ans << endl;

}