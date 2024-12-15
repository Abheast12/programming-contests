#include<iostream>
#include<vector>
#include<set>
#include<deque>

using namespace std;
bool check(int mid, vector<int>&v){
    if(mid==0)return true;
    int len = v.size()-mid+1;
    deque<int>q;
    set<int>s;
    for(int i=0; i<v.size(); i++){
        while(!q.empty() && q.front()<i-len+1){
            q.pop_front();
        }

        while(!q.empty() && v[q.back()]>=v[i]){
            q.pop_back();
        }
        q.push_back(i);
        if(i>=len-1){
            s.insert(v[q.front()]);
        }
    }
    for(int i=1; i<=mid; i++){
        if(s.find(i)==s.end()){
            return false;
        }
        // else{
        //     cout << i << " ";
        // }
    }
    // cout << endl;
    return true;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int>v(n);
        set<int>s;
        for(int i=0; i<n; i++){
            cin >> v[i];
            s.insert(v[i]);
        }
        int l =1, r=n-1;
        int ans =0;
        while(l<=r){
            // cout << l << " " << r << endl;
            int mid = (l+r)/2;
            // cout << mid << endl;
            if(check(mid, v)){
                ans = mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        // cout << ans << endl;
        bool t = false;
        for(int i=1; i<=n; i++){
            if(s.find(i)==s.end()){
                t=true;
                break;
            }
        }
        if(!t){
            cout << "1";
        }
        else cout << "0";
        for(int i=2; i<=n; i++){
            if(n-ans+1<=i){
                cout << "1";
            }
            else cout << "0";
        }
        cout << endl;
    }
}