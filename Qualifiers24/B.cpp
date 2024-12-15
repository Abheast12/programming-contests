#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b, c;
    cin >> a >> b >> c;
    map<char, int> m;
    for(char j = 'A'; j<='Z'; j++){
        int cnt = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] == j){
                cnt++;
            }            
        }
        m[j] = max(m[j], cnt);
    }
    for(char j = 'A'; j<='Z'; j++){
        int cnt = 0;
        for(int i=0; i<b.size(); i++){
            if(b[i] == j){
                cnt++;
            }            
        }
        m[j] = max(m[j], cnt);
    }
    for(char j = 'A'; j<='Z'; j++){
        int cnt = 0;
        for(int i=0; i<c.size(); i++){
            if(c[i] == j){
                cnt++;
            }            
        }
        m[j] = max(m[j], cnt);
    }
    int bg = 0;
    vector<pair<char, char>>v;
    for(char j = 'A'; j<='Z'; j++){
        if(m[j] == 0) continue;
        for(char i=j+1; i<='Z'; i++){
            while(m[i] > 0 && m[j] > 0){
                v.push_back({j, i});
                m[i]--;
                m[j]--;
            }
        }
    }
    for(char j = 'A'; j<='Z'; j++){
        if(m[j] == 1){
            v.push_back({j, j});
            // cout << j << " A" << endl;
        }
    }
    cout << v.size() << endl;
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << v[i].second << endl;
    }
}