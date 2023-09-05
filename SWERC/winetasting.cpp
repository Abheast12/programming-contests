#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = -1;
    int tot = 0;
    for(int i=0; i<2*n-1; i++){
        if(s[i]=='W') tot++;
        if(i>=n-1){
            if(i==n-1){
                ans = max(ans, tot);
            }
            else{
                if(s[i-n]=='W') tot--;
                ans = max(ans, tot);
            }
        }
    }
    cout << ans;
}