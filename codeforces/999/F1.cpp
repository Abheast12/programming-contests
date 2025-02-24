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
vector<string> getSubstrings(string &s){
    string prev = "";
    char c = s[0];
    prev+=s[0];
    int pos = 1;
    vector<string> ans;
    while(pos < s.length()){
        if(s[pos] != c){
            ans.push_back(prev);
            prev = "";
            prev+=s[pos];
            c = s[pos];
        }
        pos++;
    }
    ans.push_back(prev);
    return ans;
}
set<pair<int, int>> getSubs(string &s){
    set<pair<int, int>>subs;
    char c = s[0];
    int pos = 1;
    int st = 0;
    while(pos < s.length()){
        if(s[pos] != c){
            subs.insert({st, pos-st});
            st = pos;
            c = s[pos];
        }
        pos++;
    }
    subs.insert({st, pos-st});
    return subs;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;

        set<pair<int, int>> subs = getSubs(s1);
        set<pair<int, int>> subs2 = getSubs(s2);
        for(auto x: subs2){
            if(s2[x.first] != s1[x.first]){
                auto it = s1.begin();
                it++;
                if(it == s1.end()){
                    cout << -1 << endl;
                    break;
                }
                else{
                    // s1.begin()->first = it->first;

                }
            }
        }


        // vector<string> v1 = getSubstrings(s1);
        // vector<string> v2 = getSubstrings(s2);
        // int pos1 = 0, pos2 = 0;
        // int ans =0;
        // bool flag = false;
        // while(pos1 < v1.size() && pos2 < v2.size()){
        //     int l1 = v1[pos1].length();
        //     int l2 = v2[pos2].length();
        //     if(v1[pos1][0] != v2[pos2][0]){
        //         if(pos1+1<v1.size()){
        //             swap(v1[pos1], v1[pos1+1]);
        //             ans++;
        //         }
        //         else{
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if(v1[pos1][0] == v2[pos2][0]){
        //         if(l1 < l2){
        //             while(l1 < l2){
        //                 if(pos1+2 < v1.size()){
        //                     swap(v1[pos1+1], v1[pos1+2]);
        //                     ans++;
        //                     pos1++;
        //                     l1+=v1[pos1].length();
        //                 }
        //                 else{
        //                     flag = true;
        //                     break;
        //                 }
        //             }
        //             if(l1 == l2){
        //                 pos1++;
        //                 pos2++;
        //             }
        //             else{
        //                 flag = true;
        //                 break;
        //             }
        //         }
        //         else{
        //             flag = true;
        //             break;
        //         }
        //     }
        // }
        // if(flag){
        //     cout << -1 << endl;
        // }
        // else{
        //     cout << ans << endl;
        // }
    }
}