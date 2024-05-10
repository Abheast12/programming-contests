#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        vector<int>a;
        vector<int>b;
        int n, k;
        cin >> n >> k;
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for(int j=0; j<n; j++){
            int x;
            cin >> x;
            b.push_back(x);
        }
        vector<pair<pair<int,int>, int>>c;
        for(int j=0;j<n; j++){
            if(a[j] < b[j]){
                c.push_back({{min(a[j]-b[j], -1*a[j]), -1*a[j]}, a[j]-b[j]});
            }
            
        }
        sort(c.begin(), c.end());
        int tot = 0;
        if(k >= c.size()){
            cout << 0 << endl;
        }
        else{
        for(int j=0; j<k; j++){
            tot+=(-1*c[j].first.second);
        }
        int prof = 0;
        for(int j=k; j<n; j++){
            if(c[j].first.first >=0){
                break;
            }
            else{
                prof+=(-1*c[j].second);
            }
        }
        if(prof > tot){
            cout << prof - tot << endl;
        }
        else cout << 0 << endl;
        
        }
        a.clear();
        b.clear();
        c.clear();
    }
}