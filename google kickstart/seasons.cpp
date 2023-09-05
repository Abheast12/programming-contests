#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <cstdlib>
using namespace std;
string c;
vector<pair<pair<long long int, long long int>, long long int>>v;
long long t, d, n, x;
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> d >> n >> x;
        long long maxl = 0;
        for(int j=0; j<n; j++){
            long long q, l, g;
            cin >> q >> l >> g;
            maxl = max(maxl, l);
            v.push_back({{g, l}, q});
        }
        unordered_map<long long int, long long int>m;
        sort(v.rbegin(), v.rend());
        long long total = 0;
        if(maxl<d-1){
            long long amt = x*(d-maxl);
            for(int j=0; j<n; j++){
                if(amt<=v[j].second){
                    total+=amt*v[j].first.first;
                    v[j].second-=amt;
                    break;
                }
                else{
                    total+=v[j].first.first*v[j].second;
                    v[j].second = 0;
                    amt-=v[j].second;
                }
            }
            for(int j=1; j<d-maxl; j++){
                m[j] = 0;
            }
        }
        // cout << total << endl;
        for(int j=0; j<n; j++){
            if(d-v[j].first.second>0){
                long long amt = d-v[j].first.second;
                long long leng;
                if(j==0)  leng = 1;
                else{
                    leng = abs(v[j-1].first.second - v[j].first.second);
                }
                // long long amt = d-v[j].first.second;
                cout << total << endl;
                while(leng>0){
                    if(v[j].second != 0 && (m.find(amt) == m.end() || m[amt] > 0)){
                        if(m[amt]>0){
                            if(m[amt]>v[j].second){
                                m[amt]-=v[j].second;
                                total+=v[j].first.first*v[j].second;
                                v[j].second = 0;
                                break;
                            }
                            else{
                                total+=v[j].first.first*m[amt];
                                v[j].second -= m[amt];
                                m[amt] = 0;
                            }
                        }
                        else{
                            if(x>v[j].second){
                                m[amt]=x-v[j].second;
                                total+=v[j].first.first*v[j].second;
                                v[j].second = 0;
                                break;
                            }
                            else{
                                total+=v[j].first.first*x;
                                v[j].second -= x;
                                m[amt] = 0;
                            }
                        }
                    }
                    leng--;
                }
            }
        }
        cout << "Case #" << i+1 << ": " << total << endl;
        v.clear();
        m.clear();
    }
}