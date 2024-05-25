#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long m, x;
        cin >> m >> x;
        vector<int>v(m);
        for(int i=0; i<m; i++){
            int a;
            cin >> a;
            v[i] = a;
        }
        long long tot = 0;
        multiset<int>bought;
        int ans = 0;
        for(int i=0; i<m; i++){
            if(v[i] > tot){
                if(bought.size()>0){
                    auto it = bought.end();
                    it--;
                    if(*it > v[i]){
                        long long last = *it;
                        tot+=(last-v[i]);
                        bought.erase(it);
                        bought.insert(v[i]);
                    }
                }
            }
            else{
                tot -=v[i];
                bought.insert(v[i]);
                ans++;
            }
            tot+=x;
        }
        cout << ans << endl;
        v.clear();
        bought.clear();
    } 
}