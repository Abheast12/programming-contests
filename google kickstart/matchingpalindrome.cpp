#include<string>
#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;
int t, p, n;
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        string s;
        cin >> s;
        bool t = false;
        cout << "Case #" << i+1 << ": ";
        if(n%2==0){
            string sub = s.substr(1, n/2-1);
            reverse(sub.begin(), sub.end());
            if(s.substr(n/2+1, n/2-1)==sub){
                cout << s[0] << endl;
                t = true;
            }
        }
        if(!t){
            for(int j=n/2+1; j<n; j++){
                string sub = s.substr(j, n-j);
                string sub2 = s.substr(2*j-n, n-j);
                
                reverse(sub2.begin(), sub2.end());
                
                string palin = s.substr(0, 2*j-n);
                string pl = palin;
                reverse(palin.begin(), palin.end());
                if(sub == sub2 && pl == palin){
                    cout << pl << endl;
                    t=true;
                    break;
                }
                string sub3 = s.substr(j+1, n-j-1);
                string sub4 = s.substr(2*j-n+1, n-j-1);
                reverse(sub4.begin(), sub4.end());
                string palin2 = s.substr(0, 2*j-n+1);
                string pl2 = palin2;
                reverse(palin2.begin(), palin2.end());
                if(sub3 == sub4 && pl2 == palin2){
                    cout << pl2 << endl;
                    t=true;
                    break;
                }
            }
            if(!t){
                cout << s << endl;
            }
        }
        
    }
}