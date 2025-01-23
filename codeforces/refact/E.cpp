#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

// long long maxsz = 1;
// int find(int x, vector<long long>&root) {
//     while (x != root[x]) {
//         if(root[x] != root[root[x]]) root[x] = root[root[x]];
//         x = root[x];
//     }
//     return x;
// }
// void unite(int a, int b, vector<long long>&root, vector<long long>&sz) {
//     int roota = find(a, root);
//     int rootb = find(b, root);
//     if(roota == rootb) return;
//     if (sz[roota] < sz[rootb]){
//         swap(roota, rootb);
//     }
//     sz[roota] += sz[rootb];
//     maxsz = max(maxsz, sz[roota]);
//     root[rootb] = roota;
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int>minFactor(4e5+1);
    // vector<long long>root(4e5+1), sz(4e5+1);
    // for (int i = 1; i <= 4e5; i++) root[i] = i;
    // for (int i = 1; i <= 4e5; i++) sz[i] = 1;
    // // unite(2, 4, root, sz);
    int m = 4e5;
    vector<bool> isPrime(m+1, true);
    isPrime[0] = isPrime[1] = false;
    // vector<vector<int>> factors(m+1);
    for (int i = 2; i <= m; i++) {
        if (isPrime[i]) {
            // factors[i].push_back(i);
            for (int j = i * 2; j <= m; j += i) {
                isPrime[j] = false;
                // factors[j].push_back(i);
            }
        }
    }
    for(int i=3; i<=4e5; i+=2){
        for(int j=3; j*j<=i; j+=2){
            if(i%j==0){
                minFactor[i] = j;
                break;
            }
        }
    }


    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        int primes = 0;
        int firstPrime = -1;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(isPrime[v[i]]){
                primes++;
                firstPrime = v[i];
            }
        }
        if(primes>1){
            cout << -1 << endl;
        }
        else if(primes==0){
            cout << 2 << endl;
        }
        else{
            bool t = true;
            for(int i=0; i<n; i++){
                if(v[i] == firstPrime) continue;
                if(v[i]%2==0 && v[i]>=2*firstPrime) continue;
                if(v[i]-minFactor[v[i]]>=2*firstPrime) continue;
                t = false;
                cout << -1 << endl;
                break;
            }
            if(t){
                cout << firstPrime << endl;
            }
        }
        // bool t = false;
        // for(int i=1; i<n; i++){
        //     if(find(v[i], root) != find(v[i-1], root)){
        //         cout << -1 << endl;
        //         t=true;
        //         break;
        //     }
        // }
        // if(!t){
        //     cout << find(v[0], root) << endl;
        // }

    }
}