#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int x;
        cin >> x;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        set<int>s;
        long long ans = 1;
        for(int i=0; i<n; i++){
            if(x%v[i]==0){
                bool added = false;
                for(int it : s){
                    if(it==v[i]){
                        ans++;
                        s.clear();
                        s.insert(x/v[i]);
                        added = true;
                        break;
                    }
                    else if(it%v[i] == 0){
                        s.insert(it/v[i]);
                    }
                }
                if(!added){
                    s.insert(x/v[i]);
                }
            }
            
        }
        cout << ans << endl;
        s.clear();
        v.clear();
    }
}