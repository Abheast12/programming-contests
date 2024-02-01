#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<vector<pair<string, int>>> v;
vector<pair<string, int>> cases(int bg, int ed, string s, char addb, char adde, bool isBg, bool isEd){
    vector<pair<string, int>> vv;
    char c1 = s[bg];
    char c2 = s[ed];
    if(c1=='0' && c2=='1'){
        string temp = "";
        
        for(int i=bg; i<=ed; i++){
            temp+='0';
        }
        string temp2 = temp;
        if(isBg){
            temp2=addb + temp;
        } 
        if(isEd){
            temp2+=adde;
        }
        vv.push_back({temp2, 1});
        int tt = 1;
        for(int i=ed-bg-1; i>=0; i-=2){
            temp[i] = '1';
            tt+=2;
            temp2 = temp;
            if(isBg){
                temp2=addb + temp;
            } 
            if(isEd){
                temp2+=adde;
            }
            vv.push_back({temp2, tt});
        }
    }
    else if(c1=='1' && c2=='0'){
        string temp = "";
        for(int i=bg; i<=ed; i++){
            temp+='0';
        }
        string temp2 = temp;
        if(isBg){
            temp2=addb + temp;
        } 
        if(isEd){
            temp2+=adde;
        }
        vv.push_back({temp2, 1});
        int tt = 1;
        for(int i=ed-bg; i>=0; i-=2){
            temp[i] = '1';
            tt+=2;
            temp2 = temp;
            if(isBg){
                temp2=addb + temp;
            } 
            if(isEd){
                temp2+=adde;
            }
            vv.push_back({temp2, tt});
        }
    }
    else if(c1=='0' && c2=='0'){
        string temp = "";
        for(int i=bg; i<=ed; i++){
            temp+='0';
        }
        string temp2 = temp;
        if(isBg){
            temp2=addb + temp;
        } 
        if(isEd){
            temp2+=adde;
        }
        vv.push_back({temp2, 0});
        int tt = 0;
        for(int i=ed-bg; i>=0; i-=2){
            temp[i] = '1';
            tt+=2;
            temp2 = temp;
            if(isBg){
                temp2=addb + temp;
            } 
            if(isEd){
                temp2+=adde;
            }
            vv.push_back({temp2, tt});
        }
    }
    else{
        string temp = "";
        string temp2 = "";
        for(int i=bg; i<=ed; i++){
            temp+='0';
            temp2+='1';
        }
        vv.push_back({temp2, 0});
        temp2 = temp;
        // string temp2 = temp;
        if(isBg){
            temp2=addb + temp;
        } 
        if(isEd){
            temp2+=adde;
        }
        vv.push_back({temp2, 2});
        int tt = 2;
        for(int i=ed-bg-1; i>=0; i-=2){
            temp[i] = '1';
            tt+=2;
            temp2 = temp;
            if(isBg){
                temp2=addb + temp;
            } 
            if(isEd){
                temp2+=adde;
            }
            vv.push_back({temp2, tt});
        }
    
    }
    return vv;
}
vector<pair<string, int>> fx(int bg, int ed, string s){
    vector<pair<string, int>>vv;
    if(bg==0){
        if(ed==s.length()-1){
            if(ed-bg+1!=2){
                s[bg] = '0';
                s[ed] = '1';
                vv = cases(bg+1, ed-1, s, '0', '1', true, true);
                // s[bg] = '1';
                // s[ed] = '0';
                // cases(bg+1, ed-1, s, '1', '0', true, true);
                s[bg] = '0';
                s[ed] = '0';
                vector<pair<string, int>>vv2 = cases(bg+1, ed-1, s, '0', '0', true, true);
                vv.insert(vv.end(), vv2.begin(), vv2.end());
                // s[bg] = '1';
                // s[ed] = '1';
                // cases(bg+1, ed-1, s, '1', '1', true, true);
            }
            else{
                
                vv.push_back({"00", 0});
                vv.push_back({"01", 1 });
            }
        }
        else{
            s[bg] = '0';
            vv = cases(bg+1, ed, s, '0', '0', true, false);
            s[bg] = '1';
            vector<pair<string, int>>vv2 = cases(bg+1, ed, s, '1', '0', true, false);
            vv.insert(vv.end(), vv2.begin(), vv2.end());
        }
    }
    else{
        if(ed==s.length()-1){
            s[ed] = '1';
            vv = cases(bg, ed-1, s, '0', '1', false, true);
            s[ed] = '0';
            vector<pair<string, int>>vv2 = cases(bg, ed-1, s, '0', '0', false, true);
            vv.insert(vv.end(), vv2.begin(), vv2.end());

        }
        else{
            vv = cases(bg, ed, s, '0', '0', false, false);
        }
    }
    return vv;
}
int main(){
    int n, t, k;
    cin >> t;
    for(int i=0; i<t; i++){
        string s;
        cin >> n >> k;
        cin >> s;
        // string ans = solve(s, k);
        int bg = -1;
        int ed = -1;
        for(int j=0; j<n; j++){
            if(s[j]=='?' && bg==-1){
                bg = j;
            }
            else if(bg!=-1 && s[j]!='?'){
                ed = j-1;
                //handle if bg=ed here
                vector<pair<string, int>>vv;
                if(bg==ed){
                    
                    if(bg==0){
                        if(s[ed+1]=='0'){
                            vv.push_back({"0", 0});
                            vv.push_back({"1", 1});
                        }
                        else{
                            vv.push_back({"1", 0});
                            vv.push_back({"0", 2});
                            // s[bg] = '0';
                        }
                    }
                    else{
                        if(s[bg-1]=='0' && s[ed+1]=='0'){
                            vv.push_back({"0", 0});
                            vv.push_back({"1", 2});
                        }
                        else{
                            vv.push_back({"0", 1});
                            // s[bg] = '0';
                        }
                    }
                }
                else{
                    // vector<pair<int, string>>vv;
                    vv = fx(bg, ed, s);
                }
                sort(vv.begin(), vv.end());
                v.push_back(vv);
                bg = -1;
                ed = -1;
            }
        }
        if(bg!=-1){
            ed = n-1;
            vector<pair<string, int>>vv;
            if(bg==ed && bg==0){
                vv.push_back({"0", 0});
            }
            else if(bg==ed){
                if(s[bg-1]=='0'){
                    vv.push_back({"0", 0});
                    vv.push_back({"1", 1});
                }
                else{
                    vv.push_back({"1", 0});
                    vv.push_back({"0", 1});
                }
            }
            else{
                vv = fx(bg, ed, s);
            }
            sort(vv.begin(), vv.end());
            v.push_back(vv);
        }
        int totk = 0;
        for(int j=0; j<n-1; j++){
            if(s[j]!=s[j+1] && s[j]!='?' && s[j+1]!='?'){
                totk++;
            }
        }
        if(totk>=k){
            cout << "Impossible" << endl;
        }
        else{
            map<pair<int ,int>, int>mp;
            for(int j=(int)v.size()-1; j>=0; j--){

                for(int jk=0; jk<v[j].size(); jk++){
                    int kk = v[j][jk].second;
                    // if(totk+kk<)
                }
            }
        }
        
        // cout << ans << endl;
    }

}