#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        long long k, x, a;
        cin >> k >> x >> a;
        long long na = a;
        bool t = false;
        for(int j=1; j<=x; j++){
            if(na<=0){
                t = true;
                cout << "NO" << endl;
                break;
            }
            if(j==1) na--;
            else{
                long long dif = a +1-na;
                long long bet = ceil((double)dif/(double)(k-1));
                // cout << j << " " << dif << " " << bet << endl;
                na-=bet;
            }
        }
        if(!t){
            if(na*(k)>a){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        

    }
}