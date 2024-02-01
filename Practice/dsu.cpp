#include <iostream>
using namespace std;

int maxsz = 1;
int root[100100], sz[100100];

int find(int x) {
    while (x != root[x]) {
        // if(root[x] != root[root[x]]) root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unite(int a, int b) {
    int roota = find(a);
    int rootb = find(b);
    if (sz[roota] < sz[rootb]){
        sz[rootb]+=sz[roota];
        maxsz = max(maxsz, sz[rootb]);
        root[roota] = rootb;
    } else{
        sz[roota] += sz[rootb];
        maxsz = max(maxsz, sz[roota]);
        root[rootb] = roota;
    }
    
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    int ans = n;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(!(find(a)==find(b))){
            unite(a, b);
            ans--;
        }
        cout << ans << " " << maxsz << endl;
    }

}