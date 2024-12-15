#include<iostream>
#include<deque>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int q, c;
    cin >> q >> c;
    map<string, int>m;
    deque<string>dq;
    int t;
    set<pair<int, string>>s;
    // struct compare {
    //     inline bool operator()(const std::string& first,
    //             const std::string& second) const
    //     {
    //         return first.size() < second.size();
    //     }
    // };
    for(int i=0; i<q; i++){
        cin >> t;
        if(t==1){
            int c1;
            string st;
            cin>> c1;
            cin >> st;
            m[st] = c1;
            s.insert({st.length(), st});
            // auto it = lower_bound(s.begin(), s.end(), {st.length(), st});
            auto it = s.lower_bound({st.length(), st});
            it++;
            while(it!=s.end() && (((string)(it->second)).find(st) != std::string::npos)){
                s.erase(it);
            }
        }
        else if(t==2){
            string st;
            cin >> st;
            auto it = s.lower_bound({st.length(), st});
            
            if(it!=s.end() && ((string)(it->second)).compare(st)==0){
                cout << m[st] << endl;
            }
            else{
                int tmp2 = 0;
                string tmpstr;
                for(int k=0; k<st.length(); k++){
                    // cout << "here" << endl;
                    if(s.find({k+1, st.substr(0, k+1)})==s.end()){
                        tmp2 = k;
                        tmpstr = st.substr(0, k);
                        break;
                    }
                }
                // if(st.length()>1) it = s.lower_bound({st.length(), st.substr(0, st.length()-1)});
                // else cout << -1 << endl;
                //it!=s.begin()
                if(tmp2>0){
                    // cout << "hre" << endl;
                    int tmp = 0;
                    for(int j=tmp2; j<st.length(); j++){
                        if(st[j]=='R'){
                            tmp--;
                        }
                        else tmp++;
                    }
                    int ans = 0;
                    if((m[tmpstr]+tmp)<0){
                        ans = c + m[tmpstr]+tmp;
                    }
                    else{
                        ans = ((m[tmpstr]+tmp)%c);
                    }
                    cout << ans << endl;
                    // --it;
                    // if(st.find((string)(it->second)) != std::string::npos){
                    //     int tmp = 0;
                    //     // cout << (it->second) << " " << st << endl;
                    //     // int sz = 0;
                    //     // for(int i=0; i<st.length(); i++){
                    //     //     if(s.find(st.substr(0, i+1))==s.end()){
                    //     //         break;
                    //     //     }
                    //     //     else sz++;
                    //     // }
                    //     // if(sz!=0){
                    //         for(int j=(it->second).length(); j<st.length(); j++){
                    //             if(st[j]=='R') tmp--;
                    //             else tmp++;
                    //         }
                    //         // cout << m[it->second] << " " << tmp << endl;
                    //         int ans;
                    //         if((m[it->second]+tmp)<0){
                    //             ans = c + m[it->second]+tmp;
                    //         }
                    //         else{
                    //             ans = ((m[it->second]+tmp)%c);
                    //         }
                    //         cout << ans << endl;
                    //     // }
                    //     // else{
                    //     //     cout << -1 << endl;
                    //     // }
                    // }
                    // else{
                    //     cout << -1 << endl;
                    // }
                }
                else{
                    cout << -1 << endl;
                }

            }
        }
    }
}