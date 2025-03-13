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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<pair<char, int>>>v(n, vector<pair<char, int>>(2));
        for(int i=0; i<n; i++){
            int x, y;
            char c,d;
            cin >> c >> x >> d >> y;
            v[i][0] = {c, x};
            v[i][1] = {d, y};
        }
        int l = 1, r = 1;
        vector<int>best(n);
        for(int i=n-1; i>=1; i--){
            if(v[i][0].first == 'x' && v[i][1].first == 'x'){
                if(v[i][0].second < v[i][1].second){
                    best[i] = 1;
                }
                else if(v[i][0].second > v[i][1].second){
                    best[i] = 0;
                }
                else{
                    if(i!=n-1){
                        best[i] = best[i+1];
                    }
                    else{
                        best[i] = 1;
                    }
                }
            }
            else if(v[i][0].first == 'x'){
                best[i] = 0;
            }
            else if(v[i][1].first == 'x'){
                best[i] = 1;
            }
            else{
                if(i!=n-1){
                    best[i] = best[i+1];
                }
                else{
                    best[i] = 1;
                }
            }
            // if(v[i][0].first == 'x'){
            //     l*=v[i][0].second;
            // }
            // if(v[i][1].first == 'x'){
            //     r*=v[i][1].second;
            // }
            // if(l < r){
            //     best[i] = 1;
            // }
            // else{
            //     best[i] = 0;
            // }
        }
        int curl = 1, curr = 1;
        for(int i=0; i<n; i++){
            int bonusl = 0, bonusr = 0;
            // if(v[i][0].first == '+'){
                
            // }
            if(v[i][0].first == 'x'){
                bonusl+=(v[i][0].second-1)*curl;
            }
            else{
                bonusl=v[i][0].second;
            }
            if(v[i][1].first == 'x'){
                bonusr+=(v[i][1].second-1)*curr;
            }
            else{
                bonusr=v[i][1].second;
            }
            if(i != n-1){
                if(best[i+1] == 1){
                    curr+=(bonusr+bonusl);
                }
                else{
                    curl+=(bonusr+bonusl);
                }
            }
            else{
                curl+=bonusl;
                curr+=bonusr;
            }
        }
        cout << curl+curr << endl;
    }
}