#include<numeric>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int w, h, n;
    cin >> w >> h >> n;
    int area = w*h;
    char c;
    int w1=0, w2=w, h1=0, h2=h;
    set<int>widths;
    set<int>heights;
    multiset<int>diffh;
    multiset<int>diffw;
    widths.insert(w1);
    widths.insert(w2);
    heights.insert(h1);
    heights.insert(h2);
    diffw.insert(w);
    diffh.insert(h);
    for(int i=0; i<n; i++){
        int a;
        cin >> c >> a;
        if(c=='H'){
            auto it = lower_bound(heights.begin(), heights.end(), a);
            int mx = *it;
            it--;
            int mn = *it;
            diffh.erase(lower_bound(diffh.begin(), diffh.end(), mx-mn));
            diffh.insert(mx-a);
            diffh.insert(a-mn);
            heights.insert(a);
        }
        else if(c=='V'){
            auto it = lower_bound(widths.begin(), widths.end(), a);
            int mx = *it;
            it--;
            int mn = *it;
            diffw.erase(lower_bound(diffw.begin(), diffw.end(), mx-mn));
            diffw.insert(mx-a);
            diffw.insert(a-mn);
            widths.insert(a);
        }
        auto it = diffh.end();
        auto it2 = diffw.end();
        it--;
        it2--;
        cout << *it**it2 << endl;
        // cout << w1 << " " << w2 << " " << h1 << " " << h2 << endl;
    }
}