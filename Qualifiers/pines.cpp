#include <iostream>
#include<vector>
using namespace std;
vector<int>v;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=1; i<=n+1; i++){
        v.push_back(i);
    }
    bool b = true;
    for(int i=0; i<n; i++){
        if(s[i]=='A'){
            if(!b){
                if(v[i]<v[i+1]){
                    int tmp = v[i];
                    v[i] = v[i+1];
                    v[i+1] = tmp;
                }
                b = true;
            }
            else if(b){
                if(v[i]>v[i+1]){
                    int tmp = v[i];
                    v[i] = v[i+1];
                    v[i+1] = tmp;
                }
                b = false;
            }
        }
    }
    for(int i=0; i<n+1; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}