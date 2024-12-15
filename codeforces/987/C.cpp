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
        long long n;
        cin >> n;
        if(n%2==0){
            for(int i=1; i<=n/2; i++){
                cout << i << " " << i << " ";
            }
            cout << endl;
        }
        else{
            if(n<=25){
                cout << -1 << endl;
            }
            else{
                int cur = 3;
                int tot = 0;
                for(int i=1; i<=n; i++){
                    if(i==1 || i==10 || i==26){
                        cout << 1 << " ";
                    }
                    else if(i == 27 || i == 23){
                        cout << 2 << " ";
                    }
                    else{
                        cout << cur << " ";
                        tot++;
                        if(tot==2){
                            cur++;
                            tot = 0;
                        }
                    }
                }
            }
        }
    }
}