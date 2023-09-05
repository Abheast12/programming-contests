#include<iostream>
#include<vector>
using namespace std;
int arr[100100];
vector<int>v;
int main(){
    int t, n;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        int a;
        for(int j=0; j<n; j++){
            cin >> a;
            arr[a] = j;
        }
        for(int j=0; j<n; j++){
            cin >> a;
            v.push_back(a);
        }
        int tot = 1;
        for(int j=n-1; j>=1; j--){
            if(arr[v[j]]>arr[v[j-1]]){
                tot++;
            }
            else break;
        }
        cout << n - tot << endl;
        v.clear();
    }
}