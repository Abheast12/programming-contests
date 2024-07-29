#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>a1(n);
        vector<int>b1(n);
        
        for(int i=0; i<n; i++){
            cin >> a1[i];
        }
        for(int i=0; i<n; i++){
            cin >> b1[i];
        }
        vector<int>a2 = a1;
        vector<int>b2 = b1;
        sort(a1.begin(), a1.end());
        sort(b1.begin(), b1.end());
        bool t = false;
        for(int i=0; i<n; i++){
            if(a1[i] != b1[i]){
                cout << "NO" << endl;
                t=true;
                break;
            }
        }
        if(!t){

            long long o_s1waps = 0;
            long long o_s2waps = 0;
            long long inv_a = 0;
            long long inv_b = 0;
            map<int, int>mp1;
            map<int, int>mp2;
            for(int i=0; i<n; i++){
                mp1[a2[i]] = i;
                mp2[b2[i]] = i;
            }
            ordered_set o_s1;
            ordered_set o_s2;

            for(int i=0; i<n; i++){
                if(i!=0){
                    
                    // auto it1 = lower_bound(o_s1.begin(), o_s1.end(), mp1[a1[i]]);
                    // auto it2 = lower_bound(o_s2.begin(), o_s2.end(), mp2[b1[i]]);
                    inv_a+=mp1[a1[i]];
                    inv_b+=mp1[b1[i]];
                    inv_a -= o_s1.order_of_key(mp1[a1[i]]);
                    inv_b-= o_s2.order_of_key(mp2[b1[i]]);
                    o_s1.insert(mp1[a1[i]]);
                    o_s2.insert(mp2[b1[i]]);
                }
                else{
                    inv_a+=mp1[a1[i]];
                    inv_b+=mp1[b1[i]];
                    o_s1.insert(mp1[a1[i]]);
                    o_s2.insert(mp2[b1[i]]);
                }
            }
            // for(int i=0; i<n; i++){
            //     if(mp1[a1[i]]+a1[i]-1 > i){
            //         o_s1waps += mp1[a1[i]]+a1[i]-1 - i;
            //     }
            //     if(mp2[b1[i]]+b1[i]-1 > i){
            //         o_s2waps += mp2[b1[i]]+b1[i]-1 - i;
            //     }
            // }
            o_s1waps = inv_a;
            o_s2waps = inv_b;
            // cout << o_s1waps << " " << o_s2waps << endl;
            if(o_s1waps%2 == o_s2waps%2){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
            mp1.clear();
            mp2.clear();
        }
        // a1.clear();
        // b1.clear();
        // a2.clear();
        // b2.clear();


    }
}