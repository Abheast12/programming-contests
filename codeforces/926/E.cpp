#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
vector<long long>v[300300];
queue<pair<long long, long long>>q;
long long height[300300];
long long vis[300300];
set<pair<long long, long long>>s;
bool find(long long a, long long b){
    long long cura = a;
    long long curb = b;
    set<pair<long long, long long>>curs;

    while(cura!=curb){
        if(height[cura] > height[curb]){
            swap(cura, curb);
        }
        if(height[cura]==height[curb]){
            long long pa = v[cura][0];
            long long pb = v[curb][0];
            if(s.find({pa, cura})!=s.end() || s.find({pb, curb})!=s.end()){
                return true;
            }
            else{
                curs.insert({pa, cura});
                curs.insert({pb, curb});
                cura = pa;
                curb = pb;
            }
        }
        else{
            long long pb = v[curb][0];
            if(s.find({pb, curb})!=s.end()){
                return true;
            }
            else{
                curs.insert({pb, curb});
                curb = pb;
            }
        }
    }
    for(auto i: curs){
        s.insert(i);
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long n;
        cin >> n;
        for(int j=0; j<n-1; j++){
            long long a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        q.push({1, 0});
        // vis[1] = 1;
        while(!q.empty()){
            long long a = q.front().first;
            long long b = q.front().second;
            // cout << a << " " << b << endl;
            height[a] = b;
            vis[a] = 1;
            q.pop();
            for(int j=0; j<v[a].size(); j++){
                if(vis[v[a][j]]!=1) q.push({v[a][j], b+1});
            }
        }
        for(int j=1; j<=n; j++){
            sort(v[j].begin(), v[j].end(), [](int i1, int i2) {
                return height[i1] < height[i2];
            });
        }
        // for(int j=1; j<=n; j++){
        //     cout << height[j] << " ";
        // }
        // cout << endl;
        long long k;
        cin >> k;
        long long ans = k;
        vector<pair<long long, long long>>p;
        // cout << "here" << endl;
        for(int j=0; j<k; j++){
            long long a, b;
            cin >> a >> b;
            if(height[a] > height[b]){
                swap(a, b);
            }
            p.push_back({a, b});
        }
        
        sort(p.begin(), p.end(), [](pair<long long, long long> i1, pair<long long, long long> i2) {
            return height[i1.second] - height[i1.first] > height[i2.second] - height[i2.first];
        });
        // cout << "here" << endl;
        for(int j=0; j<k; j++){
            if(find(p[j].first, p[j].second)){
                ans--;
            }
        }
        cout << ans << endl;
        for(int j=1; j<=n; j++){
            v[j].clear();
            height[j] = 0;
            vis[j] = 0;
        }
        s.clear();
    }
}