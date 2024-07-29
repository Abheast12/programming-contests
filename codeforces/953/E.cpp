#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        vector<int> mv1(n);
        vector<int> mv2(n);
        vector<int> psum(n);
        string s1, s2;
        cin >> s1 >> s2;
        for(int i=0; i<n; i++){
            v1[i] = s1[i]-'0';
        }
        for(int i=0; i<n; i++){
            v2[i] = s2[i]-'0';
        }
        for(int i=0; i<n-2; i++){
            if(v1[i]==0 && v1[i+2]==0){
                if(v2[i+1] == 0){
                    mv2[i+1] = 1;
                    v2[i+1] = 1;
                }
            }
        }
        for(int i=0; i<n-2; i++){
            if(v2[i]==1 && v2[i+2] == 1){
                if(v1[i+1] == 0){
                    mv1[i+1] = 1;
                    v1[i+1] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(i==0){
                psum[i] = v1[i];
            }
            else{
                if(v1[i] == 1) psum[i] = psum[i-1]+v1[i];
                else psum[i] = psum[i-1];
            }
        }
        int q;
        cin >> q;
        for(int i=0; i<q; i++){
            int lb, hb;
            cin >> lb >> hb;
            lb--;
            hb--;
            int ans;
            if(lb==0){
                ans = psum[hb];
            }
            else{
                ans = psum[hb]-psum[lb-1];
            }
            set<int>s;
            if(mv1[hb] == 1){
                s.insert(hb);
            }
            if(mv1[lb] == 1){
                s.insert(lb);
            }
            if(lb+1<=hb){
                if(mv1[lb+1] == 1 && mv2[lb] == 1){
                    s.insert(lb+1);
                }
            }
            if(hb-1>=lb){
                if(mv1[hb-1] == 1 && mv2[hb] == 1){
                    s.insert(hb-1);
                }
            }
            cout << ans - s.size() << endl;
            s.clear();
        }
        v1.clear();
        v2.clear();
        mv1.clear();
        mv2.clear();
        psum.clear();



    }
}