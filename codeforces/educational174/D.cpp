#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;  
int solve(string &s, int n, int first, int last){
    map<char, int>mp;
    map<char, int>mp2;
    for(int i=0; i<=last; i++){
        mp[s[i]]++;
        mp2[s[n-i-1]]++;
    }

    set<pair<char, int>>st2;
    for(char i ='a'; i<='z'; i++){
        if(mp2[i] > mp[i]){
            st2.insert({i, mp2[i]-mp[i]});
        }
    }
    if(st2.empty()){
        return last-first+1;
    }

    for(int i=last+1; i<n/2; i++){
        mp[s[i]]++;
        mp2[s[n-i-1]]++;
    }
    set<pair<char, int>>st;
    for(char i ='a'; i<='z'; i++){
        if(mp2[i] > mp[i]){
            st.insert({i, mp2[i]-mp[i]});
        }
    }
    int idx = n/2;
    while(!st.empty() && idx < n){
        mp[s[idx]]++;
        mp2[s[idx]]--;
        if(mp[s[idx]] == mp2[s[idx]]){
            auto it = st.lower_bound(make_pair(s[idx], 0));
            if(it != st.end() && it->first == s[idx]){
                st.erase(it);
            }
        }
        idx++;
    }
    return min(idx-first, n-1);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        vector<int>v(n);
        int first = -1;
        int last = -1;
        for(int i=0; i<n/2; i++){
            if(s[i] == s[n-i-1]){
                v[i] = 0;
                v[n-i-1] = 0;
            }
            else{
                if(first == -1){
                    first = i;
                }
                v[i] = 1;
                last = i;
                v[n-i-1] = 1;
            }
        }
        if(first == -1){
            cout << 0 << endl;
            continue;
        }

        
        int ans = 1e9;
        ans = min(ans, solve(s, n, first, last));
        reverse(s.begin(), s.end());
        ans = min(ans, solve(s, n, first, last));
        cout << ans << endl;

        // if(v[n/2-1] == 1){
        //     map<char, int>mp;
        //     map<char, int>mp2;
        //     for(int i=0; i<n/2; i++){
        //         mp[s[i]]++;
        //     }
        //     for(int i=n/2; i<n; i++){
        //         mp2[s[i]]++;
        //     }
        //     set<pair<char, int>>st;
        //     for(char i ='a'; i<='z'; i++){
        //         if(mp2[i] > mp[i]){
        //             st.insert({i, mp2[i]-mp[i]});
        //         }
        //     }
        //     if(st.empty()){
        //         cout << n/2-first << endl;
        //         continue;
        //     }
        //     int idx = n/2;
        //     while(!st.empty() && idx < n){
        //         mp[s[idx]]++;
        //         mp2[s[idx]]--;
        //         if(mp[s[idx]] == mp2[s[idx]]){
        //             auto it = st.lower_bound(make_pair(s[idx], 0));
        //             if(it != st.end() && it->first == s[idx]){
        //                 st.erase(it);
        //             }
        //         }
        //         idx++;
        //     }
        //     cout << min(idx+1, n-1) << endl;
        // }
        // else{
            
        //     int last = -1;
        //     for(int i=0; i<n/2; i++){
        //         if(v[i] == 1){
        //             last = i;
        //         }
        //     }
        //     if(first == -1 && last == -1){
        //         cout << 0 << endl;
        //         continue;
        //     }
        //     cout << last-first+1 << endl;
        // }
    }
}