#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a, b, n, m;
        cin >> a >> b >> n >> m;
        set<pair<int, int>>sx;
        set<pair<int, int>>sy;
        for(int i=0; i<n; i++){
            int x, y;
            cin >> x >> y;
            sx.insert({x, y});
            sy.insert({y, x});
        }
        long long al = 0;
        long long bl = 0;
        long long maxa = a;
        long long maxb = b;
        long long mina = 1;
        long long minb = 1;
        // cout << m << endl;
        for(int i=0; i<m; i++){
            char c;
            long long k;
            cin >> c >> k;
            // cout << c << k << endl;
            long long dif = 0;
            if(c=='U'){
                long long bd = mina + k;
                auto it = sx.lower_bound({bd, 0});
                while(it!=sx.begin()){
                    it--;
                    auto temp = it;
                    sy.erase({temp->second, temp->first});
                    it = sx.erase(temp);
                    dif++;
                }
                mina = bd;
            }
            else if(c=='D'){
                long long bd = maxa - k;
                auto it = sx.upper_bound({bd, b+1});
                while(it!=sx.end()){
                    auto temp = it;
                    sy.erase({temp->second, temp->first});
                    it = sx.erase(temp);
                    dif++;
                }
                maxa = bd;

            }
            else if(c=='L'){
                long long bd = minb + k;
                auto it = sy.lower_bound({bd, 0});
                while(it!=sy.begin()){
                    it--;
                    auto temp = it;
                    sx.erase({temp->second, temp->first});
                    it = sy.erase(temp);
                    dif++;
                }
                minb = bd;
            }
            else if(c=='R'){
                long long bd = maxb - k;
                auto it = sy.upper_bound({bd, a+1});
                while(it!=sy.end()){
                    auto temp = it;
                    sx.erase({temp->second, temp->first});
                    it = sy.erase(temp);
                    // it++;
                    dif++;
                }
                maxb = bd;
            }
            if(i%2==0){
                al += dif;
            }
            else{
                bl += dif;
            }
        }
        cout << al << " " << bl << endl;
        sx.clear();
        sy.clear();
    }

}