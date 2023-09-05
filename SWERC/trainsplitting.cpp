#include<iostream>
#include<set>
using namespace std;
set<int>v[100];
int main(){
    int t, n, m;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> m;
        int a,b;
        if(m == (n)*(n-1)/2){
            cout << 3 << endl;
            for(int j=1; j<=m; j++){
                cin >> a >> b;
                if((a==1 && b==2) || (b==1 && a==2)){
                    cout << 3;
                }
                else if(a==1 || b==1){
                    cout << 1;
                }
                else if(a==2 || b==2){
                    cout << 2;
                }
                else cout << 3;
                if(j==m) cout << endl;
                else cout << " ";
            }
        }
        else{
        for(int j=1; j<=m; j++){
            cin >> a >> b;
            v[a].insert(j);
            v[b].insert(j);
        }
        int val = -1;
        for(int j=1; j<=n; j++){
            if(v[j].size()<n-1){
                val = j;
                break;
            }
        }
        
        cout << 2 << endl;
        for(int j=1; j<=m; j++){
            if(v[val].find(j)!=v[val].end()){
                if(j!=m) cout << 2 << " ";
                else cout << 2 << endl;
            }
            else {
                if(j!=m) cout << 1 << " ";
                else cout << 1 << endl;
            }
        }
        
        }
        for(int j=1; j<=n; j++){
            v[j].clear();
        }
    }
}