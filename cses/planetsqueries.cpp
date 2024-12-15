#include<iostream>

using namespace std;
int up[32][200200];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,q;
    cin >> n >> q;
    for(int i=1; i<=n; i++){
        long long a;
        cin >> a;
        up[0][i] = a;
    }
    for(int i=1; i<32; i++){
        for(int j=1; j<=n; j++){
            up[i][j] = up[i-1][up[i-1][j]];
        }
    }
    for(int i=0; i<q; i++){
        long long a, b;
        cin >> a >> b;
        for(long long j=0; j<32; j++){
            if((1 << j) <= b && (b & (1 << j)) != 0){
                a = up[j][a];
            }
        }
        
        cout << a << "\n";
    }
}