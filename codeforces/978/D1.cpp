#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << "! 1" << endl;
            continue;
        }
        vector<int>arr(n+1, 0);
        arr[1] = 1;
        for(int i=1; i<=n-1; i++){
            cout << "? " << i << " " << i+1 << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x==1){
                arr[i+1] = arr[i];
            }
            else if(x==0){
                arr[i+1] = 1-arr[i];
            }
        }
        int l =1, r = n;
        while(l<r){
            int mid = (l+r+1)/2;
            cout << "? " << mid << " " << l << endl;
            cout.flush();
            int x;
            cin >> x;
            if(x==1){
                if(arr[mid] == arr[l]){
                    l = mid+1;
                }
                else{
                    r = mid;
                }
            }
            else{
                if(arr[mid] != arr[l]){
                    l = mid+1;
                }
                else{
                    r=mid;
                }
            }
            if(r-l<=1){
                break;
            }
        }
        if(l==r){
            cout << "! " << l << endl;
        }
        else{
            int temp = r+1;
            if(temp>n){
                temp = 1;
            }
            cout << "? " << temp << " " << r << endl;
            cout.flush();
            int x;
            cin >> x;
            cout << "? " << r << " " << temp << endl;
            cout.flush();
            int x2;
            cin >> x2;
            if(x==x2){
                cout << "! " << l << endl;
            }
            else{
                cout << "! " << r << endl;
            }
            cout.flush();
            
        }
    }
}