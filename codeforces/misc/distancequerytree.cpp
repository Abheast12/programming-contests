#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int, pair<pair<int, int>,int>> edge;
int subtreesize[200200];
int pathsum[200200];
vector<pair<int, int>> graph[200200];

int timer = 0, tin[200000], euler_tour[400000];
int segtree[1600000];  // Segment tree for RMQ

void dfs(int node = 0, int parent = -1) {
	tin[node] = timer;  // The time when we first visit a node
	euler_tour[timer++] = node;
	for (pair<int,int> i : graph[node]) {
		if (i.first != parent) {
			dfs(i.first, node);
			euler_tour[timer++] = node;
		}
	}
}

int mn_tin(int x, int y) {
	if (x == -1) return y;
	if (y == -1) return x;
	return (tin[x] < tin[y] ? x : y);
}

// Build the segment tree: run `build()` after running dfs`
void build(int node = 1, int l = 0, int r = timer - 1) {
	if (l == r) segtree[node] = euler_tour[l];
	else {
		int mid = (l + r) / 2;
		build(node * 2, l, mid);
		build(node * 2 + 1, mid + 1, r);
		segtree[node] = mn_tin(segtree[node * 2], segtree[node * 2 + 1]);
	}
}

int query(int a, int b, int node = 1, int l = 0, int r = timer - 1) {
	if (l > b || r < a) return -1;
	if (l >= a && r <= b) return segtree[node];
	int mid = (l + r) / 2;
	return mn_tin(query(a, b, node * 2, l, mid),
	              query(a, b, node * 2 + 1, mid + 1, r));
}

// Make sure you run $dfs` and `build()` before you run this
int lca(int a, int b) {
	if (tin[a] > tin[b]) swap(a, b);
	return query(tin[a], tin[b]);
}



void pathsumdfs(int node, int parent, int tot){
    pathsum[node] = tot;
    for(pair<int,int> x: graph[node]){
        if(x.first!=parent){
            pathsumdfs(x.first, node, tot+x.second);
        }
    }
    return;
}

int subtreesizedfs(int node, int parent){
    int tot = 0;
    for(pair<int,int> x: graph[node]){
        if(x.first!=parent){
            tot += subtreesizedfs(x.first, node);
        }
    }
    subtreesize[node] = 1 + tot;
    return 1 + tot;
}


void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
        // Add 'val' to current node of BI Tree
        BITree[index] += val;
 
        // Update index to that of parent in update View
        index += index & (-index);
    }
}
 
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
 
    // Uncomment below lines to see contents of BITree[]
    //for (int i=1; i<=n; i++)
    //      cout << BITree[i] << " ";
 
    return BITree;
}
 
// SERVES THE PURPOSE OF getElement()
// Returns sum of arr[0..index]. This function assumes
// that the array is preprocessed and partial sums of
// array elements are stored in BITree[]
int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
 
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
 
    // Traverse ancestors of BITree[index]
    while (index>0)
    {
        // Add current element of BITree to sum
        sum += BITree[index];
 
        // Move index to parent node in getSum View
        index -= index & (-index);
    }
    return sum;
}
 
// Updates such that getElement() gets an increased
// value when queried from l to r.
void update(int BITree[], int l, int r, int n, int val)
{
    // Increase value at 'l' by 'val'
    updateBIT(BITree, n, l, val);
 
    // Decrease value at 'r+1' by 'val'
    updateBIT(BITree, n, r+1, -val);
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        edge[i] = {{a, b}, c};
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            
        }
    }
}