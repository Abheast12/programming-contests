#include<iostream>
using namespace std;

int main(){
    unsigned long long x, y, r;
    unsigned long long t;
    cin >> t;
    for(unsigned long long i=0; i<t; i++){
        cin >> x >> y >> r;
        if(y > x) swap(x, y);
        unsigned long long tot = 0;
        bool t = false;
        
        for(long long i=63; i>=0; i--){
            if(!t){
                if(((1ULL << i) & x) != ((1ULL << i) & y)){
                    t = true;
                }
            }
            else{
                if(((1ULL << i) & x) > 0 && ((1ULL << i) & y) == 0){
                    if(r >= tot + (1ULL << i)){
                        tot += (1ULL << i);
                        y = y ^ (1ULL << i);
                        x = x ^ (1ULL << i);
                    }
                }
            }
        }
        cout << x - y << endl;
    }
}