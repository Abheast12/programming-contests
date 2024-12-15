#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    long long k, n;
    cin >> k >> n;
    vector<long long>v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    map<long long, long long>m;
    map<long long, vector<long long>>rm;
    for(int i=0; i<n; i++){
        double check = (double)v[i]+(double)k/(double)2;
        if(check > k){
            check -= k;
        }
        auto it = lower_bound(v.begin(), v.end(), check);
        long long low, high;
        if(it==v.begin()){
            low = v[0]-check;
            high = k-v[n-1]+check;
            if(low < high){
                m[v[0]]++;
                rm[v[i]].push_back(v[0]);
            }
            else if(low > high){
                m[v[n-1]]++;
                rm[v[i]].push_back(v[n-1]);
            }
            else{
                m[v[0]]++;
                rm[v[i]].push_back(v[0]);
                m[v[n-1]]++;
                rm[v[i]].push_back(v[n-1]);
            }
        }
        else if(it==v.end()){
            low = check-v[n-1];
            high = v[0]+k-check;
            if(low < high){
                m[v[n-1]]++;
                rm[v[i]].push_back(v[n-1]);
            }
            else if(low > high){
                m[v[0]]++;
                rm[v[i]].push_back(v[0]);
            }
            else{
                m[v[0]]++;
                rm[v[i]].push_back(v[0]);
                m[v[n-1]]++;
                rm[v[i]].push_back(v[n-1]);
            }
        }
        else{
            high = *it-check;
            --it;
            low = check-*it;
            if(low < high){
                m[*it]++;
                rm[v[i]].push_back(*it);
            }
            else if(low > high){
                it++;
                m[*it]++;
                rm[v[i]].push_back(*it);
            }
            else{
                m[*it]++;
                rm[v[i]].push_back(*it);
                it++;
                m[*it]++;
                rm[v[i]].push_back(*it);
            }
        }
    }
    long long ans = 0;
    for(auto i=m.begin(); i!=m.end(); i++){
        if(i->second > ans){
            ans = i->second;
        }
    }
    for(auto i=rm.begin(); i!=rm.end(); i++){
        cout << i->first << " " << i->second[0] << " " << endl;
        if(i->second.size() == 2){
            bool t1 = false, t2 = false;
            if(rm[i->second[0]].size()==2){
                if(rm[i->second[0]][0] == i->second[1] || rm[i->second[0]][1] == i->second[1]){
                    if(rm[i->second[0]][0] == i->first || rm[i->second[0]][1] == i->first){
                        t1 = true;
                    }
                }
            }
            if(rm[i->second[1]].size()==2){
                if(rm[i->second[1]][0] == i->second[0] || rm[i->second[1]][1] == i->second[0]){
                    if(rm[i->second[1]][0] == i->first || rm[i->second[1]][1] == i->first){
                        t2 = true;
                    }
                }
            }
            if(t1 && t2){
                ans = max(ans, 3LL);
            }
            // if(rm[i->second[0]].size()==1){
            //     if(rm[i->second[0]][0] == i->second[1]){
            //         t1 = true;
            //     }
            // }
            // else if(rm[i->second[0]].size()==2){
            //     if(rm[i->second[0]][0] == i->second[1] || rm[i->second[0]][1] == i->second[1]){
            //         t1 = true;
            //     }
            // }

            // if(rm[i->second[1]].size()==1){
            //     if(rm[i->second[1]][0] == i->second[0]){
            //         t2 = true;
            //     }
            // }
            // else if(rm[i->second[1]].size()==2){
            //     if(rm[i->second[1]][0] == i->second[0] || rm[i->second[1]][1] == i->second[0]){
            //         t2 = true;
            //     }
            // }
            // if(t1 && t2){
            //     ans = max(ans, 3LL);
            // }
        }
    }
    cout << ans << endl;
}