#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long n, x;
        cin >> n >> x;
        long long a[200200];
        long long b[30];
        long long curb[30];
        for(int i=0; i<30; i++){
            b[i] = 0;
            curb[i] = 0;
        }
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<30; j++){
                if(a[i] & (1<<j)){
                    b[j]++;
                }
            }
        }
        int bit =-1;
        for(int i=0; i<30; i++){
            if(((1<<i) < x) && ((x | (1<<i)) > x)){
                bit = i;
            }
            else if((1<<i) >= x){
                break;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            bool t = true;
            for(int j=0; j<30; j++){
                if(a[i] & (1<<j)){
                    b[j]--;
                    // cout << b[2] << endl;
                    curb[j]++;
                }
                if((b[j] % 2 != 0) && ((1<<j) >x)){
                    // cout << "here" << i << endl;
                    t = false;
                }
            }
            if(t && bit!=-1 && b[bit]%2==1){
                // cout << "here" << endl;
                bool tt = false;
                for(int j=bit+1; j<30; j++){
                    if((1<<j)<=x){
                        if(b[j]%2==0){
                            tt = true;
                            break;
                        }
                    }
                    else break;
                }
                if(!tt) t = false;
            }
            if(t){
                long long temp = 0;
               for(int j=0; j<30; j++){
                    
                    if(curb[j]%2==1){
                        temp+=(1<<j);
                    }
                }
                if(temp >x){
                    t = false;
                }
                else{
                    for(int j=0; j<30; j++){
                        curb[j] = 0;
                    }
                
                }
            }
            if(t){
                ans++;
            }
            else if(!t && i==n-1){
                ans = -1;
            }
            // cout << i << " " << ans << endl;
        }
        cout << ans << endl;
        for(int i=0; i<30; i++){
            b[i] = 0;
            curb[i] = 0;
        }
        for(int i=0; i<n; i++){
            a[i] = 0;
        }


    }
}