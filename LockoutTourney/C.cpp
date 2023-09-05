#include<numeric>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int l1 = s1.length()-2;
    int l2 = s2.length()-2;
    int l3 = s3.length()-2;
    int l4 = s4.length()-2;
    // cout << l1 << " " << l2 << " " << l3 << " " << l4 << endl;
    vector<int>v;
    if(l1*2<=l2 && l1*2<=l3 && l1*2<=l4){
        v.push_back(l1);
    }
    if(l2*2<=l1 && l2*2<=l3 && l2*2<=l4){
        v.push_back(l2);
    }
    if(l3*2<=l1 && l3*2<=l2 && l3*2<=l4){
        v.push_back(l3);
    }
    if(l4*2<=l1 && l4*2<=l2 && l4*2<=l3){
        v.push_back(l4);
    }
    
    if(l1/2>=l2 && l1/2>=l3 && l1/2>=l4){
        v.push_back(l1);
    }
    if(l2/2>=l1 && l2/2>=l3 && l2/2>=l4){
        v.push_back(l2);
    }
    if(l3/2>=l1 && l3/2>=l2 && l3/2>=l4){
        v.push_back(l3);
    }
    if(l4/2>=l1 && l4/2>=l2 && l4/2>=l3){
        v.push_back(l4);
    }

    if(v.size()>=2 || v.size()<1){
        cout << "C" << endl;
    }
    else{
        if(v[0]==l1){
            cout << "A" << endl;
        }
        if(v[0]==l2){
            cout << "B" << endl;
        }
        if(v[0]==l3){
            cout << "C" << endl;
        }
        if(v[0]==l4){
            cout << "D" << endl;
        }
    }
}