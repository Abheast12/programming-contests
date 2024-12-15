#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

int main(){
    long long t, n;
    cin >> t;
    map<long long, vector<long long>>m;
    for(int i=0; i<t; i++){
        cin >> n;
        vector<long long>v(n);
        set<long long>s;
        for(int j=0; j<n; j++){
            long long a;
            cin >> a;
            s.insert(j-a);
            m[j-a].push_back(a);
        }
        long long ans = 0;
        for(auto it : s){
            vector<long long>temp = m[it];
            for(int k=(int)temp.size()-1; k>=0; k-=2){
                if(k-1>=0){
                    if(temp[k]+temp[k-1]>0) ans+=temp[k]+temp[k-1];
                }
                // if(k>=(int)temp.size()-k-1){
                //     break;
                // }
                // else{
                //     if(temp[k]+temp[(int)temp.size()-k-1]>0){
                //         ans+=(temp[k]+temp[(int)temp.size()-k-1]);
                //     }
                // }
            }
        }
        cout << ans << endl;
        v.clear();
        s.clear();
        m.clear();
    }
    
}