#include<iostream>
#include<vector>

using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << "? 1 " << n/4 << endl;
        cout.flush();
        int res1, res2;
        cin >> res1;
        cout << "? " << n/4+1 << " " << n/2 << endl;
        cout.flush();
        cin >> res2;
        bool t1 = false, t2 = false;
        // t1 indicates if 1 is in first half
        // t2 indicates if k > n/2
        if(res1!=res2){
            t1 = true;
        }
        int res3;
        cout << "? 1 " << n/2 << endl;
        cout.flush();
        cin >> res3;
        if(t1 && res3 == 1){
            t2 = true;
        }
        else if(!t1 && res3 == 0){
            t2 = true;
        }
        if(t2){
            long long tmp;
            if(t1){
                tmp = 1;
            }
            else{
                tmp = n;
            }
            long long l = n/2+1;
            long long r = n;
            long long ans;
            while(l<=r){
                long long mid = (l+r)/2;
                if(tmp==1){
                    cout << "? 1 " << mid << endl;
                }
                else{
                    long long tmp2 = n-mid+1;
                    cout << "? " << tmp2 << " " << n << endl;
                }
                cout.flush();
                int res;
                cin >> res;
                if(res == 0){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            cout << "! " << ans << endl;
            cout.flush();
        }
        else{
            long long tmp;
            if(t1){
                tmp = n;
            }
            else{
                tmp = 1;
            }
            long long ans;
            long long l = 1, r = n/2;
            while(l<=r){
                long long mid = (l+r)/2;
                if(tmp == 1){
                    cout << "? 1 " << mid << endl;
                }
                else{
                    cout << "? " << n-mid+1 << " " << n << endl;
                }
                cout.flush();
                int res;
                cin >> res;
                if(res == 1){
                    ans = mid;
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            cout << "! " << ans << endl;
            cout.flush();
        }

    }
}