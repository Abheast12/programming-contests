#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<string>
using namespace std;
pair<long long, long long> swap(vector<int>&v1, vector<int>&v2, long long res, bool isMult){
    vector<int>cur1;
    vector<int>cur2;
    for(int i=0; i<v1.size()-1; i++){
        cur1.push_back(v1[i]);
        
        for(int j=0; j<v2.size()-1; j++){
            cur2.push_back(v2[j]);
            vector<int>new1 = cur2;
            vector<int>new2 = cur1;
            for(int ii=i+1; ii<v1.size(); ii++){
                new1.push_back(v1[ii]);
            }
            for(int jj=j+1;jj<v2.size(); jj++){
                new2.push_back(v2[jj]);
            }
            long long pow = 1;
            long long a = 0;
            for(int ii=new1.size()-1; ii>=0; ii--){
                a+=new1[ii]*pow;
                pow*=10;
            }
            pow = 1;
            long long b = 0;
            for(int ii=new2.size()-1; ii>=0; ii--){
                b+=new2[ii]*pow;
                pow*=10;
            }
            // cout << a << " " << b << endl;
            if(isMult){
                if(a*b == res){
                    return {a, b};
                }
            }
            else{
                if(a+b == res){
                    return {a, b};
                }
            }
        }
        cur2.clear();
    }
    return {-1, -1};
}
pair<long long, long long> swap2(vector<int>&v1, vector<int>&v2, long long res, bool isMult){
    vector<int>cur1;
    vector<int>cur2;
    for(int i=0; i<v1.size()-1; i++){
        cur1.push_back(v1[i]);
        
        for(int j=0; j<v2.size()-1; j++){
            cur2.push_back(v2[j]);
            vector<int>new1 = cur2;
            vector<int>new2 = cur1;
            for(int ii=i+1; ii<v1.size(); ii++){
                new1.push_back(v1[ii]);
            }
            for(int jj=j+1;jj<v2.size(); jj++){
                new2.push_back(v2[jj]);
            }
            long long pow = 1;
            long long a = 0;
            for(int ii=new1.size()-1; ii>=0; ii--){
                a+=new1[ii]*pow;
                pow*=10;
            }
            pow = 1;
            long long b = 0;
            for(int ii=new2.size()-1; ii>=0; ii--){
                b+=new2[ii]*pow;
                pow*=10;
            }
            if(isMult){
                if(a*res== b){
                    return {a, b};
                }
            }
            else{
                if(a+res== b){
                    return {a, b};
                }
            }
        }
        cur2.clear();
    }
    return {-1, -1};
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long a, b, c;
    char c1;
    char mult;
    cin >> a >> mult >> b >> c1 >> c;
    // cout << a << " " << b << " " << c << " " << mult << endl;
    bool isMult = false;
    if(mult == '*'){
        isMult = true;
    }
    long long a2, b2, c2;
    a2 = a;
    b2 = b;
    c2 =c;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    while(a !=0){
        v1.push_back(a%10);
        a/=10;
    }
    while(b!=0){
        v2.push_back(b%10);
        b/=10;
    }
    while(c!=0){
        v3.push_back(c%10);
        c/=10;
    }
    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());
    reverse(v3.begin(), v3.end());
    // for(int gg : v1){
    //     cout << gg << " ";
    // }
    // cout << endl;
    pair<long long, long long>p1 = swap(v1, v2, c2, isMult);
    if(p1.first!=-1){
        if(isMult){
            cout << p1.first << " * " << p1.second << " = " << c2;
        }
        else{
            cout << p1.first << " + " << p1.second << " = " << c2;
        }
        return 0;
    }
    
    pair<long long, long long>p2 = swap2(v1, v3, b2, isMult);
    if(p2.first!=-1){
        if(isMult){
            cout << p2.first << " * " << b2 << " = " << p2.second;
        }
        else{
            cout << p2.first << " + " << b2 << " = " << p2.second;
        }
        return 0;
    }

    pair<long long, long long>p3 = swap2(v2, v3, a2, isMult);
    if(p3.first!=-1){
        if(isMult){
            cout << a2 << " * " << p3.first << " = " << p3.second;
        }
        else{
            cout << a2 << " + " << p3.first << " = " << p3.second;
        }
        return 0;
    }
    
}