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

// Binary Exponentiation
long long binexp(long long bs, long long pw){
    long long res = 1;
    while(pw > 0){
        if(pw%2 == 1){
            res = (res*bs);
        }
        bs = (bs*bs);
        pw >>= 1;
    }
    return res;
}

// Binary Multiplication
long long binmul(long long a, long long b, long long mod){
    long long res = 0;
    while(b){
        if(b&1){
            res = (res+a)%mod;
        }
        a = (a+a)%mod;
        b>>=1;
    }
    return res;
}

// Calculate the modular inverse of a number given prime modulus
long long modinv(long long x, long long m){
    long long res = 1;
    long long pow = m-2;
    while(pow> 0){
        if(pow%2){
            res = (res*x)%m;
        }
        x = (x*x)%m;
        pow=(pow>>1);
    }
    return res;
}

// String Hashing
long long compute_hash(string const& s) {
    const int p = 29;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

// Prefix Hashing (for substring hashing, modified hash calculation)
vector<long long> compute_prefix_hash(string const& s) {
    const int p = 29;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    vector<long long>hashes(s.length());
    for (int i=0; i<s.length(); i++) {
        if(i!=0){
            hashes[i] = hashes[i-1]*p + (s[i] - '0' + 1);
            hashes[i] %= m;
        }
        else{
            hashes[i] = (s[i] - '0' + 1);
            hashes[i] %= m;
        }
    }
    return hashes;
}

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

// Fenwick Tree implementation (uses 1-indexing)
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTree(vector<int> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int val) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }
    
    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
    
    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
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
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
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

        // Computing nCr mod a large prime
        long long mod = 1e9+7;
        vector<long long>factorials(n+1);
        factorials[0] = 1;
        long long cur = 1;
        for(int i=1; i<=n; i++){
            cur = cur*(n-i+1);
            cur%=mod;
            cur*=binexp(i, mod-2);
            cur%=mod;
            factorials[i] = cur;
        }
    }
}