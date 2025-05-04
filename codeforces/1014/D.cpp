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
void add(vector<int>&ops, string& s, char c, int curct, int maxct, vector<pair<int, char>>&v){
    // int i =0;
    // while(i < s.length()-1){
    //     // cout << i << " " << s[i] << " " << s[i+1] << endl;
    //     if(s[i] != s[i+1] && s[i] != c && s[i+1] != c){
    //         ops.push_back(i+1);
    //         s = s.substr(0, i+1) + c + s.substr(i+1);
    //         curct++;
    //         if(curct == maxct) break;
    //     }
    //     i++;
    // }


    int off = 0;
    for(int i=0; i<s.length()-1; i++){
        if(v[0].first == v[2].first) break;
        if(s[i] != s[i+1]){
            if(s[i] == v[2].second || s[i+1] == v[2].second){
                
                if(s[i] != v[0].second && s[i+1] != v[0].second){
                    // cout << i << " " << s[i] << " " << s[i+1] << endl;
                    int ct =0;
                    string tmp = "";
                    while(ct < 2*(v[2].first - v[0].first)-1){
                        ops.push_back(i+1+off);

                        off++;
                        ct++;
                    }
                    for(int j =0; j<ct; j++){
                        if(j%2 == 0){
                            tmp += v[0].second;
                        }
                        else{
                            tmp += v[1].second;
                        }
                    }
                    s = s.substr(0, i+1) + tmp + s.substr(i+1);
                    v[1].first+=v[2].first-v[0].first-1;
                    
                    v[0].first = v[2].first;
                    // cout << tmp << " " << v[0].first << endl;
                    break;
                    // cout << s[i] << " " << s[i+1] << endl;
                    // if(v[1].first == v[2].first){
                    //     ops.push_back(i+1+off);
                    //     off++;
                    //     v[0].first++;
                    // }
                    // else{
                    //     // cout << "here" << endl;
                    //     int ct =0;
                    //     while(ct < 2*(v[2].first - v[1].first)){
                    //         ops.push_back(i+1+off);
                    //         off++;
                    //         ct++;
                    //     }
                    //     // off+=2*(v[2].first - v[1].first);
                    //     // off++;
                    //     v[0].first += v[2].first - v[1].first;
                    //     v[1].first = v[2].first;
                        
                    //     // v[0].first++;
                    //     if(v[0].first < v[2].first){
                    //         ops.push_back(i+1+off);
                    //         off++;
                    //         v[0].first++;
                    //     }
                    // }
                    // if(v[0].first > v[1].first){
                    //     swap(v[0], v[1]);
                    // }
                }
                // else{
                //     if(v[1].first == v[2].first) continue;
                //     int ct =0;
                //     while(ct < 2*(v[2].first - v[1].first)){
                //         ops.push_back(i+1+off);
                //         off++;
                //         ct++;
                //     }
                //     // off+=2*(v[2].first - v[1].first);
                //     v[0].first += v[2].first - v[1].first;
                //     v[1].first = v[2].first;
                    
                // }
                
            }
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int>ct(3);
        vector<char>ch(3);
        ch[0] = 'I';
        ch[1] = 'L';
        ch[2] = 'T';
        for(int i=0; i<n; i++){
            if(s[i] == 'I'){
                ct[0]++;
            }
            else if(s[i] == 'L'){
                ct[1]++;
            }
            else{
                ct[2]++;
            }
        }


        if(ct[0] == ct[1] && ct[1] == ct[2]){
            cout << 0 << endl;
            continue;
        }
        vector<int>ops;
        vector<pair<int, char>>v;
        for(int i=0; i<3; i++){
            v.push_back({ct[i], ch[i]});
        }
        sort(v.begin(), v.end());
        // int off = 0;
        // for(int i=0; i<s.length()-1; i++){
        //     if(v[0].first == v[2].first) break;
        //     if(s[i] != s[i+1]){
        //         if(s[i] == v[2].second || s[i+1] == v[2].second || ((v[1].first == v[2].first) && (s[i] == v[1].second || s[i+1] == v[1].second))){
                    
        //             if(s[i] != v[0].second && s[i+1] != v[0].second){
        //                 // cout << s[i] << " " << s[i+1] << endl;
        //                 if(v[1].first == v[2].first){
        //                     ops.push_back(i+1+off);
        //                     off++;
        //                     v[0].first++;
        //                 }
        //                 else{
        //                     // cout << "here" << endl;
        //                     int ct =0;
        //                     while(ct < 2*(v[2].first - v[1].first)){
        //                         ops.push_back(i+1+off);
        //                         off++;
        //                         ct++;
        //                     }
        //                     // off+=2*(v[2].first - v[1].first);
        //                     // off++;
        //                     v[0].first += v[2].first - v[1].first;
        //                     v[1].first = v[2].first;
                            
        //                     // v[0].first++;
        //                     if(v[0].first < v[2].first){
        //                         ops.push_back(i+1+off);
        //                         off++;
        //                         v[0].first++;
        //                     }
        //                 }
        //                 if(v[0].first > v[1].first){
        //                     swap(v[0], v[1]);
        //                 }
        //             }
        //             else{
        //                 if(v[1].first == v[2].first) continue;
        //                 int ct =0;
        //                 while(ct < 2*(v[2].first - v[1].first)){
        //                     ops.push_back(i+1+off);
        //                     off++;
        //                     ct++;
        //                 }
        //                 // off+=2*(v[2].first - v[1].first);
        //                 v[0].first += v[2].first - v[1].first;
        //                 v[1].first = v[2].first;
                        
        //             }
                    
        //         }
        //     }
        // }
        bool flag = false;
        while(true){
            if(v[0] .first == v[1].first && v[1].first == v[2].first){
                break;
            }
            
            // int curct = ct[mni];
            // // cout << curct << " " << mx << ch[mni] << endl;
            // int newct = add(ops, s, ch[mni], curct, mx);
            sort(v.begin(), v.end());
            int prev = v[0].first;
            // cout << v[0].first << " " << v[1].first << " " << v[2].first << endl;
            if(v[0].first == v[1].first){
                swap(v[0], v[1]);
            }
            add(ops, s, v[0].second, v[0].first, v[2].first, v);
            if(v[0].first == prev){
                flag = true;
                break;
            }
            // cout << "here" << endl;
            // for(int o : ops){
            //     cout << o << " ";
            // }
            // cout << endl;
            // if(newct == curct){
            //     flag = true;
            //     break;
            // }
            // ct[mni] = newct;
            // bool bad = false;
            // int nmni = -1;
            // for(int i=0; i<3; i++){
            //     if(i != mni){
            //         if(ct[i] <= ct[mni]){
            //             nmni = i;
            //             bad = true;
            //         }
            //     }
            // }
            // if(!bad){
            //     flag = true;
            //     break;
            // }
            // mni = nmni;
        }
        if(flag){
            cout << -1 << endl;
            continue;
        }
        if(ops.size() > 2*n){
            cout << -1 << endl;
            continue;
        }
        cout << ops.size() << endl;
        if(ops.size() == 0){
            continue;
        }
        for(int i=0; i<ops.size(); i++){
            cout << ops[i] << endl;
        }
        // if(v[0].first != v[2].first){
        //     cout << -1 << endl;
        //     continue;
        // }
        // if(ops.size() > 2*n){
        //     cout << -1 << endl;
        //     continue;
        // }
        // cout << ops.size() << endl;
        // if(ops.size() == 0){
        //     continue;
        // }
        // for(int i=0; i<ops.size(); i++){
        //     cout << ops[i] << endl;
        // }


        // for(int i=0; i<s.length()-1; i++){
        //     if(v[0].first == v[2].first) break;
        //     if(s[i] != s[i+1]){
        //         if(s[i] != v[0].second || s[i+1] != v[0].second){
        //             int ct =0;
        //             while(ct < 2*(v[2].first - v[1].first)){
        //                 ops.push_back(i+1+off);
        //                 ct++;
        //             }
        //             off+=2*(v[2].first - v[1].first);
        //             v[1].first = v[2].first;
        //             v[0].first += v[2].first - v[1].first;
        //         }
        //     }
        // }





        // vector<int>ops;
        // int mx = max(ct[0], max(ct[1], ct[2]));
        // bool flag = false;
        // int mn = 1e18;
        // int mni =-1;
        // for(int i=0; i<3; i++){
        //     if(ct[i] < mn){
        //         mn = ct[i];
        //         mni = i;
        //     }
        // }
        
    }
}