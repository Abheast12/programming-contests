#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x;
        cin >> x;
        int a[33];
        for(int i=0; i<33; i++){
            a[i] = 0;
        }
        int j = 0;
        while(x!=0){
            a[j] = x&1;
            x = x>>1;
            j++;
        }
        int last = -1;
        int len = 0;
        for(int i=0; i<=j; i++){
            if(last==-1 && a[i] == 1){
                last =i;
            }
            else if(a[i]==0 && last!=-1){
                if(i-last>1){
                    a[i] = 1;
                    a[last] = -1;
                    last = i;
                }
                else{
                    last = -1;
                }
            }
            else if(a[i] == 1 && last!=-1){
                a[i] = 0;
            }
            if(a[i]==1){
                len = i;
            }
        }
        cout << len+1 << endl;
        for(int i=0; i<=len; i++){
            cout << a[i] << " ";
        }
        cout << endl;


    }
}