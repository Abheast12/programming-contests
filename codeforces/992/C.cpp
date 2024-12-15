#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<algorithm> 
using namespace std;
// returns remainder and number of powers of 2
pair<long long, pair<long long, long long>> gg(long long val, long long p){
    // cout << "here" << endl;
    long long add = pow(2, p);
    long long r = 0;
    long long cnt = 1;
    while(r<val){
        if(r+add>=val){
            break;
        }
        r+=add;
        add/=2;
        cnt++;
        p--;
    }
    return {val%add, {cnt, p-1}};
}
int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        bool t = false;
        if(n-1>=40){
            t=true;
        }
        else if(pow(2, n-1)>=k){
            t=true;
        }
        if(!t){
            cout << -1 << endl;
        }
        else{
            vector<long long>front;
            vector<long long>back;
            for(int i=n-1; i>=1; i--){
                if(i-1>=40){
                    front.push_back(n-i);
                }
                else{
                    if(k<pow(2, i-1)){
                        front.push_back(n-i);
                    }
                    else if(k==pow(2,i-1)){
                        front.push_back(n-i);
                        
                    }
                    else{
                        back.push_back(n-i);
                        k-=pow(2, i-1);
                    }
                }
            }
            reverse(back.begin(), back.end());
            for(int i=0; i<front.size(); i++){
                cout << front[i] << " ";
            }
            cout << n << " ";
            for(int i=0; i<back.size(); i++){
                cout << back[i] << " ";
            }
            cout << endl;
            // vector<long long>res;
            // long long tmpn = n-1;
            // while(pow(2, min(tmpn, 40LL))>k){
            //     res.push_back(1);
            //     tmpn--;
            // }
            // while(true){
            //     cout << k << " " << tmpn << endl;
            //     pair<long long, pair<long long, long>> p = gg(k, tmpn);
            //     cout << p.first << " " << p.second.first << " " << p.second.second << endl;
            //     res.push_back(p.second.first);
            //     k = p.first;
            //     tmpn = p.second.second;
            //     if(k==0 || k==1){
            //         break;
            //     }
            // }
            // vector<long long>ans;
            // long long start = res[0];
            // ans.push_back(start);
            // vector<long long>left;
            // for(int i=1; i<res.size(); i++){
            //     if(res[i]>1){
            //         for(int j=1; j<res[i]; j++){
            //             left.push_back(start+j);
            //         }
            //     }
            //     ans.push_back(start+res[i]);
            //     start+=res[i];
            // }
            // for(int i=left.size()-1; i>=0; i--){
            //     ans.push_back(left[i]);
            // }
            // for(int i=0; i<ans.size(); i++){
            //     cout << ans[i] << " ";
            // }
            // cout << endl;
            

            // long long val = 1<<min(n-1, 40LL);
            // long long consec =0;
            // long long cur = min(n-1, 40LL);
            // long long idx  =0;
            // bool t = false;
            // while(val){
            //     if(cur == n-1){
            //         if(val&k){
            //             t = true;
            //             consec=1;
            //         }
            //     }
            //     else if(t == true){
            //         if(val&k){
            //             consec++;
            //         }
            //         else{
            //             t=false;
            //         }
            //     }
            //     else if(val&k){
            //         idx+=val;
            //     }
            //     val>>=1;
            //     cur--;
            // }
            
            

        }
    }
}