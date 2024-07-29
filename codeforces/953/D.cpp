#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n,c;
        cin >> n >> c;
        vector<long long>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        // long long maxl[200100];
        // long long maxr[200100];
        // long long psum[200100];
        vector<long long>maxl(n+1);
        vector<long long>maxr(n+1);
        vector<long long>psum(n+1);

        // memset(maxl, 0, sizeof(maxl));
        // memset(maxr, 0, sizeof(maxr));
        // memset(psum, 0, sizeof(psum));
        for(int i=n-2; i>=0; i--){
            maxr[i] = max(maxr[i+1], v[i+1]);
        }
        for(int i=1; i<n; i++){
            maxl[i] = max(maxl[i-1], v[i-1]);
        }
        for(int i=0; i<n; i++){
            if(i==0){
                psum[i] = v[i];
            }
            else{
                psum[i] = psum[i-1]+v[i];
            }
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++){
            
            if(i==0){
                if(v[i]+c >= maxr[i]){
                    ans[i] = 0;
                }
                else{
                    ans[i] = 1;
                }
            }
            else{
                long long temp = v[i];
                int tans =0;
                if(maxl[i] >= temp || v[0]+c >=temp){
                    temp+=psum[i-1];
                    tans+=i;
                    if(temp+c >= maxr[i]){
                        ans[i] = tans;
                    }
                    else{
                        ans[i] = tans+1;
                    }
                }
                else{
                    if(maxr[i] > temp){
                        temp+=psum[i-1];
                        tans+=i;
                        if(temp+c >= maxr[i]){
                            ans[i] = tans;
                        }
                        else{
                            ans[i] = tans+1;
                        }
                    }
                    else{
                        ans[i] = 0;
                    }
                }

            }
        }

        for(int i=0; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        ans.clear();
        v.clear();
        maxl.clear();
        maxr.clear();
        psum.clear();
    }
}