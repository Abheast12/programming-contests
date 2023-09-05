#include <iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

set<int>s;
set<int>repeat;
vector<int>v;
int t, n, r;
int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> r;
            v.push_back(r);
            if(s.find(r)!=s.end()){
                repeat.insert(r);
            }
            else s.insert(r);

        }
        cout << "Case #" << i+1 << ": ";
        for(int j=0; j<n; j++){
            set<int>::iterator it = s.lower_bound(2*v[j]);
            if(it==s.end()){
                it--;
            }
            if(*it > 2*v[j]){
                it--;
            }
            if(*it == v[j]){
                if(repeat.find(v[j])!=repeat.end()) cout << v[j] << " ";
                else{
                    if(it != s.begin()){
                        it--;
                        cout << *it << " ";
                    }
                    else cout << -1 << " ";
                }
            }
            else cout << *it << " ";
        }
        cout << endl;
        s.clear();
        repeat.clear();
        v.clear();
    }
}