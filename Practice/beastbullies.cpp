#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    long long sum = 0;
    bool b = false;
    int ans = n;
    long long beat = v[n-1];
    long long tempsum = 0;
    int surv = 1;
    int last = n-2;
    for(int i=n-2; i>=0; i--){
        tempsum += v[i];
        // cout << tempsum << " " << beat << endl;
        if(tempsum>=beat){
            b = true;
            beat +=tempsum;
            tempsum = 0;
            surv+=(last-i+1);
            last = i-1;
        }
    }
    cout << surv << endl;
}