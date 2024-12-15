#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<char>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        deque<int>q;
        long long ans =0;
        for(int i=n-1; i>=0; i--){
            if(v[i] == '1'){
                q.push_back(i+1);
            }
            else{
                if(!q.empty()){
                    q.pop_front();
                }
                ans+=(long long)i+1;
            }
        }
        while(q.size() > 1){
            ans+=(long long)q.back();
            q.pop_back();
            q.pop_front();
        }
        if(q.size()==1){
            ans+=(long long)q.back();
        }
        cout << ans << endl;
        q.clear();
        v.clear();
    }
}