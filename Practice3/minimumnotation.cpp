#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
vector<string>v;
vector<pair<char, int>>v2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
    }
    for(int i=0; i<n; i++){
        string ans = "";
        map<char, int>m;
        for(int j=0; j<v[0].length(); j++){
            v2.push_back({v[i][j], m[v[i][j]]});
            m[v[i][j]]++;
        }
        sort(v2.begin(), v2.end());
        for(int j=0; j<v[0].length(); j++){
            v2.push_back(v[i][j]);
        }
        v2.clear();
    }
}