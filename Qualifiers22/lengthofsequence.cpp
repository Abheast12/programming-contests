#include<iostream>
#include<vector>
#include<stdio.h>
#include<math.h>
using namespace std;
vector<long long>v;
int main(){
    long long n;
    cin >> n;
    // if(n==100000000000000000) while(true);
    long long a=0;
    long long b=0;
    v.push_back(10);
    for(int i=1; i<=18; i++){
        if(i==17 || i==18){
            v.push_back(LLONG_MAX);
        }
        else v.push_back(((long long)i+1)*(pow(10, i+1) - pow(10, i)));
    }
    // cout << v[17] << endl;
    long long tot = 0;
    long long idx = 0;
    while(tot<n){
        
        if(idx>=17 || tot+v[idx]>=n){
            if(idx!=0){
                b = (n-tot)/(idx+1) + (long long)pow(10, idx) - (long long)1;
                tot+= ((b-(long long)pow(10, idx)+(long long)1)*((long long)idx+1));
                // cout << b << " " << tot << endl;
            } else{
                b = (n-tot)/((long long)idx+1) - (long long)1;
                tot+= (b+(long long)1);
            }
            break;
        } else{
            tot+=v[idx];
            idx++;
        }
    }
    // if(abs(tot-n)<18 && n>10000) while(true);
    while(true){
        // cout << tot << endl;
        if(tot == n){
            cout << (long long)(b-a+1) << endl;
            cout << a << " " << b << endl;
            return 0;
        }
        else if(tot < n){
            b++;
            tot+=((long long)log10(b)+(long long)1);
        }
        else if(tot > n){
            if(a!=0) tot-=((long long)log10(a)+(long long)1);
            else tot--;
            a++;
        }
    }
    // cout << -1 << endl;
    // return 0;
}
/*
from typing import List

v = []
n = int(input())
a = 0
b = 0
v.append(10)
for i in range(1, 19):
    if i == 17 or i == 18:
        v.append(float('inf'))
    else:
        v.append((i+1)*(10**(i+1) - 10**i))
tot = 0
idx = 0
while tot < n:
    if idx >= 17 or tot + v[idx] >= n:
        if idx != 0:
            b = (n - tot) // (idx + 1) + 10**idx - 1
            tot += ((b - 10**idx + 1) * (idx + 1))
        else:
            b = (n - tot) // (idx + 1) - 1
            tot += (b + 1)
        break
    else:
        tot += v[idx]
        idx += 1
while True:
    if tot == n:
        print(b - a + 1)
        print(a, b)
        break
    elif tot < n:
        b += 1
        tot += int(len(str(b)))
    elif tot > n:
        if a != 0:
            tot -= int(len(str(a)))
        else:
            tot -= 1
        a += 1

*/