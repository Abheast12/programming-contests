#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, c;
        cin >> n >> c;
        vector<long long> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        long long ans = 0;
        ans = ((c+1)*(c+2))/2;
        // if((c+1)%2==0){
        //     ans+=(c+3)*(c+1)/4;
        // }
        // else{
        //     ans+=(c+2)*(c+2)/4;
        // }
        long long dif = 0;
        long long odd = 0;
        long long even = 0;
        for(int i=0; i<n; i++){
            long long tmp = (c-a[i])/2;
            tmp++;
            dif+=tmp;
            tmp = a[i]/2;
            tmp++;
            dif+=tmp;
            dif--;
            if(a[i]%2==0){
                dif-=even;
                even++;
            }
            else{
                dif-=odd;
                odd++;
            }

        }
        ans-=dif;
        cout << ans << endl;
        a.clear();
    }
}