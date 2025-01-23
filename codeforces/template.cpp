#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<random>
#include<numeric>
using namespace std;
#define all(x) begin(x), end(x)
int seg[800800];
int arr[400400];

// Convex Hull implementation
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
// max seg tree implementation
void recalculate(int node, int (&seg)[800800]){
    seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
}
void build(int node, int left, int right, int (&seg)[800800], int (&arr)[400400]){
    if(left == right){
        seg[node] = arr[left];
    }
    else {
        int middle = (left + right) / 2;
        build(2 * node + 1, left, middle, seg, arr);
        build(2 * node + 2, middle + 1, right, seg, arr);
        recalculate(node, seg);
    }
}
void update(int node, int left, int right, int x, int y, int (&seg)[800800]) {
    if (left == right) { //we are in the xth leaf
        seg[node] = y;
    } else {
        int middle = (left + right) / 2;
        if (x <= middle) { //we need to update the left son
            update(2 * node + 1, left, middle, x, y, seg);
        } else {
            update(2 * node + 2, middle + 1, right, x, y, seg);
        }
        //after updating said son, recalculate the current segment
        recalculate(node, seg);
    }
}
int query(int node, int left, int right, int x, int y, int (&seg)[800800]) {
    if (x <= left && right <= y) {
        //the segment of "node" is completely included in the query
        return seg[node];
    } else {
        int answer = INT_MIN;
        int middle = (left + right) / 2;
        if (x <= middle) {
            //the query segment and the left son segment have at least one element in common
            answer = max(answer, query(2 * node + 1, left, middle, x, y, seg));
        }
        if (y >= middle + 1) {
            //the query segment and the right son segment have at least one element in common
            answer = max(answer, query(2 * node + 2, middle + 1, right, x, y, seg));
        }
        //we would not have entered this function if (x, y) and (left, right) had nothing in common,
        //so there is no risk of answer returning -Infinity here, as either the left or the right son
        //would update it
        return answer;
    }
}

// Max Segment Tree implementation (no lazy propagation)
struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { 
        return max(a, b);
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

// dsu implementation
long long maxsz = 1;
int find(int x, vector<long long>&root) {
    while (x != root[x]) {
        if(root[x] != root[root[x]]) root[x] = root[root[x]];
        x = root[x];
    }
    return x;
}
void unite(int a, int b, vector<long long>&root, vector<long long>&sz) {
    int roota = find(a, root);
    int rootb = find(b, root);
    if (sz[roota] < sz[rootb]){
        sz[rootb]+=sz[roota];
        maxsz = max(maxsz, sz[rootb]);
        root[roota] = rootb;
    } else{
        sz[roota] += sz[rootb];
        maxsz = max(maxsz, sz[roota]);
        root[rootb] = roota;
    } 
}

//random number generator in the range [mn, mx]
long long getRandomInRange(long long mn, long long mx) {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long> dis(mn, mx);
    return dis(gen);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        // Union Find set up
        vector<long long>root(n+1), sz(n+1);
        for (int i = 1; i <= n; i++) root[i] = i;
        for (int i = 1; i <= n; i++) sz[i] = 1;

        // Convex Hull input
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

        
        // Sieve of Erasthotenes
        int m = 1e6;
        vector<bool> isPrime(m+1, true);
        isPrime[0] = isPrime[1] = false;
        vector<vector<int>> factors(m+1);
        for (int i = 2; i <= m; i++) {
            if (isPrime[i]) {
                factors[i].push_back(i);
                for (int j = i * 2; j <= m; j += i) {
                    isPrime[j] = false;
                    factors[j].push_back(i);
                }
            }
        }

        for(int i=0; i<n; i++){
            int a;
        }
    }
}