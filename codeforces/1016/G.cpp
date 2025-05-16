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

struct node{
    int children[2] = {-1, -1};
    int last = -1;
};

int find(vector<node>&trie, int x, int  k){
    int ans = -1;
    int curr =0;
    for(int i=29; i>=0; i--){
        int xi = (x>>i)&1;
        int ki = (k>>i)&1;
        // int val = (xi^ki);
        if(ki == 1){
            if(trie[curr].children[xi^1] != -1){
                
                curr = trie[curr].children[xi^1];

            }
            else{
                return ans;
            }
        }
        else{
            int opp = xi^1;
            if(trie[curr].children[opp] != -1){
                ans  = max(ans, trie[trie[curr].children[opp]].last);
                // curr = trie[curr].children[0];
            }
            if(trie[curr].children[xi] != -1){
                curr = trie[curr].children[xi];
            }
            else return ans;
        }
    }
    return max(ans, trie[curr].last);
}

void add(vector<node>&trie, int x, int idx){
    int curr = 0;
    trie[curr].last = idx;
    for(int i=29; i>=0; i--){
        int xi = (x>>i)&1;
        if(trie[curr].children[xi] == -1){
            trie[curr].children[xi] = trie.size();
            trie.push_back(node());
        }
        curr = trie[curr].children[xi];
        trie[curr].last = idx;
    }
    
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        if(k==0){
            cout << 1 << endl;
            continue;
        }
        vector<node>trie(1);
        int ans = 1e9;
        for(int i=0; i<n; i++){
            add(trie, v[i], i);
            int val = find(trie, v[i], k);
            if(val != -1){
                ans = min(ans, i-val+1);
            }
        }  
        if(ans == 1e9){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        } 
    }
}