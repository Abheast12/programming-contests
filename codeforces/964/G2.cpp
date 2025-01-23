#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int l = 2, r = 999;
        int ans = -1;
        while(l < r){
            int dif = r-l;
            int mid = l + dif/3;
            int mid2 = r - dif/3;
            cout << "? " << mid << " " << mid2 << endl;
            cout.flush();
            int val;
            cin >> val;
            if(val == mid*mid2){
                l = mid2+1;
            }
            else if(val == (mid+1)*(mid2+1)){
                r = mid;
                ans = mid;
            }
            else{
                ans = mid2;
                r = mid2;
                l = mid+1;
            }
        }
        cout << "! " << ans << endl;
    }
}