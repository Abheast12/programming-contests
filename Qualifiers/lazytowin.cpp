#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<deque>
using namespace std;
int n;
vector<int>v;

int main(){
    cin >> n;
    long long tot = 0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
        tot+=a;
    }
    // if(tot<0){
    //     while(true){}
    // }
    if(tot%2 == 1){
        tot = (tot+1)/2;
    } else {
        tot/=2;
    }
    int lower = 0;
    int upper = 1;
    long long sum = v[lower];
    // cout << tot << endl;
    // set<int>s;
    // s.insert(lower);
    deque<int>dq;
    dq.push_back(v[lower]);
    int ans = 200200;
    
    while(lower != v.size()){
        // cout << lower << " " << upper << " " << sum << endl;
        if(sum<tot){
            if(upper!=v.size()){
                sum+=(long long)v[upper];
                // cout << v[upper] << endl;
                while(!dq.empty() && dq.back()>v[upper]){
                    dq.pop_back();
                }
                dq.push_back(v[upper]);
                upper++;
            }
            else{
                break;
            }
        }
        else{
            while(sum>=tot){
                // cout << lower << " " << upper << " " << ans << endl;
                if(!dq.empty() && sum-dq.front()>=tot){
                    ans = min(ans, upper-lower-1);
                }
                else ans = min(ans, upper-lower);
                // cout << ans << " " << dq.front() << endl;
                if(dq.front()==v[lower]){
                    dq.pop_front();
                }
                sum-=(long long)v[lower];
                lower++;
            }
        }
    }
    cout << ans << endl;
}