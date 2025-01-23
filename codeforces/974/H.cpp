#include<iostream>
#include<vector>
#include<map>
#include<random>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<int>v(n);
        map<int, long long>mp;
        vector<int>x(n+1);
        x[0] = 0;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(!mp[v[i]]){
                std::random_device rd;
                std::mt19937_64 gen(rd());  // 64-bit Mersenne Twister
                long long mn = 1;
                long long mx = 1e18;
                std::uniform_int_distribution<long long> dis(mn, mx);
                long long random_number = dis(gen);
                mp[v[i]] = random_number;
            }
            x[i+1] = x[i]^mp[v[i]];
        }
        for(int i=0; i<q; i++){
            int l, r;
            cin >> l >> r;
            if(x[r] == x[l-1]){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }

    }
}