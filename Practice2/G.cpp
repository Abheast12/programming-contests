#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long t, k;
    cin >> t >> k;
    double d = (double) t/(double)k;
    // cout << ceil(d) << endl;
    cout << t + (long long) ceil(d) << endl;
}