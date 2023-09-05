#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

vector<string>v;
string s[9] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
int vis[10];
void recurse9(string s2, string prev){
    if(s2.length() == 9) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse9(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse8(string s2, string prev){
    if(s2.length() == 8) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse8(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse7(string s2, string prev){
    if(s2.length() == 7) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse7(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse6(string s2, string prev){
    if(s2.length() == 6) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse6(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse5(string s2, string prev){
    if(s2.length() == 5) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse5(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse4(string s2, string prev){
    if(s2.length() == 4) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse4(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse3(string s2, string prev){
    if(s2.length() == 3) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse3(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
void recurse2(string s2, string prev){
    if(s2.length() == 2) {
        v.push_back(s2);
        return;
    }
    for(int i=0; i<9; i++){
        if(!vis[i]){
            if(prev=="1" && s[i] != "3" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "2" && s[i] != "8") {
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "3" && s[i] != "1" && s[i] != "7" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "4" && s[i] != "6"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev=="5" || prev==""){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "6" && s[i] != "4"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "7" && s[i] != "1" && s[i] != "3" && s[i] != "9"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "8" && s[i] != "2"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
            else if(prev == "9" && s[i] != "1" && s[i] != "3" && s[i] != "7"){
                vis[i] = 1;
                string s3 = s2+s[i];
                string s4 = s[i];
                recurse2(s3, s4);
                vis[i] = 0;
            }
        }
    }
    return;
}
// void recurse1(string s2){
//     if(s2.length() == 1) {
//         v.push_back(s2);
//         return;
//     }
//     for(int i=0; i<9; i++){
//         if(!vis[i]){
//             vis[i] = 1;
//             string s3 = s2+s[i];
//             recurse1(s3);
//             vis[i] = 0;
//         }
//     }
// }
void check(string a, string b){
    int pos = 0;
    while(pos<v.size()){
        // cout << "here" << endl;
        if(v[pos].find(a) !=-1 && v[pos].find(b) !=-1 && abs((int)v[pos].find(a)-(int)v[pos].find(b)) == 1){
            cout << v[pos] << endl;
            // cout << v[pos] << endl;
            // v.erase(v.begin()+pos);
            // pos--;
        }
        pos++;
    }
}
int main(){
    recurse9("", "");
    recurse8("", "");
    recurse7("", "");
    recurse6("", "");
    recurse5("", "");
    recurse4("", "");
    recurse3("", "");
    recurse2("", "");
    // recurse1("");
    // check("1", "9");
    // check("1", "3");
    // check("4", "6");
    // check("7", "9");
    // check("1", "7");
    // check("2", "8");
    // check("3", "9");
    // check("3", "7");
    // cout << v[v.size()-1] << endl;
    // cout << "end" << endl;
    int n;
    // cout << v.size() << endl;
    cin >> n;
    vector<pair<string, string>>v2;
    for(int i=0; i<n; i++){
        string a, b;
        cin >> a >> b;
        v2.push_back({a, b});
    }
    long long tot = 0;
    for(int j=0; j<v.size(); j++){
        
        int temptot = 0;
        if(v[j].size()>=n){
        for(int k=0; k<n; k++){
            if(v[j].find(v2[k].first) != -1 && v[j].find(v2[k].second) != -1 && abs((int)v[j].find(v2[k].first)-(int)v[j].find(v2[k].second)) == 1){
                temptot++;
            }
            // cout << temptot << endl;
        }
        }
        if(temptot == n) tot++;
    }
    // cout << v2.size() << endl;
    // if(n==0) cout << v.size() << endl;
    cout << tot << endl;
}