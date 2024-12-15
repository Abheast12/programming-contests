#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> par(n);
        cout << "? " << 2 << " " << 3 << endl;
        cout.flush();
        int res;
        cin >> res;
        if(res == -1){
            return 0;
        }
        if(res == 0){
            cout << "! ";
            for(int i=1; i<n; i++){
                if(i!=n-1){
                    cout << i-1 << " ";
                }
                else{
                    cout << i-1 << endl;
                }
                cout.flush();
            }
        }
        else{
            if(n==4){
                cout << "! 0 0 1" << endl;
                cout.flush();
                continue;
            }
            int last;
            for(int i=3; i<=n-1; i++){
                cout << "? " << 1 << " " << i << endl;
                cout.flush();
                int res1;
                cin >> res1;
                if(res1 == -1){
                    return 0;
                }
                if(res1 == 0){
                    par[i] = 1;
                    last = i;
                    break;
                }
            }
            queue<int>cur_parents;
            cur_parents.push(2);
            for(int i=3; i<last; i++){
                par[i] = 0;
                cur_parents.push(i);
            }
            cur_parents.push(last);
            int figured_out = last;
            while(figured_out < n-1 && !cur_parents.empty()){
                int cur = cur_parents.front();
                cur_parents.pop();
                cout << "? " << cur << " " << figured_out+1 << endl;
                cout.flush();
                int res1;
                cin >> res1;
                if(res1==0){
                    par[figured_out+1] = cur;
                    figured_out++;
                    cur_parents.push(figured_out);
                }
                if(res1==-1){
                    return 0;
                }
                // for(int i=figured_out+1; i<=n-1; i++){
                //     cout << "? " << cur << " " << i << endl;
                //     cout.flush();
                //     int res1;
                //     cin >> res1;
                //     if(res1 == -1){
                //         return 0;
                //     }
                //     if(res1 == 0){
                //         par[i] = cur;
                //         figured_out++;
                //     }
                //     else{
                //         cur_parents.push(i);
                //     }
                // }
                // cout << "? " << cur << " " << figured_out+1 << endl;
                // cout.flush();
                // int res2;
                // cin >> res2;
                // if(res2 == -1){
                //     return 0;
                // }
                // if(res2 == 0){
                //     par[figured_out+1] = cur;
                //     figured_out++;
                // }
                // else{
                //     cur_parents.push(figured_out+1);
                // }
            }
            if(figured_out == n-1){
                cout << "! ";
                for(int i=1; i<n; i++){
                    if(i!=n-1){
                        cout << par[i] << " ";
                    }
                    else{
                        cout << par[i] << endl;
                    }
                    cout.flush();
                }
            }

            
        }
    }
}