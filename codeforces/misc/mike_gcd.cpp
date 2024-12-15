#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n);
    set<long long>factors;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        set<long long>factors2;
        // cout << "here" << endl;
        if(i==0){
            for(long long j=1; j*j<=v[i]; j++){
                if(v[i]%j==0){
                    factors.insert(j);
                    factors.insert(v[i]/j);
                }
            }
        }
        else{
            for(int j=1; j*j<=v[i]; j++){
                if(v[i]%j==0){
                    if(factors.find(j)!=factors.end()) factors2.insert(j);
                    if(factors.find(v[i]/j)!=factors.end()) factors2.insert(v[i]/j);
                }
            }
            factors = factors2;
        }
        factors2.clear();
    }
    if(factors.size()>1){
        cout << "YES" << endl;
        cout << 0 << endl;
    }
    else{
        int streak = 0;
        int mods = 0;
        for(int i=0; i<n; i++){
            // cout << streak << " " << i << endl;
            if(v[i]%2LL==1LL){
                streak++;
            }
            else if(streak!=0){
                // cout << mods << endl;
                // mods+= streak%2==0 ? streak/2 : streak/2+1;
                // cout << mods << endl;
                mods += streak/2;
                if(streak%2==1){
                    mods+=2;
                }
                streak=0;
            }
        }
        if(streak!=0){
            mods += streak/2;
            if(streak%2==1){
                mods+=2;
            }
            // mods+= streak%2==0 ? streak/2 : streak/2+1;
        }
        cout << "YES" << endl;
        cout << mods << endl;
    }

}