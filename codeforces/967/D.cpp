#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        set<int>s;
        map<int, int>mp;
        map<int, int>r;
        for(int i=0; i<n; i++){
            cin >> v[i];
            s.insert(v[i]);
            // mp[v[i]]++;
            r[v[i]] = i;
        }
        int best = s.size();
        map<int, bool>used;
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(used[v[i]]) continue;
            if(ans.size()!=0){
                while(true){
                    int cur = ans[ans.size()-1];
                    if(r[cur] > i){
                        if(ans.size()%2==0){
                            if(cur > v[i]){
                                used[cur] = false;
                                ans.pop_back();
                            }
                            else{
                                if(ans.size()>1 && ans[ans.size()-2] < v[i] && r[ans[ans.size()-2]] > i){
                                    used[cur] = false;
                                    ans.pop_back();
                                    cur = ans[ans.size()-1];
                                    used[cur] = false;
                                    ans.pop_back();
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        else{
                            if(cur < v[i]){
                                used[cur] = false;
                                ans.pop_back();
                            }
                            else{
                                if(ans.size()>1 && ans[ans.size()-2] > v[i] && r[ans[ans.size()-2]] > i){
                                    used[cur] = false;
                                    ans.pop_back();
                                    cur = ans[ans.size()-1];
                                    used[cur] = false;
                                    ans.pop_back();
                                }
                                else{
                                    break;
                                }
                            }
                        }
                    }
                    else break;
                }
            }
            ans.push_back(v[i]);
            used[v[i]] = true;  
        }
        cout << best << endl;
        for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;

        // int lastStart = -1;
        // vector<set<pair<int, int>>>vals(n+1);
        // set<int>tmp;

        // int cur = best+1;
        // for(int i=n-1; i>=0; i--){
        //     if(tmp.find(v[i]) == tmp.end()){
        //         tmp.insert(v[i]);
        //         cur--;
        //         vals[cur].insert({v[i], i});
        //     }
        //     else{
        //         vals[cur].insert({v[i], i});
        //     }
        // }
        // set<pair<int, int>>used;
        // int prev = -1;
        // for(int i=1; i<=best; i++){
        //     if(i==1){
        //         used = vals[i];
        //         cout << used.rbegin()->first << " ";
        //         prev = used.rbegin()->second;
        //     }
        //     else{
        //         used.insert(vals[i].begin(), vals[i].end());
        //     }
        // }



    }
}