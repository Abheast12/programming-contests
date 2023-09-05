#include <iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
string c;
vector<pair<string, int>>v;
vector<pair<int, int>>v2;
int t, n, d, u;
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> c >> d >> u;
            v.push_back({c, u});
            v2.push_back({d, u});
        }
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
        int total = 0;
        for(int j=0; j<n; j++){
            if(v2[j].second==v[j].second) total++;
        }
        cout << "Case #" << i+1 << ": " << total << endl;
        v.clear();
        v2.clear();
    }
}