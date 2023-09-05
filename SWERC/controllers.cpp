#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int t, n;
    cin >> t;
    string s;
    cin >> s;
    long long pos = 0;
    long long neg = 0;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '+')pos++;
        else neg++;
    }
    cin >> n;
    long long a, b;
    long long smx = max(pos, neg);
    long long smn = min(pos, neg);
    for(int i=0; i<n; i++){
        cin >> a >> b;
        long long mx = max(a, b);
        long long mn = min(a, b);
        long long pmn = smx*mn;
        long long pmx = smn*mx;
        if(mx == mn && smx == smn) cout << "YES" << endl;
        else if(pmn>pmx) cout << "NO" << endl;
        else if((pmx-pmn)%(mx-mn) == 0){
            if((pmx-pmn)/(mx-mn)<=smx) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }
}