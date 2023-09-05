#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> arr[200200];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t;
    
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        long long ans = 0;
        for(int j=0; j<n; j++){
            int a, b;
            cin >> a >> b;
            arr[a].push_back(b);
        }
        for(int j=1; j<=n; j++){
            sort(arr[j].begin(), arr[j].end(), greater<>());
            int minj = min(j, (int)arr[j].size());
            for(int k=0; k<minj; k++){
                ans+=(long long)arr[j][k];
            }
            arr[j].clear();
        }
        cout << ans << endl;
    }


}