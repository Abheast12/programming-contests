#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
using namespace std;
vector<long long> getFactors(long long num){
    vector<long long>v;
    for(long long i=1; i*i <= num;i++){
        if(num%i == 0){
            if(i == num/i){
                v.push_back(i);
            }
            else{
                v.push_back(i);
                v.push_back(num/i);
            }
        }
    }
    return v;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin >> n;
    int n;
    cin >> n;
    vector<pair<long long, long long>>q;
    for(int i=0; i<n; i++){
        long long a, b;
        cin >>a >> b;
        q.push_back({a, b}); 
    }
    for(int i=0;i<n; i++){
        long long a = q[i].first;
        long long b = q[i].second;
        if(a > b){
            swap(a, b);
        }
        
        set<long long>s;
        if(a%2==0 && b%2==1){
            s.insert(2);
        }
        if(a%2==1 && b%2==0){
            s.insert(2);
        }
        vector<long long>factors = getFactors(a);
        // cout << "hi" << endl;

        for(int i=0; i<factors.size(); i++){
            // cout << factors[i] << " ";
            if((b-2)%factors[i]==0){
                // cout << "here" << endl;
                s.insert(factors[i]);
            }
        }
        // cout << "hi" << endl;
        factors = getFactors(a-1);
        for(int i=0; i<factors.size(); i++){
            // cout << factors[i] << " ";
            if((b-1)%factors[i]==0){
                s.insert(factors[i]);
            }
        }
        // cout << "h1i" << endl;
        factors = getFactors(a-2);
        // cout << "h1i" << endl;
        // cout << factors.size() << endl;
        for(int i=0; i<factors.size(); i++){
            // cout << factors[i] << " ";
            if((b)%factors[i]==0){
                s.insert(factors[i]);
            }
        }
        
        cout << s.size() << " ";
        for(auto it = s.begin(); it!=s.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
        s.clear();
    }
        
}