#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        cout << max(n, m)+1 << endl;
    }
}