#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        a[0] = 0;
        vector<char>ans(n, '2');
        bool b = false;
        int last_change = 1;
        for(int i=1; i<n; i++){
            cout << "? 1 " << i+1 << endl;
            cout.flush();
            cin >> a[i];
            if(a[i] > a[i-1]){
                int dif = a[i] - a[i-1];
                ans[i] = '1';
                int cur = i-1;
                while(dif > 0 && ans[cur] == '2'){
                    ans[cur] = '0';
                    dif--;
                    cur--;
                }
                while(ans[cur] == '2'){
                    ans[cur] = '1';
                    cur--;
                }
            }
            else if(i == n-1){
                if(a[i] == 0){
                    b=true;
                    cout << "! IMPOSSIBLE" << endl;
                    cout.flush();
                }
                else{
                    int cur = i;
                    while(ans[cur] == '2'){
                        ans[cur] = '0';
                        cur--;
                    }
                    // ans[i] = '0';
                }  
            }
        }
        if(!b){
            string s_ans = "";
            for(char c : ans){
                s_ans += c;
            }
            cout << "! " << s_ans << endl;
            cout.flush();
        }
    }
}