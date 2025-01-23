#include<vector>
#include<iostream>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        int tot  =0;
        set<int>s;
        set<int>s2;
        s.insert(v[0]);
        for(int i=1; i<n; i++){
            if(v[i] < *s.begin()){
                s.insert(v[i]);
            }
            else if(v[i] < *s2.begin() || s2.empty()){
                s2.insert(v[i]);
                tot++;
            }
        }
        cout << tot << endl;
    }
}