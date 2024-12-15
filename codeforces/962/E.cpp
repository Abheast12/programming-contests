#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long pre[200200];
        pre[0] = 0;
        for(int i=1; i<=s.length(); i++){
            if(s[i-1] == '0'){
                pre[i] = pre[i-1] - 1;
            }
            else pre[i] = pre[i-1] + 1;
        }
        map<long long, long long> mp;
        mp[0] = 1;
        long long ans = 0;
        const long long mod = 1e9+7;
        for(int i=1; i<=s.length(); i++){
            ans+=mp[pre[i]] * (s.length()-i+1);
            mp[pre[i]]+=i+1;
            mp[pre[i]]%=(mod);
            ans%=mod;
        }
        cout << ans << endl;
        mp.clear();
        for(int i=1; i<=s.length(); i++){
            pre[i] = 0;
        }
    }
}