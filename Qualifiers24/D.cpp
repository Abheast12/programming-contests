#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<string>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin >> a >> b;
        string newa = "";
        string newb = "";
        int ba = 0;
        int bb = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] == 'B'){
                ba++;
            }
            else{
                newa += a[i];
            }
        }
        for(int i=0; i<b.size(); i++){
            if(b[i] == 'B'){
                bb++;
            }
            else{
                newb += b[i];
            }
        }
        ba%=2;
        bb%=2;
        // int temp = 3;
        // temp%=2;
        // cout << temp<< endl;
        int pos = 0;
        // string newesta = "";
        // string newestb = "";
        // char cur;
        // int streak = 0;
        // for(int i=0; i<newa.size(); i++){
        //     if(i == 0){
        //         cur = newa[i];
        //         streak = 1;
        //     }
        //     else{
        //         if(newa[i] == cur){
        //             streak++;
        //         }
        //         else{
        //             if(streak%2 == 1){
        //                 newesta += cur;
        //             }
        //             cur = newa[i];
        //             streak = 1;
        //         }
        //     }
        // }
        // if(streak%2 == 1){
        //     newesta += cur;
        // }
        // for(int i=0; i<newb.size(); i++){
        //     if(i == 0){
        //         cur = newb[i];
        //         streak = 1;
        //     }
        //     else{
        //         if(newb[i] == cur){
        //             streak++;
        //         }
        //         else{
        //             if(streak%2 == 1){
        //                 newestb += cur;
        //             }
        //             cur = newb[i];
        //             streak = 1;
        //         }
        //     }
        // }
        // if(streak%2 == 1){
        //     newestb += cur;
        // }
        
        // while(pos < newa.size()){
        //     if(pos < newa.size()-1 && newa[pos] == newa[pos+1]){
        //         newa.erase(pos, 2);
        //     }
        //     else pos++;
        // }
        // pos = 0;
        // while(pos < newb.size()){
        //     if(pos < newb.size()-1 && newb[pos] == newb[pos+1]){
        //         newb.erase(pos, 2);
        //     }
        //     else pos++;
        // }
        stack<char>sa;
        stack<char>sb;
        for(int i=0; i<newa.size(); i++){
            if(sa.empty()){
                sa.push(newa[i]);
            }
            else{
                if(sa.top() == newa[i]){
                    sa.pop();
                }
                else{
                    sa.push(newa[i]);
                }
            }
        }
        string newesta = "";
        while(!sa.empty()){
            newesta += sa.top();
            sa.pop();
        }
        reverse(newesta.begin(), newesta.end());
        for(int i=0; i<newb.size(); i++){
            if(sb.empty()){
                sb.push(newb[i]);
            }
            else{
                if(sb.top() == newb[i]){
                    sb.pop();
                }
                else{
                    sb.push(newb[i]);
                }
            }
        }
        string newestb = "";
        while(!sb.empty()){
            newestb += sb.top();
            sb.pop();
        }
        reverse(newestb.begin(), newestb.end());
        if(ba == bb && newesta == newestb){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}