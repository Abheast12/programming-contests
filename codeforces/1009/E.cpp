#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;  
long long getRandomInRange(long long mn, long long mx) {
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(mn, mx);
    return dis(gen);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << "? 1 2 3" << endl;
        cout.flush();
        int a;
        cin >> a;
        if(a == 0){
            cout << "! 1 2 3" << endl;
            cout.flush();
            continue;
        }
        vector<int>arr(3);
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;
        for(int i=1; i<75; i++){
            int x = getRandomInRange(0, 2);
            arr[x] = a;
            cout << "? " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
            cout.flush();
            int b;
            cin >> b;
            if(b == 0){
                cout << "! " << arr[0] << " " << arr[1] << " " << arr[2] << endl;
                cout.flush();
                break;
            }
            a = b;
        }
    }
}