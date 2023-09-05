#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        vector<int>v;
        vector<int>changes;
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            
            v.push_back(a);
            if(j!=0){
                if(v[j]!=v[j-1]){
                    changes.push_back(j);
                }
            }
        }
        if(v[n-1] == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int j=0; j<n-changes.size(); j++){
                if(j==n-1) cout << 0 << endl;
                else cout << 0 << " ";
            }
            for(int j=0; j<changes.size(); j++){
                
                if(j==changes.size()-1) cout << changes[j] << endl;
                else cout << changes[j] << " ";
            }
            
        }
    }
}