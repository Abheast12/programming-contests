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
        long long l, r;
        cin >> l >> r;

        // long long a = 0, b = 0, c = 0;
        // if(l==0){
        //     cout << r << " " << r-1 << " " << 0 << endl;
        // }
        // else{
        //     long long x = l^r;
        //     cout << r << " " << l << " " << x << endl;
        // }



        long long a =0 , b = 0, c = 0;
        // int last = -1;
        for(long long i=29; i>=0; i--){
            long long bt1 = l&(1LL<<i);
            long long bt2 = r&(1LL<<i);
            if(bt1 == bt2){
                a += bt1;
                // b += bt1;
                // c+= bt1;
            }
            else{
                // last = i;
                a+=bt2;
                break;
            }
        }

        b = a-1;
        if(l == a-1){
            c = a+1;
        }
        else c = a-2;
        // long long f = (1 << (last+1)) - 1;
        // l = l&f;
        // r = r&f;
        // // long long a = 0, b = 0, c = 0;
        // if(l==0){
        //     cout << a+r << " " << a+r-1 << " " << 0 << endl;
        // }
        // else{
        //     long long x = l^r;
        //     cout << a+r << " " << a+l << " " << a+x << endl;
        // }

        cout << a << " " << b << " " << c << endl;
        // cout << last << endl;
        // long long tmp1 = l&(1LL<<(last-1));
        // long long tmp2 = r&(1LL<<(last-1));
        // long long tmp3 = r&(1LL<<last);
        // // cout << tmp1 << " " << tmp2 << " " << tmp3 << endl;
        // bool dif = true;
        // a+=tmp3;
        // if(tmp2){
        //     b+=tmp3;
        //     a+=tmp2;
        //     c+=tmp2;
        //     last-=2;
        // }
        // else if(!tmp1){
        //     b+=(1LL<<(last-1));
        //     last-=2;
        // }
        // else{
        //     // b+=tmp3;
        //     long long prev = 1LL<<last;
        //     c+=tmp1;
        //     b+=tmp1;
        //     last = last - 2;
        //     // cout << a << " " << b << " " << c << " " << last << endl;
        //     while(last >= 0){
        //         long long bt1 = l&(1LL<<last);
        //         long long bt2 = r&(1LL<<last);
        //         if(bt2 && !bt1){
        //             a += bt2;
        //             b+=bt2;
        //             last--;
        //             break;
        //         }
        //         else if(!bt2 && bt1){
        //             c += bt1;
        //             b+=bt1;
        //             last--;
        //         }
        //         else if(bt2 && bt1){
        //             a += bt2;
        //             c += bt2;
        //             b+=prev;
        //             b-=tmp1;
        //             last--;
        //             break;
        //         }
        //         else{
        //             b += (1LL<<last);
        //             last--;
        //             break;
        //         }
                
        //     }
        // }
        // // a+= (1LL<<last);
        // // b+= (1LL<<last);
        // for(long long i=last; i>=0; i--){
        //     long long bt1 = l&(1LL<<i);
        //     long long bt2 = r&(1LL<<i);
        //     // a+=bt2;
        //     // c+=bt1;
        //     if(bt2 && !bt1){
        //         a += bt2;
        //         // b += bt2;
        //     }
        //     else if(!bt2 && bt1){
        //         c += bt1;
        //     }
        //     else if(bt2 && bt1){
        //         a += bt2;
        //         c += bt2;
        //     }
        //     else{
        //         b += (1LL<<i);
        //     }
        //     // cout << a << " " << b << " " << c << endl;
        // }
        // cout << a << " " << b << " " << c << endl;
    }
}