#include<iostream>
// #include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    for(int i=0; i<t; i++){
        long long n, k, m, a, b;
        cin >> n >> k >> m >> a >> b;
        if(k==1 && n%m!=0){
            cout << -1 << endl;
        } else if (k==1) {
            cout << 0 << endl;
        }
        else {
            vector<long long>v;
            // vector<long long>v2;
            long long nn = n;
            while(nn!=0){
                v.push_back(nn);
                nn /= k;
            }
            v.push_back(0);
            sort(v.begin(), v.end());

            long long ans = ((long long)v.size()-(long long)1)*b;
            for(int j=1; j<(int)v.size(); j++){
                if(v[j]%m==0){
                    ans = min(ans, (long long)(v.size()-j-1)*b);
                }
                else{
                    long long x = v[j];
                    long long y = v[j];
                    long long ct = 0;
                    while(true){
                        if(y%m - x%m != y - x || x%m==0 || y%m==0){
                            ans = min(ans, (long long)(v.size()-j-1)*b + (long long)ct*a);
                            break;
                        }
                        y%=m; x%=m;
                        y*=k; x*=k;
                        
                        y+=k-1;
                        if(x<0 || y < 0) while(true);
                        // if(LLONG_MAX/y < k){
                        //     y%=m; x%=m;
                        //     y*=k; x*=k;
                        //     y+=k-1;
                        //     // break;
                        // }
                        // else{
                        //     y *= k;
                        //     if(LLONG_MAX - y > k-1){
                        //         y+=k-1;
                        //     }
                        //     else y = LLONG_MAX;
                        //     x *= k;
                        //     // if(LLONG_MAX/y < k){
                        //     //     y = LLONG_MAX;
                        //     //     x *=k;
                        //     // }
                        //     // else{
                        //     //     y *= k;
                        //     //     if(LLONG_MAX - y > k-1) y+=k-1;
                        //     //     else y = LLONG_MAX;
                        //     //     x *= k;
                        //     // }
                        // }
                        ct++;
                    }
                }
            }
            // priority_queue<pair<long long, long long>>pq;
            // pq.push({0, n});
            // while(!pq.empty()){
            //     long long x = pq.top().first;
            //     long long y = pq.top().second;
            //     if(y%m==0){
            //         cout << x << endl;
            //         break;
            //     }
            //     pq.pop();
            //     long long xx = y/k;
            //     pq.push({x+b, xx});
            //     if(k <= LLONG_MAX/y){
            //         long long yy = y*k;
            //         if(m - yy%m < k){
            //             pq.push({x+a, m});
            //         }
            //     }
                

            // }
            cout << ans << endl;
        }
    }
}