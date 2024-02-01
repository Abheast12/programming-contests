#include<iostream>

using namespace std;
pair<int, int> fill(int a, int b, int bi, int bj, int n){
    
    if(abs(a - bi) > abs(b-bj)){
        while(b!=bj){
            cout << a << " " << b << " ";
            if(a > bi){
                cout << -1*n << " ";
                a--;
            }
            else {
                cout << n << " "; 
                a++;
            }
            if(b > bj){
                b--;
                cout << -1*n << endl;
            }
            else {
                cout << n << endl;
                b++;
            }
            n--;
            
        }
    }
    else{
        while(a!=bi){
            cout << a << " " << b << " ";
            if(a > bi){
                cout << -1*n << " ";
                a--;
            }
            else {
                cout << n << " "; 
                a++;
            }
            if(b > bj){
                b--;
                cout << -1*n << endl;
            }
            else {
                cout << n << endl;
                b++;
            }
            n--;
            
        }
    }
    return {a, b};
}
int main(){
    int n, bi, bj;
    cin >> n >> bi >> bj;
    cout << "Yes" << endl;
    pair<int, int>tl, br;
    // int tl =1, br = n;
    tl = {1,1}; br = {n, n};
    cout << n-1 << endl;
    while(true){
        if(br.first-tl.first==0) break;
        if(bi-tl.first > br.first-bi){
            if(bj-tl.second > br.second-bj){
                pair<int, int>p = fill(tl.first, tl.second, bi, bj, br.first-tl.first);
                tl = {p.first, p.second};
            }
            else{
                pair<int, int>p =fill(tl.first, br.second, bi, bj, br.first-tl.first);
                tl.first = p.first;
                br.second = p.second;
            }
        }
        else{
            if(bj-tl.second > br.second-bj){
                pair<int, int>p =fill(br.first, tl.second, bi, bj, br.first-tl.first);
                tl.second = p.second;
                br.first = p.first;
            }
            else{
                pair<int, int>p =fill(br.first,br.second, bi, bj, br.first-tl.first);
                br = {p.first, p.second};
            }
        }
    }
}