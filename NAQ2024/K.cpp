#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
int calcPoints(long long a, long long b){
    if(abs(a-b) <= 15){
        return 7;
    }
    else if(abs(a-b) <=23){
        return 6;
    }
    else if(abs(a-b) <=43){
        return 4;
    }
    else if(abs(a-b) <=102){
        return 2;
    }
    return 0;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<long long>v1(n);
    vector<long long>v2(m);
    vector<vector<pair<long long, long long>>>dif(n);
    
    for(int i=0; i<n; i++){
        cin >> v1[i];
    }
    for(int i=0; i<m; i++){
        cin >> v2[i];
    }
    long long ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dif[i].push_back({abs(v1[i] - v2[j]), j});
        }
    }
    for(int i=0; i<n; i++){
        sort(dif[i].begin(), dif[i].end());
    }


}