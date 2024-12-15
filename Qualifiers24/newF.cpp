#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

struct Node {
    int val;
    int idx;
    Node(int v = INT_MAX, int i = -1) : val(v), idx(i) {}
};

Node combine(Node a, Node b, bool isMin) {
    if (isMin) {
        return (a.val < b.val) ? a : b;
    } else {
        return (a.val > b.val) ? a : b;
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

void update(int node, int left, int right, int x, Node newValue, vector<Node>& seg, bool isMin) {
    if (left == right) {
        seg[node] = newValue;
    } else {
        int middle = (left + right) / 2;
        if (x <= middle) {
            update(2 * node + 1, left, middle, x, newValue, seg, isMin);
        } else {
            update(2 * node + 2, middle + 1, right, x, newValue, seg, isMin);
        }
        recalculate(node, seg, isMin);
    }
}

Node query(int node, int left, int right, int x, int y, vector<Node>& seg, bool isMin) {
    if (x > right || y < left) return Node(isMin ? INT_MAX : INT_MIN);
    
    if (x <= left && right <= y) return seg[node];
    
    int middle = (left + right) / 2;
    Node leftResult = query(2 * node + 1, left, middle, x, y, seg, isMin);
    Node rightResult = query(2 * node + 2, middle + 1, right, x, y, seg, isMin);
    
    return combine(leftResult, rightResult, isMin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;

        vector<Node> mnseg(4*n+1), mxseg(4*n+1);
        vector<int> v(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        vector<int> r(n), l(n);
        for(int i = 0; i < n; i++) {
            r[i] = i - v[i];
            l[i] = i + v[i];
        }

        build(0, 0, n-1, mnseg, r,true);
        build(0 ,0 ,n-1 ,mxseg ,l,false);

        queue<pair<int ,int>> q;
        q.push({0, a-1});

        vector<int> dist(n ,INT_MAX);
        dist[a-1] = 0;

        while(!q.empty()) {
            int d = q.front().first;
            int u = q.front().second;
            // cout << d << " " << u << endl;
            q.pop();
            dist[u] = d;
            if(u == b-1) break;
            // Clear the current position from segment trees
            update(0 ,0 ,n-1 ,u ,Node(INT_MAX ,u), mnseg, true);
            update(0 ,0 ,n-1 ,u ,Node(INT_MIN ,u), mxseg, false);

            // Query for minimum
            while(true){
                Node mn = query(0 ,0 ,n-1 ,u+1,min(n-1,u+v[u]),mnseg,true);
                if(mn.val == INT_MAX || mn.idx <= u || dist[mn.idx] != INT_MAX || r[mn.idx] > u)
                    break;
                // dist[mn.idx] = dist[u] + 1;
                // q.push(mn.idx);
                q.push({d+1, mn.idx});
                update(0 ,0 ,n-1 ,mn.idx ,Node(INT_MAX,mn.idx),mnseg, true); 
                update(0 ,0 ,n-1 ,mn.idx ,Node(INT_MIN,mn.idx),mxseg, false); 
            }

            // Query for maximum
            while(true){
                Node mx = query(0 ,0 ,n-1,max(u-v[u],0),u-1,mxseg,false);
                if(mx.val == INT_MIN || mx.idx >= u || dist[mx.idx] != INT_MAX || l[mx.idx] < u)
                    break;
                // dist[mx.idx] = dist[u] + 1;
                // q.push(mx.idx);
                q.push({d+1, mx.idx});
                update(0 ,0 ,n-1,mx.idx ,Node(INT_MAX,mx.idx),mnseg, true); 
                update(0 ,0,n-1,mx.idx ,Node(INT_MIN,mx.idx),mxseg, false); 
            }
        }

        cout << dist[b-1] << endl;
    }

    return 0;
}