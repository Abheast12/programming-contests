#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v1;
vector<int>v2;
int main(){
    int n, t;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            v1.push_back(a);
        }
        sort(v1.begin(), v1.end());
        for(int j=0; j<n; j++){
            int a;
            cin >> a;
            v2.push_back(a);
        }
        sort(v2.begin(), v2.end());
        long long idx1 = 0, idx2 = 0;
        long long ans = 1;
        if(v2[idx2] >= v1[idx1]) cout << 0 << endl;
        else{
            while(idx1 != n){
                if(idx2 == n){
                    ans = (ans * (long long) (idx2 - idx1)) % 1000000007;
                    // cout << idx1 << " " << idx2 << endl;
                    idx1++;
                }
                else if(v2[idx2] < v1[idx1]){
                    idx2++;
                }
                else{
                    ans = (ans * (long long) (idx2 - idx1)) % 1000000007;
                    // cout << idx1 << " " << idx2 << endl;

                    idx1++;
                }
            }
            if(idx1 == n && idx2 != n){
                cout << 0 << endl;
            }
            else{
                cout << ans << endl;
            }
        }
        v1.clear();
        v2.clear();
    }
}