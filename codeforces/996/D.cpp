#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    int ct =0;
    while(t--){
        ct++;
        double n, k, l;
        cin >> n >> k >> l;
        // vector<double>v(n);
        multiset<double>v;
        for(int i=0; i<n; i++){
            double x;
            cin >> x;
            v.insert(x);
        }
        double time = 0;
        double pos =0;
        map<int, int>used;
        multiset<double>::iterator it;
        // if(ct == 202){
        //     cout << n << "," << k << "," << l << ",";
        //     for(auto x : v){
        //         cout << x << ",";
        //     }
        // }
        while(pos < l){
            // cout << pos << " " << time << endl;
            if(pos == 0){
                time+=*v.begin();
                pos+=k;
                v.erase(v.begin());
                it = v.lower_bound(pos-time-k);

            }
            else{
                if(it == v.end()){
                    time+=(l-pos);
                    pos = l;
                    break;
                }
                else{
                    if(*it <= pos){
                        if(*it+time>=pos){
                            pos+=k;
                            v.erase(it);
                        }
                        else{
                            pos = *it+time+k;
                            v.erase(it);
                        }
                       
                    }
                    else{
                        // cout << *it << " " << pos << " " << time << endl;
                        if(*it-time<=pos){
                            pos+=k;
                            v.erase(it);
                        }
                        else{
                            double dist = *it-pos-time;
                            double tmp = dist/(double)2;
                            pos = *it-time- tmp+k;
                            time+=tmp;
                            v.erase(it);
                        }
                        // cout << *it << " " << pos << " " << time << endl;
                    }
                   
                    // if(dist<=0) tmp = 0;
                    // else if(it != v.begin()){
                    //     auto it2 = it;
                    //     it2--;
                    //     if(*it2 + time + k > pos ){
                    //         pos = *it2 + time + k;
                    //     }
                    //         dist = *it-pos-time;
                    //         tmp = dist/(double)2;
                    // }
                    // time+=tmp;
                    // pos+=tmp;
                    // pos+=k;
                    // v.erase(it);
                    // cur = lower_bound(v.begin(), v.end(), pos)-v.begin();
                }
                
                it = v.lower_bound(pos-time-k);
            }
        }
        // for(int i=0; i<n; i++){
        //     if(pos >= l){
        //         break;
        //     }
        //     if(i==0){
                
        //     }
        //     else{
        //         if(abs(v[i]-pos) )
        //     }
        // }
        
        cout << (int)(2.0*time) << endl;
    }
}