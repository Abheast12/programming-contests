#include<iostream>
#include<vector>
using namespace std;
vector<int>v;
int main(){
    int n;
    cin >> n;
    int a, b;
    int start = -1, end = n;
    bool b2 = true;
    for(int i=0; i<n; i++){
        
        cin >> a;
        v.push_back(a);
        
    }
    bool inInterval = false;
    bool hadInterval = false;
    for(int i=0; i<n-1; i++){
        if(v[i]>v[i+1]){
            if(!inInterval){
                inInterval = true;
                start = i;
            }
            else if(hadInterval){
                b2 = false;
                break;
            }
        }
        else{
            if(inInterval){
                end = i;
                hadInterval = true;
            }
        }
    }

    // if(i!=0){
    //         b = v[i-1];
    //         if(b<a){
    //             if(start!=-1){
    //                 b2 = false;
    //                 break;
    //             }
    //             start = i+1;
    //         }
    //         else if(b>a){
    //             if(start!=-1){
    //                 end = i+1;
    //                 break;
    //             }
    //         }
    //     }
    if(!b2){
        cout << "no" << endl;
    }
    else{
        
        cout << "yes" << endl;
        cout << start+1 << " " << end << endl;
    }
}