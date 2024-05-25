#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    int arr[100100]; 
    int val1[100100];
    // int val2[100100];
    while(t--){
        int n;
        cin >> n;
        int f = 0;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i]==n){
                f = i%2;
            }
        }
        vector<pair<int, int>>v1;
        vector<pair<int, int>>v2;
        for(int i=0; i<n-1; i+=2){
            v1.push_back({arr[i], i});
        }
        for(int i=1; i<n; i+=2){
            v2.push_back({arr[i], i});
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int j = n;
        if(f==0){
            
            for(int i=0; i<v1.size(); i++){
                val1[v1[i].second] = j;
                j--;
            }
            for(int i=0; i<v2.size(); i++){
                val1[v2[i].second] = j;
                j--;
            }
        }
        else{
            for(int i=0; i<v2.size(); i++){
                val1[v2[i].second] = j;
                j--;
            }
            for(int i=0; i<v1.size(); i++){
                val1[v1[i].second] = j;
                j--;
            }
        }
        for(int i=0; i<n; i++){
            cout << val1[i] << " ";
        }
        cout << endl;
        for(int i=0; i<n; i++){
            val1[i] = 0;
            arr[i] = 0;
        }
        v1.clear();
        v2.clear();
        

    }
}