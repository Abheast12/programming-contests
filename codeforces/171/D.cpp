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
    long long n;
    cin >> n;
    vector<long long>a(n);
    vector<long long>mult;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    long long q;
    cin >> q;
    long long sum = 0;
    mult.push_back(0);
    for(int i=n; i>=1; i--){
        sum+=i;
        mult.push_back(sum);
    }
    vector<long long> supersums(n);
    for(int i=n-1; i>=0; i--){
        if(i==n-1){
            supersums[i] = a[i];
        }
        else{
            supersums[i] = supersums[i+1] + a[i]*(n-i);
        }
    }
    vector<long long>press(n+1);
    vector<long long>prea(n+1);
    press[0] = 0;
    prea[0] = 0;
    for(int i=1; i<=n; i++){
        prea[i] = prea[i-1] + a[i-1];
        press[i] = press[i-1] + supersums[i-1];
    }
    for(int i=0; i<q; i++){
        long long x, y;
        cin >> x >> y;
        auto it = lower_bound(mult.begin(), mult.end(), x);
        auto it2 = lower_bound(mult.begin(), mult.end(), y);
        if(x < *it){
            it--;
        }
        if(y < *it2){
            it2--;
        }
        int idx1, idx2;
        idx1 = distance(mult.begin(), it);
        idx2 = distance(mult.begin(), it2);
        pair<long long, long long>start, end;
        if(x == *it){
            start = {idx1, n};
        }
        else{
            start = {idx1+1, idx1+(x-*it)};
        }
        if(y == *it2){
            end = {idx2, n};
        }
        else{
            end = {idx2+1, idx2+(y-*it2)};
        }
        cout << start.first << " " << start.second << " " << end.first << " " << end.second << endl;
        long long ans = 0;
        if(end.first -1 > start.first){
            ans = press[end.first-1] - press[start.first];
        }
        cout << ans << endl;
        long long startsum; 
        if(start.second!=n){
            startsum = supersums[start.first-1] - supersums[start.second];
        }
        else{
            startsum = supersums[start.first-1];
        }
        long long startsub = (n-(start.first-1)-(start.second-1-start.first+1))*(prea[start.second-1]-prea[start.first-1]);
        ans+=(supersums[start.first-1] - (startsum - startsub));
        cout << ans << " " << startsum << " " << startsub << endl;
        long long endsum;
        if(end.second !=n){
            endsum = supersums[end.first-1] - supersums[end.second];
        }
        else{
            endsum = supersums[end.first-1];
        }
        long long endsub = (n-(end.first-1)-(end.second-1-end.first+1))*(prea[end.second-1]-prea[end.first-1]);
        ans+=(endsum - endsub);
        cout << ans << endl;
    }

}