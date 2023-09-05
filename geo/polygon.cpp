#include<iostream>
#include<vector>
using namespace std;
vector<pair<long long, long long>>v;
int main(){
    int a;
    cin >> a;
    long long ans = 0;
    for(int i=0; i<a; i++){
        long long b, c;
        cin >> b >> c;
        v.push_back({b, c});
    }
    for(int i=0; i<a; i++){
        if(i!=a-1){
            ans+=(v[i].first*v[i+1].second-v[i+1].first*v[i].second);
        }
        else{
            ans+=(v[a-1].first*v[0].second-v[0].first*v[a-1].second);
        }
    }
    cout << abs(ans) << endl;
}