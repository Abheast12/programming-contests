#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define MAX_INT 2147483640
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int>s;
        for(int i=0; i<n; i++){
            int x;
            cin >> x;
            s.insert(x);
        }
        set<pair<int, int>>dif;
        // set<pair<int, int>>dif2;
        auto temp_it = s.begin();
        if(*temp_it != 1){
            dif.insert({1, *temp_it-1});
        }
        
        for(auto it=s.begin(); it!=s.end(); it++){
            auto it2 = next(it);
            if(it2 == s.end()){
                // dif.insert({-1*MAX_INT, *it+1});
                dif.insert({*it+1, MAX_INT});
                break;
            }
            
            // dif.insert({-1*(*it2-*it-1), *it+1});
            dif.insert({*it+1, *it2-*it-1});
                // dif2.insert({*it2-*it-1, *it+1});
        }
        int m;
        cin >> m;
        for(int i=0; i<m; i++){
            for(pair<int, int> p: dif){
                cout << "(" <<  p.first << "," << p.second << ") ";
            }
            cout << endl;
            int x; char c;
            cin >> c >> x;
            if(c == '-'){
                auto it = s.find(x);
                auto it2 = next(it);
                if (it == s.begin()){
                    if(*it!=1){
                        // dif.erase({-1*(*it-1), 1});
                        dif.erase({1, *it-1});
                    }
                    if (it2!=s.end()){
                        // dif.erase({-1*(*it2-*it-1), *it+1});
                        // dif.insert({-1*(*it2-*it-1), 1});
                        dif.erase({*it+1, *it2-*it-1});
                        dif.insert({1, *it2-1});
                    }
                    else{
                        // dif.erase({-1*MAX_INT, *it+1});
                        // dif.insert({-1*MAX_INT, 1});
                        dif.erase({*it+1, MAX_INT});
                        dif.insert({1, MAX_INT});
                    }
                }
                else{
                    auto it3 = prev(it);
                    // dif.erase({-1*(*it-*it3-1), *it3+1});
                    dif.erase({*it3+1, *it-*it3-1});
                    if (it2 == s.end()){
                        // dif.erase({-1*MAX_INT, *it+1});
                        // dif.insert({-1*MAX_INT, *it3+1});
                        dif.erase({*it+1, MAX_INT});
                        dif.insert({*it3+1, MAX_INT});
                    }
                    else{
                        // dif.erase({-1*(*it2-*it-1), *it+1});
                        // dif.insert({-1*(*it2-*it3-1), *it3+1});
                        dif.erase({*it+1, *it2-*it-1});
                        dif.insert({*it3+1, *it2-*it3-1});
                    }
                }
                s.erase(it);
            }
            else if(c=='+'){
                auto it = lower_bound(s.begin(), s.end(), x);
                if(it == s.begin()){
                    if(x != 1){
                        // dif.erase({-1*(*it-1), 1});
                        // dif.insert({-1*(x-1), 1});
                        dif.erase({1, *it-1});
                        dif.insert({1, x-1});
                    }
                    // dif.insert({-1*(*it-x-1), x+1});
                    dif.insert({x+1, *it-x-1});
                }
                else if(it == s.end()){
                    if(s.size() == 0){
                        // dif.erase({-1*MAX_INT, 1});
                        // dif.insert({-1*MAX_INT, x+1});
                        dif.erase({1, MAX_INT});
                        dif.insert({x+1, MAX_INT});
                        if(x!=1){
                            // dif.insert({-1*(x-1), 1});
                            dif.insert({1, x-1});
                        }
                    }
                    else{
                        auto it2 = prev(it);
                        // dif.erase({-1*MAX_INT, *it2+1});
                        // dif.insert({-1*MAX_INT, x+1});
                        // dif.insert({-1*(x-*it2-1), *it2+1});
                        dif.erase({*it2+1, MAX_INT});
                        dif.insert({x+1, MAX_INT});
                        dif.insert({*it2+1, x-*it2-1});
                    }
                }
                else{
                    auto it2 = prev(it);
                    // dif.erase({-1*(*it-*it2-1), *it2+1});
                    // dif.insert({-1*(*it-x-1), x+1});
                    // dif.insert({-1*(x-*it2-1), *it2+1});
                    dif.erase({*it2+1, *it-*it2-1});
                    dif.insert({x+1, *it-x-1});
                    dif.insert({*it2+1, x-*it2-1});
                }
                s.insert(x);
            }
            else if(c=='?'){
                auto it = lower_bound(dif.begin(), dif.end(), make_pair(0, x), [](const pair<int, int>& a, const pair<int, int>& b) {
                    return a.second < b.second;
                });
                cout << it->first << " ";
            }
        }
        cout << endl;
        s.clear();
        dif.clear();
    }

}