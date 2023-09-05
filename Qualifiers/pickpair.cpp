#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<string>v;

int main(){
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++){
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    int k = 0;
    for(int i=0; i<v[0].length(); i++){
        if(v[0][i] == v[1][i]){
            k++;
        } else {
            break;
        }
    }
    for(int i=2; i<n; i+=2){
        int tempk = 0;
        for(int j=0; j<k; j++){
            if(v[i][j] == v[i+1][j]){
                tempk++;
            } else {
                break;
            }
        }
        k = tempk;
    }
    // cout << v[0].length() << endl;
    cout << k << endl;
}