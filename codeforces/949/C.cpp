#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        vector<pair<pair<long long, long long>, long long>>v2;
        long long prev = -1;
        for(int i=0; i<n; i++){
            if(v[i] != -1){
                if(prev == -1) prev = i;
                else {
                    v2.push_back({{prev, i}, i-prev});
                    prev=i;
                }
            }
        }
        bool t = true;
        for(int i=0; i<v2.size(); i++){
            cout << v2[i].first.first << " " << v2[i].first.second << " " << v2[i].second << endl;
        }
        for(int j=0; j<v2.size(); j++){

            long long first = v[v2[j].first.first];
            long long second = v[v2[j].first.second];
            long long diff = v2[j].second;
            // set<long long>vis;
            vector<long long>vf;
            vector<long long>vs;
            vs.clear();
            vf.clear();
            long long tot = 0;
            while(first!=1 || second!=1){
                if(first>second){
                    first/=2;
                    tot++;
                    vf.push_back(first);
                    // vis.insert(first);
                }
                else if(first<second){
                    second/=2;
                    tot++;
                    vs.insert(vs.begin(), second);
                    // vis.insert(second);
                }
                else{
                    break;
                }

            }
            for(int i=0; i<vf.size(); i++){
                cout << vf[i] << " ";
            }
            cout << endl;
            for(int i=0; i<vs.size(); i++){
                cout << vs[i] << " ";
            }
            cout << endl;
            if(diff>=tot && diff%2==tot%2){
                for(int i=0; i<diff-tot; i++){
                    if(i%2==0) v[v2[i].first.first+i+1] = v[v2[i].first.first]*2;
                    else v[v2[i].first.first+i+1] = v[v2[i].first.first];
                }
                for(int i=0; i<vf.size(); i++){
                    v[v2[i].first.first+i+1] = vf[i];
                }
                for(int i=1; i<vs.size(); i++){
                    v[v2[i].first.second-i-1] = vs[i];
                }
            }
            else{
                t = false;
                cout << -1 << endl;
                break;
            }
        }
        if(t){
            for(int i=0; i<n; i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }
        v.clear();
        v2.clear();

    }
}