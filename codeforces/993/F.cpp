#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
bool solve(long long a, set<long long>&st, set<long long>&st2, long long s1, long long s2){
    long long a1 = abs(a);
    for(int i=1; i*i<=a1; i++){
        if(a1%i ==0){
            if(a>=0){
                if(st.find(s1-i)!=st.end() && st2.find(s2-a1/i)!=st2.end()){
                    return true;
                }
                if(st.find(s1-a1/i)!=st.end() && st2.find(s2-i)!=st2.end()){
                    return true;
                }
                if(st.find(s1+i)!=st.end() && st2.find(s2+a1/i)!=st2.end()){
                    return true;
                }
                if(st.find(s1+a1/i)!=st.end() && st2.find(s2+i)!=st2.end()){
                    return true;
                }
            }
            else{
                if(st.find(s1-i)!=st.end() && st2.find(s2+a1/i)!=st2.end()){
                    return true;
                }
                if(st.find(s1+a1/i)!=st.end() && st2.find(s2-i)!=st2.end()){
                    return true;
                }
                if(st.find(s1+i)!=st.end() && st2.find(s2-a1/i)!=st2.end()){
                    return true;
                }
                if(st.find(s1-a1/i)!=st.end() && st2.find(s2+i)!=st2.end()){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, q;
    cin >> n >> m >> q;
    long long s1 = 0;
    long long s2 = 0;
    set<long long>st;
    set<long long>st2;
    for(int i=0; i<n; i++){
        long long a;
        cin >> a;
        st.insert(a);
        s1 += a;
    }
    for(int i=0; i<m; i++){
        long long a;
        cin >> a;
        st2.insert(a);
        s2 += a;
    }
    for(int i=0; i<q; i++){
        long long a;
        cin >> a;
        if(solve(a, st, st2, s1, s2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}