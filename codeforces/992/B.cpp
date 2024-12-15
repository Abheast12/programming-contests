#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int t;
    cin >> t;
    map<int, long long>mp;
    mp[1] = 1;
    mp[2] = 4;
    long long res = 4;
    int i=3;
    while(res<=1e5+1){
        res = (res+1)*2;
        mp[i] = res;
        i++;
    }
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=100; i++){
            if(mp[i]>=n){
                cout << i << endl;
                break;
            }
        }
    }
}