#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;
#define all(x) begin(x), end(x)

template <class T> int sgn(T x) { return (x>0) - (x<0);}
template <class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const{return tie(x, y)<tie(p.x, p.y);}
    bool operator==(P p)const{return tie(x,y)==tie(p.x,p.y);}
    P operator+ (P p) const { return P(x+p.x, y+p.y);}
    P operator-(P p) const{return P(x-p.x, y-p.y);}
    P operator*(T d) const {return P(x*d, y*d);}
    T dot(P p) const {return x*p.x + y*p.y;}
    T cross(P p) const {return x*p.y-y*p.x;}
    T cross(P a, P b) const {return (a-*this).cross(b-*this);}
};
typedef Point<long long> P;
vector<P> convexHull(vector<P> pts) {
    if(size(pts) <=1)return pts;
    sort(all(pts));
    vector<P> h(size(pts)+1);
    int s =0, t=0;
    for(int it = 2; it--; s=--t, reverse(all(pts)))
        for(P p:pts){
            while(t>=s + 2 && h[t-2].cross(h[t-1], p) <= 0)t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin()+t -(t==2 && h[0]==h[1])};
}
int main(){
    int n;
    cin >> n;
    vector<Point<long long>>v;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        Point <long long> p;
        p.x = x;
        p.y = y;
        v.push_back(p);
    }
    vector<Point<long long>>hull = convexHull(v);
    // cout << hull.size() << endl;
    // for(int i=0; i<hull.size(); i++){
    //     cout << hull[i].x << " " << hull[i].y << endl;
    // }
    long long ans = 0;
    for(int i=0; i<hull.size(); i++){
        if(i!=hull.size()-1){
            ans+=(hull[i].x*hull[i+1].y-hull[i+1].x*hull[i].y);
        }
        else{
            ans+=(hull[hull.size()-1].x*hull[0].y-hull[0].x*hull[hull.size()-1].y);
        }
    }
    cout << ans << endl;
}