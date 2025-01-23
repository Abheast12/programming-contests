#include<iostream>
#include<vector>

using namespace std;  

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n+1);
        for(int i=1; i<=n; i++){
            cin >> v[i];
        }
        vector<int>fd(n+1, 0);
        fd[0] = 1;
        for(int i=1; i<=n; i++){
            if(i-v[i]-1 >= 0){
                if(fd[i-v[i]-1]){
                    fd[i] = 1;
                }
            }
            if(fd[i-1]){
                if(i+v[i]<=n){
                    fd[i+v[i]] = 1;
                }
            }
        }
        // for(int i=0; i<=n; i++){
        //     cout << fd[i] << " ";
        // }
        if(fd[n]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        // vector<int>bd(n+2, 0);
        // bd[n+1] = 1;
        // for(int i=2; i<=n; i++){
        //     if(i-v[i]-1 >= 0){
        //         fd[i] = fd[i-v[i]-1];
        //     }
        // }
        // for(int i=n-1; i>=1; i--){
        //     if(i+v[i]+1 <= n+1){
        //         bd[i] = bd[i+v[i]+1];
        //     }
        // }
        // bool ok = false;
        // for(int i=0; i<=n; i++){
        //     if(fd[i] && bd[i+1]){
        //         ok = true;
        //         break;
        //     }
        // }
        // if(ok){
        //     cout << "YES" << endl;
        // }
        // else{
        //     cout << "NO" << endl;
        // }

    }
}