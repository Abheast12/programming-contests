#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<tuple>
using namespace std;

// int seg[800800];
// int arr[400400];

struct Node {
    int val;
    int idx;
    Node(int v = 0, int i = -1) : val(v), idx(i) {}
};

Node combine(Node a, Node b, bool isMin) {
    if (isMin) {
        if (a.val == b.val) return a.idx > b.idx ? a : b;
        if (a.val < b.val) return a;
        return b;
    } else {
        if(a.val == b.val) return a.idx > b.idx ? a : b;
        if (a.val > b.val) return a;
        return b;
    }
}

void recalculate(int node, vector<Node>& seg, bool isMin) {
    seg[node] = combine(seg[2 * node + 1], seg[2 * node + 2], isMin);
}

void build(int node, int left, int right, vector<Node>& seg, vector<int>& arr, bool isMin) {
    if (left == right) {
        seg[node] = Node(arr[left], left);
    } else {
        int middle = (left + right) / 2;
        build(2 * node + 1, left, middle, seg, arr, isMin);
        build(2 * node + 2, middle + 1, right, seg, arr, isMin);
        recalculate(node, seg, isMin);
    }
}

void update(int node, int left, int right, int x, int y, vector<Node>& seg, bool isMin) {
    if (left == right) {
        seg[node] = Node(y, left);
    } else {
        int middle = (left + right) / 2;
        if (x <= middle) {
            update(2 * node + 1, left, middle, x, y, seg, isMin);
        } else {
            update(2 * node + 2, middle + 1, right, x, y, seg, isMin);
        }
        recalculate(node, seg, isMin);
    }
}

Node query(int node, int left, int right, int x, int y, vector<Node>& seg, bool isMin) {
    if (x <= left && right <= y) {
        return seg[node];
    } else {
        int middle = (left + right) / 2;
        Node answer = Node(isMin ? INT_MAX : INT_MIN, -1);
        
        if (x <= middle) {
            Node leftResult = query(2 * node + 1, left, middle, x, y, seg, isMin);
            answer = combine(answer, leftResult, isMin);
        }
        if (y >= middle + 1) {
            Node rightResult = query(2 * node + 2, middle + 1, right, x, y, seg, isMin);
            answer = combine(answer, rightResult, isMin);
        }
        return answer;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // int mnseg[400400];
    // int mxseg[400400];
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        if(a > b) swap(a, b);
        // a--; b--;
        vector<Node> mnseg(4*n+1);
        vector<Node> mxseg(4*n+1);
        vector<int> v(n);
        vector<int> r(n+1);
        vector<int> l(n+1);
        r[0] = INT_MAX;
        l[0] = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            r[i+1] = i-v[i];
            l[i+1] = i+v[i];
        }
        build(0, 1, n, mnseg, r, true);
        build(0, 1, n, mxseg, l, false);

        priority_queue<pair<int, int>> pq;
        pq.push({0, a});
        unordered_map<int, int>vis;
        while(!pq.empty()){
            
            int dist = -pq.top().first;
            int pos = pq.top().second;
            cout << "cur" << pos << " " << dist << endl;
            pq.pop();
            if(pos == b){
                cout << dist << endl;
                break;
            }
            if(vis[pos]) continue;
            update(0, 1, n, pos, INT_MAX, mnseg, true);
            update(0, 1, n, pos, INT_MIN, mxseg, false);
            vis[pos] = 1;
            Node mn = query(0, 1, n, pos, min(n, pos+v[pos-1]), mnseg, true);
            Node mx = query(0, 1, n, max(1, pos-v[pos-1]), pos, mxseg, false);

            if(mn.val != INT_MAX && !vis[mn.idx]){
                cout << mn.idx << " " << mn.val << endl;
                pq.push({-1*(dist+1), mn.idx});
            }
            if(mx.val != INT_MIN && !vis[mx.idx]){
                cout << mx.idx << " " << mx.val << endl;
                pq.push({-1*(dist+1), mx.idx});
            }
        }
        while(!pq.empty()) pq.pop();
        v.clear();
        r.clear();
        l.clear();
        mnseg.clear();
        mxseg.clear();
        vis.clear();
    }
}