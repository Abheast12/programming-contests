#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<5000; i++){
        if(i==1){
            v.push_back(0);
        }
        else if(i==2) {
            v.push_back(1);
        }
        else{
            v.push_back(i*(i-1)/2);
        }
    }
    int total = 0;
    int left = n;
    
    while(left>0){
        auto it = lower_bound(v.begin(), v.end(), left);
        int idx = it-v.begin();
        idx--;
        total+=v[idx];
        left-=(idx+1);
    }
    cout << total << endl;
    // for(int i=0; i<=n; i++){
    //     cout << "here" << endl;
    //     if(left == 0){
    //         cout << total << endl;
    //         break;
    //     }
    //     if(left - v[i].first > v[i].first){
    //         cout << v[i].first << " " << v[i].second << endl;
    //         total+=v[i].second;
    //         left-=v[i].first;
    //     }
    // }
}
