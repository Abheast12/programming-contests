#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n, q;
        cin >> n >> q;
        vector<vector<long long>>v(n+1, vector<long long>(n+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> v[i][j];
            }
        }
        vector<vector<long long>>prefx(n+1, vector<long long>(n+1));
        vector<vector<long long>>prefy(n+1, vector<long long>(n+1));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                prefx[i][j] = i*v[i][j];
                prefy[i][j] = j*v[i][j];
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                v[i][j] += v[i][j-1];
                v[i][j] += v[i-1][j];
                v[i][j] -= v[i-1][j-1];
            }
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                prefx[i][j] += prefx[i][j-1];
                prefx[i][j] += prefx[i-1][j];
                prefx[i][j] -= prefx[i-1][j-1];
                prefy[i][j] += prefy[i-1][j];
                prefy[i][j] += prefy[i][j-1];
                prefy[i][j] -= prefy[i-1][j-1];
            }
        }
        while(q--){
            long long x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long long ans = prefx[x2][y2] - prefx[x1-1][y2] - prefx[x2][y1-1] + prefx[x1-1][y1-1];
            ans*=(y2-y1+1);
           
            long long tmp = v[x2][y2] - v[x1-1][y2] - v[x2][y1-1] + v[x1-1][y1-1];
            long long ytmp = prefy[x2][y2] - prefy[x1-1][y2] - prefy[x2][y1-1] + prefy[x1-1][y1-1];
            ans+=(tmp+ytmp);
            tmp*=(x1*(y2-y1+1)+y1);
            ans-=tmp;
            // cout << ans << " " << tmp << " " << ytmp << " " << endl;
            // ans+=ytmp;
            // ans+=tmp;
            cout << ans << " ";
        }
        cout << endl;
    }
}