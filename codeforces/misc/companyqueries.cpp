#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int>v[200200];
int depth = 0;
int arr[400400];
int seg[800800];
int last = 0;
map<int, int>m;

void recalculate(int node){
    seg[node] = min(seg[2 * node + 1], seg[2 * node + 2]);
}
void build(int node, int left, int right){
    if(left == right){
        seg[node] = arr[left];
    }
    else {
        int middle = (left + right) / 2;
        build(2 * node + 1, left, middle);
        build(2 * node + 2, middle + 1, right);
        recalculate(node);
    }
}

int query(int node, int left, int right, int x, int y) {
    if (x <= left && right <= y) {
        //the segment of "node" is completely included in the query
        return seg[node];
    } else {
        int answer = INT_MAX;
        int middle = (left + right) / 2;
        if (x <= middle) {
            //the query segment and the left son segment have at least one element in common
            answer = max(answer, query(2 * node + 1, left, middle, x, y));
        }
        if (y >= middle + 1) {
            //the query segment and the right son segment have at least one element in common
            answer = max(answer, query(2 * node + 2, middle + 1, right, x, y));
        }
        //we would not have entered this function if (x, y) and (left, right) had nothing in common,
        //so there is no risk of answer returning -Infinity here, as either the left or the right son
        //would update it
        return answer;
    }
}

void dfs(int cur, int par){
    m[cur] = last;
    for(int i=0; i<v[cur].size(); i++){
        if(v[cur][i]!=par){
            arr[last] = depth;
            last++;
            depth++;
            dfs(v[cur][i], cur);
            depth--;
        }
    }
    arr[last] = depth;
    last++;
    return;
}

int main(){
    long long n, q;
    cin >> n >> q;
    for(int i=1; i<=n-1; i++){
        long long a;
        cin >> a;
        v[i].push_back(a);
        v[a].push_back(i);
    }
    dfs(1, -1);
    for(int i=0; i<800800; i++){
        seg[i] = INT_MAX;
    }
    build(0, 0, last-1);
    for(int i=0; i<q; i++){
        long long a, b;
        cin >> a >> b;
        int ans = query(0, m[a], m[b], m[a], m[b]);
        cout << ans << endl;
    }
}