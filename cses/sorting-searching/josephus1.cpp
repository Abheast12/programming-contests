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

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
    cin >> n;
    set<int>v;
    for(int i=1; i<=n; i++){
        v.insert(i);
    }
    auto it = v.begin();
    ++it;
    while(v.size() >= 1){
        // cout << "here" << endl;
        if(it == v.end()){
            it = v.begin();
        }
        cout << *it << " ";
        it = v.erase(it);
        if(v.size() == 0){
            break;
        }
        if(it == v.end()){
            it = v.begin();
        }
        ++it;
    }
    cout << endl;

    
}