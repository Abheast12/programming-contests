#include<iostream>
#include<vector>
using namespace std;

ostream& operator<<(ostream& os, const vector<int>& v){
    os << "[";
    for(int i = 0; i < v.size(); i++){
        os << v[i];
        if(i != v.size()-1) os << ", ";
    }
    os << "]";
    return os;
}
int main(){
    vector<int> v = {1,2,3,4,5};
    cout << v << endl;
}