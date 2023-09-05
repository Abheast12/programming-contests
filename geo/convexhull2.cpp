#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;
vector<pair<int, int>>v1;
vector<pair<pair<double, long double>, pair<int, int>>>v;
vector<pair<int, int>>v2;
int main(){
    int n;
    cin >> n;
    int mina = 1E9+1, minb = 1E9+1;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        if(b<minb){
            minb = b;
            mina = a;
        }
        else if(b==minb && a < mina){
            mina = a;
        }
        v1.push_back({a, b});
    }
    for(int i=0; i<n; i++){
        if(v1[i].first!=mina || v1[i].second!=minb){
            if(mina == v1[i].first){
                v.push_back({{3.14159265358979323/2.0, pow(v1[i].second-minb, 2)}, {v1[i].first, v1[i].second}});
            }
            else{
                long double d = atan(((long double)(v1[i].second-minb))/((long double)(v1[i].first-mina)));
                long double dist = (long double)pow(v1[i].second-minb, 2)+(long double)pow(v1[i].first-mina, 2);
                v.push_back({{d, dist}, {v1[i].first, v1[i].second}});
            }
        }
    }
    sort(v.begin(), v.end());
    v2.push_back({mina, minb});
    v2.push_back({v[0].second.first, v[0].second.second});
    int pos = v.size()-1;
    int lastp = -1;
    int firstp = -1;
    while(pos>=1){
        if(v[pos].first.first == v[pos-1].first.first){
            if(lastp==-1){
                lastp = pos;
            }
        }
        else{
            if(lastp!=-1){
                firstp = pos;
                break;
            }
        }
        pos--;
    }
 
    if(lastp != -1 && firstp != -1){
        reverse(v.begin()+firstp, v.begin()+lastp+1);
    }
   
    for(int i=1; i<v.size(); i++){
        while(v2.size()>=2){
            long long a1 = (long long)(v2[v2.size()-1].first - v2[v2.size()-2].first) * (long long)(v[i].second.second - v2[v2.size()-2].second);
            long long a2 = (long long)(v2[v2.size()-1].second - v2[v2.size()-2].second) * (long long)(v[i].second.first - v2[v2.size()-2].first);
            if(a1 - a2 < 0){
                v2.pop_back();
            }
            else break;
        }
        v2.push_back({v[i].second.first, v[i].second.second});
    }
    long long ans = 0;
    cout << v2.size() << endl;
    for(int i=0; i<v2.size(); i++){
        
        cout << v2[i].first << " " << v2[i].second << endl;
    }
}