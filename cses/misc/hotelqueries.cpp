#include<iostream>
#include<vector>
#include<climits>
#define int long long
using namespace std;


// struct Tree {
// 	typedef int T;
// 	static constexpr T unit = INT_MIN;
// 	T f(T a, T b) { 
//         return max(a, b);
//     } // (any associative fn)
// 	vector<T> s; int n;
// 	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
// 	void update(int pos, T val) {
// 		for (s[pos += n] = val; pos /= 2;)
// 			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
// 	}
// 	T query(T val, int l, int r, int nd=1) { // query [b, e)
//         // cout << l << " " << r << " " << nd << endl;
//         if(l==r){
//             cout << l << " " << s[nd] << " " << val << endl;
//             update(l-1, s[nd]-val);
//             return l;
//         }
//         if(s[nd*2] >= val){
//             return query(val, l, (l+r)/2, nd*2);
//         }
//         else return query(val, (l+r)/2+1, r, nd*2+1);
// 		// T ra = unit, rb = unit;
// 		// for (b += n, e += n; b < e; b /= 2, e /= 2) {
// 		// 	if (b % 2) ra = f(ra, s[b++]);
// 		// 	if (e % 2) rb = f(s[--e], rb);
// 		// }
// 		// return f(ra, rb);
// 	}
//     T getbeg(){
//         return s[1];
//     }
//     void print(){
//         for(T el: s){
//             cout << el << " ";
//         }
//     }
// };

int seg[800800];
int arr[400400];

// max seg tree implementation
void recalculate(int node, int (&seg)[800800]){
    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}
void build(int node, int left, int right, int (&seg)[800800], int (&arr)[400400]){
    if(left == right){
        seg[node] = arr[left];
    }
    else {
        int middle = (left + right) / 2;
        build(2 * node , left, middle, seg, arr);
        build(2 * node + 1, middle + 1, right, seg, arr);
        recalculate(node, seg);
    }
}
void update(int node, int left, int right, int x, int y, int (&seg)[800800]) {
    if (left == right) { //we are in the xth leaf
        seg[node] = y;
    } else {
        int middle = (left + right) / 2;
        if (x <= middle) { //we need to update the left son
            update(2 * node , left, middle, x, y, seg);
        } else {
            update(2 * node +1, middle + 1, right, x, y, seg);
        }
        //after updating said son, recalculate the current segment
        recalculate(node, seg);
    }
}
void query(int node, int left, int right, int val, int (&seg)[800800], int n) {
    if (left == right) {
        // update(1, 1, n, left, seg[node]-val, seg);
        seg[node] -= val;
        cout << left << " ";
    } else {
        // int answer = INT_MIN;
        int middle = (left + right) / 2;
        if(seg[2*node] >= val){
            query(2*node, left, middle, val, seg, n);
        }
        else query(2*node+1, middle+1, right, val, seg, n);
        seg[node] = max(seg[2*node], seg[2*node+1]);
        // if (x <= middle) {
        //     //the query segment and the left son segment have at least one element in common
        //     answer = max(answer, query(2 * node + 1, left, middle, x, y, seg));
        // }
        // if (y >= middle + 1) {
        //     //the query segment and the right son segment have at least one element in common
        //     answer = max(answer, query(2 * node + 2, middle + 1, right, x, y, seg));
        // }
        //we would not have entered this function if (x, y) and (left, right) had nothing in common,
        //so there is no risk of answer returning -Infinity here, as either the left or the right son
        //would update it
        // return answer;
    }
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    // vector<int>h(n);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    vector<int>r(m);
    for(int i=0; i<m; i++){
        cin >> r[i];
    }
    build(1, 1, n, seg, arr);

    
    // Tree t(n);
    // for(int i=0; i<n; i++){
    //     t.update(i, h[i]);
    // }
    // t.print();
    for(int i=0; i<m; i++){
        if(seg[1] < r[i]) cout << "0 ";
        else{
            query(1, 1, n, r[i], seg, n);
            // cout << ans << " ";
        }
        // cout << t.getbeg() << endl;
        // t.print();
        // cout << endl;
        // if(t.getbeg() < r[i]) cout << "0 ";
        // else{
        //     int ans = t.query(r[i], 1, n);
        //     cout << ans << " ";
        // }
    }
    cout << endl;
}