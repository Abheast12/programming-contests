#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    while(v.size() >1){
        int x = v[v.size()-1];
        int y = v[v.size()-2];
        v.pop_back();
        v.pop_back();
        if(v.size()==0){
            ans+=x;
            v.push_back(y-x);
        }
        else{
            int z = v[v.size()-1];
            int amt = x-(z-1);
            ans+=amt;
            x-=amt;
            y-=amt;
            if(x!=0){
                auto it = lower_bound(v.begin(), v.end(), z-1);
                v.insert(it, x);
            }
            if(y!=0){
                auto it = lower_bound(v.begin(), v.end(), z-1);
                v.insert(it, y);
            }
        }
    }
    ans+=v[0];
    cout << ans << endl;
}