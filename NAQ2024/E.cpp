#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<int, int>m;
    set<int>ans;
    for(int i=0; i<10*n; i++){
        for(int j=0; j<5; j++){
            int a;
            cin >> a;
            m[a]++;
            if(m[a] > 2*n){
                ans.insert(a);
            }
        }
    }
    
    if(ans.size()==0){
        cout << -1 << endl;
        return 0;
    }
    for(auto it : ans){
        cout << it << " ";
    }
}