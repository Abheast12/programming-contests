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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k, m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        set<char>chars;
        for(int i=0; i<k; i++){
            chars.insert((char)('a' + i));
            // cout << (char)('a' + i) << endl;
        }
        int cur = 0;
        vector<char>last;
        set<char>tmp;
        while(cur < m){
            tmp.insert(s[cur]);
            if(tmp == chars){
                last.push_back(s[cur]);
                tmp.clear();
                // cout << cur << endl;
            }
            cur++;
        }
        if(last.size() >= n){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
            // cout << last.size() << endl;
            for(int i=0; i<k; i++){
                if(tmp.find((char)('a' + i)) == tmp.end()){
                    last.push_back((char)('a' + i));
                    // cout << (char)('a' + i) << endl;
                    break;
                }
            }
            while(last.size() < n){
                last.push_back('a');
            }
            for(int i=0; i<last.size(); i++){
                cout << last[i];
            }
            cout << endl;
        }
    }
}