#include <iostream>
using namespace std;

int maxsz = 1;
int link[100100], sz[100100];

int find(int x) {
    while (x != link[x]) {
        // if(link[x] != link[link[x]]) link[x] = link[link[x]];
        x = link[x];
    }
    return x;
}
bool same(int a, int b) {
    return find(a) == find(b);
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (sz[a] < sz[b]) swap(a,b);
    sz[a] += sz[b];
    maxsz = max(maxsz, sz[a]);
    link[b] = a;
}
int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) link[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1;
    int ans = n;
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        if(!same(a, b)){
            unite(a, b);
            ans--;
        }
        cout << ans << " " << maxsz << endl;
    }

}