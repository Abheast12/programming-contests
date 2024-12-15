#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
map<long long, long long>m;
vector<pair<long long, long long>>v[100100];
vector<pair<long long, long long>>v2[100100];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long g, n;
    cin >> g;
    for(long long i=0; i<g; i++){
        long long t, u;
        cin >> t >> u;
        m[t] = u;
    }
    cin >> n;
    vector<pair<vector<pair<long long, long long>>,vector<pair<long long, long long>>>>v3;
    for(long long i=0; i<n; i++){
        long long m;
        cin >> m;
        for(long long j=0; j<m; j++){
            long long a, b;
            cin >> a >> b;
            v[i].push_back({a, b});
        }
        long long k;
        cin >> k;
        for(long long j=0; j<k; j++){
            long long a, b;
            cin >> a >> b;
            v2[i].push_back({a, b});
        }
        v3.push_back({{v[i].begin(), v[i].end()}, {v2[i].begin(), v2[i].end()}});
        

    }
    long long ct = 0;
    long long ctprev = 0;
    int vis[100100] = {0};
    while(true){
        bool tt = false;
        sort(v3.begin(), v3.end(), [](const auto& a, const auto& b) {
            long long suma = 0;
            long long sumb =0;
            for(long long j=0; j<(long long)a.first.size(); j++){
                suma += a.first[j].second - m[a.first[j].first];
            }
            for(long long j=0; j<(long long)b.first.size(); j++){
                sumb += b.first[j].second - m[b.first[j].first];
            }
            return suma < sumb;
        });
        fill(vis, vis+(int)v3.size(), 0);
        long long lg = log(v3.size());
        for(int jj=0; jj<max((long long)1, lg); jj++){
            
        
        for(long long i=0; i<(long long)v3.size(); i++){
            if(vis[i]==0){
            bool bt = false;
           
            for(long long j=0; j<(long long)v3[i].first.size(); j++){
                if(m[v3[i].first[j].first] < v3[i].first[j].second){
                    // m[v3[i].first[j].first]++;
                    // ct++;
                    bt= true;
                    break;
                }
            }
            if(!bt){
                tt = true;
                for(long long j=0; j<(long long)v3[i].second.size();j++){
                    m[v3[i].second[j].first]+=v3[i].second[j].second;
                }
                ct++;
                vis[i] = 1;
            }
            }
        }
        }

        
        if(!tt) break;
        vector<pair<vector<pair<long long, long long>>,vector<pair<long long, long long>>>>v4;
        for(long long i=0; i<(long long)v3.size(); i++){
            if(vis[i]==0){
                v4.push_back(v3[i]);
            }
        }
        v3 = v4;
        v4.clear();

    }
    cout << ct << endl;
    

}