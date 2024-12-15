#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
#include<string>
using namespace std;




bool isValid(string s){
    if(s.length()==0) return false;
    if(s[s.length()-1] != 'O'){
        return false;
    }
    for(int i=0; i<s.length(); i++){
        if(s[i]=='O'){
            if(i>0 && s[i-1]=='O'){
                return false;
            }
        }
        if(!(s[i]=='E' || s[i]=='O')){
            return false;
        }
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    long long start = 16;
    if(!isValid(s)){
        cout << "INVALID" << endl;
        return 0;
    }

    while(true){
        long long cur = start;
        cur = (start-1)/3;
        if((cur & (cur-1LL)) == 0LL){
            start*=4LL;
            continue;
        }
        bool t = true;
        for(int i=s.length()-2; i>=0; i--){
            if(s[i] == 'O'){
                if(cur%(3LL)==1LL){
                    cur = (cur-1LL)/3LL;
                    if((cur & (cur-1LL)) == 0LL){
                        t=false;
                        break;
                    }
                }
                else{
                    t = false;
                    break;
                }
            }
            else{
                cur*=(2LL);
            }
        }
        if(t){
            cout << cur << endl;
            break;
        }
        start*=4LL;
    }
    

}

