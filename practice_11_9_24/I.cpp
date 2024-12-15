#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int p1, u1;
    cin >> p1 >> u1;
    vector<int>v1;
    for(int i=0; i<p1; i++){
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for(int i=0; i<u1; i++){
        int a;
        cin >> a;
        v1.push_back(a);
    }
    int p2, u2;
    cin >> p2 >> u2;
    vector<int>v2;
    for(int i=0; i<p2; i++){
        int a;
        cin >> a;
        v2.push_back(a);
    }
    for(int i=0; i<u2; i++){
        int a;
        cin >> a;
        v2.push_back(a);
        
    }
    map<int, int>pin_orders;
    map<int, int>unpin_orders;
    for(int i=0; i<p2; i++){
        pin_orders[v2[i]] = i;
    }
    for(int i=p2; i<p2+u2; i++){
        unpin_orders[v2[i]] = i;
    }
    int start =0, end =v1.size()-1;
    for(int i=0; i<v1.size(); i++){
        if(v1[i] == v2[i] && i < p1 && i < p2){
            start++;
        }
        else{
            break;
        }
    }
    for(int i=v1.size()-1; i>=0; i--){
        if(v1[i] == v2[i] && i >= p1 && i >=p2){
            end--;
        }
        else{
            break;
        }
    }
    if(end <= start){
        cout << 0 << endl;
        return 0;
    }

}