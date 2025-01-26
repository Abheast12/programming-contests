#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#include<string>
#include<cmath>
#define int long long
using namespace std;  

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int>v(n+m+2);
        vector<int>v2(n+m+2);
        // int ansnm = 0;
        for(int i=1; i<=n+m+1; i++){
            cin >> v[i];
        }
        for(int i=1; i<=n+m+1; i++){
            cin >> v2[i];
        }
        // vector<bool>forced(n+m+2, false);
        int tot = 0;
        int pct =0;
        int tct =0;
        int forced = -1;
        bool isP = false;
        for(int i=1; i<=n+m; i++){
            if(v[i] > v2[i] && pct < n){
                tot+=v[i];
                pct++;
            }
            else if(v2[i] > v[i] && tct < m){
                tot+=v2[i];
                tct++;
            }
            else if(pct == n){
                if(v[i] > v2[i] && forced == -1){
                    forced = i;
                    isP = true;
                }
                tot+=v2[i];
                tct++;
            }
            else if(tct == m){
                if(v2[i] > v[i] && forced == -1){
                    forced = i;
                }
                tot+=v[i];
            }
            // if(pct == n){
            //     if(v[i] > v2[i]){
            //         // forced[i] = true;
            //         tct++;
            //     }
            //     tot+=v2[i];
            // }
            // else if(tct == m){
            //     if(v2[i] > v[i]){
            //         forced[i] = true;
            //         pct++;
            //     }
            //     tot+=v[i];
            // }
            // else{
            //     if(v[i] > v2[i]){
            //         tot+=v[i];
            //         pct++;
            //     }
            //     else{
            //         tot+=v2[i];
            //         tct++;
            //     }
            // }
        }
        // cout << tot << " " << forced << endl;
        for(int i=1; i<=n+m+1; i++){
            if(i == n+m+1){
                cout << tot << endl;
                break;
            }
            else{
                int tmp = tot;
                if(forced == -1){
                    if(v[i] > v2[i]){
                        tmp-=v[i];
                        tmp+=v[n+m+1];
                    }
                    else{
                        tmp-=v2[i];
                        tmp+=v2[n+m+1];
                    }
                }
                else{
                    if(i < forced){
                        if(isP && v[i] > v2[i]){
                            tmp-=v[i];
                            tmp-=v2[forced];
                            tmp+=v[forced];
                            tmp+=v2[n+m+1];
                        }
                        else if(isP && v[i] < v2[i]){
                            tmp-=v2[i];
                            tmp+=v2[n+m+1];
                        }
                        else if(!isP && v[i] > v2[i]){
                            tmp-=v[i];
                            tmp+=v[n+m+1];
                        }
                        else{
                            tmp-=v2[i];
                            tmp-=v[forced];
                            tmp+=v2[forced];
                            tmp+=v[n+m+1];
                        }
                    }
                    else{
                        if(isP){
                            tmp-=v2[i];
                            tmp+=v2[n+m+1];
                        }
                        else{
                            tmp-=v[i];
                            tmp+=v[n+m+1];
                        }
                    }
                }
                cout << tmp << " ";
            }
        }
        // int pn =-1, pn2 = -1, tn = -1, tn2 = -1;
        // int pnct =0, tnct =0;
        // for(int i=1; i<=n+m; i++){
        //     if(i==1){
        //         if(pnct == n){
        //             pn = i;
        //         }
        //         if(tnct == m){
        //             tn = i;
        //         }
        //     }
        //     if(v[i] > v2[i]){
        //         pnct++;
        //     }
        //     else{
        //         tnct++;
        //     }
        //     if(pnct == n && pn == -1){
        //         pn = i;
        //     }
        //     else if (pnct == n+1 && pn2 == -1){
        //         pn2 = i;
        //     }
        //     if(tnct == m && tn == -1){
        //         tn = i;
        //     }
        //     else if (tnct == m+1 && tn2 == -1){
        //         tn2 = i;
        //     }
        // }
        // // cout << pn << " " << pn2 << " " << tn << " " << tn2 << endl;
        // for(int i=1; i<=n+m+1; i++){
        //     if(i == n+m+1){
        //         cout << tot << endl;
        //         break;
        //     }
        //     int tmp = tot;
        //     if(v[i] > v2[i]){
        //         if(pn == -1){
        //             tmp-=v[i];
        //             tmp+=v[n+m+1];
        //         }
        //         else if(i <= pn){
        //             tmp-=v[i];
        //             if(pn2 != -1){
        //                 tmp+=v[pn2];
        //                 tmp-=v2[pn2];
        //                 tmp+=v2[n+m+1];
        //             }
        //             else{
        //                 tmp+=v[n+m+1];
        //             }
        //         }
        //     }
        //     else{
        //         if(tn == -1){
        //             tmp-=v2[i];
        //             tmp+=v2[n+m+1];
        //         }
        //         else if(i <= tn){
        //             tmp-=v2[i];
        //             if(tn2 != -1){
        //                 tmp+=v2[tn2];
        //                 tmp-=v[tn2];
        //                 tmp+=v[n+m+1];
        //             }
        //             else{
        //                 tmp+=v2[n+m+1];
        //             }
        //         }
        //     }
        //     cout << tmp << " ";
        // }
        // cout << endl;

        // vector<int>p1(n+m+2, 0), p2(n+m+2, 0);
        // vector<int>t1(n+m+2, 0), t2(n+m+2, 0);
        // vector<int>ps, ts;
        // for(int i=1; i<=n+m+1; i++){
        //     p1[i] = p1[i-1] + v[i];
        // }
        // for(int i=1; i<=n+m+1; i++){
        //     if(v[i] > v2[i]){
        //         p2[i] = p2[i-1] + v[i];
        //         ps.push_back(i);
        //     }
        //     else{
        //         p2[i] = p2[i-1];
        //         ts.push_back(i);
        //     }
        // }
        // for(int i=1; i<=n+m+1; i++){
        //     t1[i] = t1[i-1] + v2[i];
        // }
        // for(int i=1; i<=n+m+1; i++){
        //     if(v2[i] > v[i]){
        //         t2[i] = t2[i-1] + v2[i];
        //     }
        //     else{
        //         t2[i] = t2[i-1];
        //     }
        // }
        // for(int i=1; i<=n+m+1; i++){
        //     int ans =0;
        //     if(v[i] > v2[i]){
        //         auto it = lower_bound(ts.begin(), ts.end(), i);
        //         if(*it == i && distance(ts.begin(), it) < n){
        //             ans+=p2[ps[n-1]];
        //             ans-=v[i];
        //         }
        //     }
        // }
    }
}