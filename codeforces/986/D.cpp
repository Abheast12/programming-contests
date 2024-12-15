#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> q(n);
        vector<int> k(n);
        vector<int> j(n);
        for(int i=0; i<n; i++){
            cin >> q[i];
        }
        for(int i=0; i<n; i++){
            cin >> k[i];
        }
        for(int i=0; i<n; i++){
            cin >> j[i];
        }
        vector<pair<char, int>>dp(n+1);
        vector<pair<int, char>>troll(3);
        troll[0] = {q[n-1], 'q'};
        troll[1] = {k[n-1], 'k'};
        troll[2] = {j[n-1], 'j'};
        sort(troll.begin(), troll.end());
        dp[n] = {troll[0].second, n};
        int k_min = n-1, j_min = n-1, q_min = n-1;
        dp[1] = {'l', -1};
        for(int i=n-2; i>=0; i--){
            bool works = false;
            if(q[i] > q[q_min]){
                dp[i+1] = {'q', q_min+1};
                works = true;
            }
            else if(k[i] > k[k_min]){
                dp[i+1] = {'k', k_min+1};
                works = true;
            }
            else if(j[i] > j[j_min]){
                dp[i+1] = {'j', j_min+1};
                works = true;
            }
            if(works){
                if(q[q_min] > q[i]){
                    q_min = i;
                }
                if(k[k_min] > k[i]){
                    k_min = i;
                }
                if(j[j_min] > j[i]){
                    j_min = i;
                }
            }
        }
        // cout << "here" << endl;
        vector<pair<char, int>>ans;
        int cur = 1;
        if(dp[cur].first == 'l'){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        while(cur < n){
            ans.push_back(dp[cur]);
            cur = dp[cur].second;
        }
        cout << ans.size() << endl;
        for(auto x:ans){
            cout << x.first << " "  << x.second << endl;
        }
        ans.clear();
    }
}