#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
// vector<pair<int, int>>v[100100];
// map<pair<int, int>, int>mp;
// int maxsz = 1;
long long root[100100][65], sz[100100][65];
long long find(long long x, long long y) {
    while (x != root[x][y]) {
        // if(root[x] != root[root[x]]) root[x] = root[root[x]];
        x = root[x][y];
    }
    return x;
}
bool check(long long a, long long b, long long y, long long yy){
    while(a!=b){
        while(b > a){
            if(find(b, yy) != find(root[b][y], yy)) return false;
            b = root[b][y];
            if(b==root[b][y])break;
        }
        if(a==b) return true;
        while(a > b){
            if(find(a, yy)!=find(root[a][y], yy)) return false;
            a = root[a][y];
            if(a==root[a][y] && a > b) return false;
        }
        if(a==b) return true;
        if(b==root[b][y]) return false;
    }
    
    
    
    return true;
}
void unite(long long a, long long b, long long y) {
    long long roota = find(a, y);
    long long rootb = find(b, y);
    if(roota < rootb){
        root[rootb][y] = roota;
    } else{
        root[roota][y] = rootb;
    }
    // if (sz[roota][y] < sz[rootb][y]){
    //     sz[rootb][y]+=sz[roota][y];
    //     // maxsz = max(maxsz, sz[rootb]);
    //     root[roota][y] = rootb;
    // } else{
    //     sz[roota][y] += sz[rootb][y];
    //     // maxsz = max(maxsz, sz[roota]);
    //     root[rootb][y] = roota;
    // }
    
}
// void generate_numbers(int n) {
//     int start=0;
//     for(int i=59; i>=0; i--){
//         if((1LL << i) & n){
//             start = i;
//             break;
//         }
//     }
//     if(start == 0) return;
//     vector<long long>bi;
//     long long num = (1LL << start);
//     for(int i=start-1; i>=0; i--){
//         if(!((1LL << i) & n)){
//             num+=(1LL << i);
//             bi.push_back(num);
//             num-=(1LL << i);
//         }
//         else {
//             num+=(1LL << i);
//         }
//     }
//     while (n != 0) {
//         int bit = n & -n;
//         n |= bit << 1;
//         n &= ~(bit - 1);
//         std::cout << n << std::endl;
//     }
//     std::cout << n << std::endl;
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m, q2, V;
    
    // for (int i = 1; i <= n; i++) sz[i] = 1;
    cin >> n >> m >> q2 >> V;
    
    // unite(1, 2, 3);
    // long long gg = find(1, 3);
    // cout << gg << endl;
    // return 0;
    vector<long long>bi;
    int start=0;
    for(int i=59; i>=0; i--){
        if((1LL << i) & V){
            start = i;
            break;
        }
        else{
            bi.push_back(1LL << i);
        }
    }
    // if(start == 0) return;
    // vector<long long>bi;
    // cout << start << endl;
    if(start!=0){
        long long num = (1LL << start);
        for(int i=start-1; i>=0; i--){
            if(!((1LL << i) & V)){
                num+=(1LL << i);
                bi.push_back(num);
                num-=(1LL << i);
            }
            else {
                num+=(1LL << i);
            }
        }
        bi.push_back(V);
    }
    for (int i = 1; i <= n; i++){
        for(int j=0; j<65; j++){
            root[i][j] = i;
            sz[i][j] = 1;
        }
    }
    // for(int i=0;i<(int)bi.size(); i++){
    //     cout << bi[i] << endl;
    // }
    for(int i=0; i<m; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(c >= V){
            for(int j=0; j<(int)bi.size(); j++){
                if((bi[j] & c) == bi[j]){
                    unite(a, b, j);
                }
            }
            // for(long long j=59; j>=0; j--){
            
            //     // cout << j << endl;
            //     if((1LL << j) & c){
            //         // cout << j << " " << c << endl;
            //         cout << "a,b,j " <<  a << " " << b << " " << j << endl;
            //         unite(a, b, j);
            //     }
            //     // unite(a, b, j);
                
            //     else break;
            // }
            // if((c & V) == V){
            //     cout << "a,b,j " <<  a << " " << b << endl;
            //     unite(a, b, 60);
            // }
        }
        // if(c>=V){
        //     v[a].push_back({b, c});
        //     v[b].push_back({a, c});
        // }
    }
    // cout << root[2][0] << " " << root[1][0] << endl;
    for(int i=0; i<q2; i++){
        bool t = false;
        long long a, b;
        cin >> a >> b;
        // if(a > b) swap(a, b);
        // cout << a << " " << b << endl;
        // if(find(a, 60) == find(b, 60)){
        //     cout << "Yes" << endl;
        // }
        // else{
        //     for(long long j=59; j>=0; j--){
        //         if((1LL << j) >= V){
        //             if(find(a, j) == find(b, j)){
        //                 t = true;
        //                 cout << "Yes" << endl;
        //                 break;
        //             }
        //         }
        //         else {
        //             long long k =j;
        //             if(find(a, j) != find(b, j)){
        //                 t = true;
        //                 cout << "No" << endl;
        //                 break;
        //             }
        //             long long tot = (1LL << j);
        //             for(long long k=j-1; k>=0; k--){
        //                 if(check(a, b, j, k) && check(a,b, j, k)){
        //                     tot += (1LL << k);
        //                 }
        //             }
        //             if(tot >= V){
        //                 t = true;
        //                 cout << "Yes" << endl;
        //                 break;
        //             }
        //             else{
        //                 t = true;
        //                 cout << "No" << endl;
        //                 break;
        //             }
        //         }
        //     }
        //     if(!t) cout << "No" << endl;
        // }

        for(int j=0; j<(int)bi.size(); j++){
            if(find(a, j) == find(b, j)){
                t = true;
                cout << "Yes" << endl;
                break;
            }
            
        }
        if(!t) cout << "No" << endl;
        // int a, b;
        // cin >> a >> b;
        // queue<pair<pair<int, int>, vector<int>>>q;
        // int vis[100100] = {0};
        // // vis[a] = 1;
        // vector<int>v2;
        // q.push({{a, -1}, v2});
        // bool t = false;
        // while(!q.empty()){
            
        //     int x = q.front().first.first;
        //     int y = q.front().first.second;
        //     vector<int>v3 = q.front().second;
        //     vis[x] = 1;
        //     cout << x << " " << y << endl;
        //     if(x == b){
        //         cout << "Yes" << endl;
        //         mp[{a, b}] = 1;
        //         mp[{b, a}] = 1;
        //         break;
        //     }
        //     q.pop();
        //     if(y == -1){
        //         for(auto it : v[x]){
        //             if(vis[it.first]!=1){
        //                 if(it.second>=V){
        //                     if(mp[{it.first, b}]==1 || mp[{b, it.first}]==1){
        //                         // mp[{a, b}] = 1;
        //                         cout << "Yes" << endl;
        //                         t = true;
        //                         for(int j=0; j<(int)v3.size(); j++){
        //                             mp[{a, v3[j]}] = 1;
        //                             mp[{v3[j], a}] = 1;
        //                             mp[{v3[j], b}] = 1;
        //                             mp[{b, v3[j]}] = 1;
        //                         }
        //                         break;
        //                     }
        //                     if(mp[{it.first, b}]!=-1 || mp[{b, it.first}]!=-1){
        //                         // mp[{a, b}] = -1;
        //                         // cout << "No" << endl;
        //                         // t = true;
        //                         // break;
        //                         v3.push_back(it.first);
        //                         q.push({{it.first, it.second}, v3});
        //                     }
                            
        //                 }
        //             }
                    
        //         }
        //     }
        //     else{
        //         for(auto it : v[x]){
                    
        //             if(vis[it.first]!=1){
        //                 // cout << x << " " << it.first << endl;
        //                 // printf("a&b = %d\n", it.second & y);
        //                 // cout << V << endl;
        //                 if((it.second & y)>=V){
        //                     // cout << 69 << endl;
        //                     if(mp[{it.first, b}]==1){
        //                         // mp[{a, b}] = 1;
        //                         cout << "Yes" << endl;
        //                         t = true;
        //                         for(int j=0; j<(int)v3.size(); j++){
        //                             mp[{a, v3[j]}] = 1;
        //                             mp[{v3[j], a}] = 1;
        //                             mp[{v3[j], b}] = 1;
        //                             mp[{b, v3[j]}] = 1;
        //                         }
        //                         break;
        //                     }
        //                     if(mp[{it.first, b}]!=-1 || mp[{b, it.first}]!=-1){
        //                         // mp[{a, b}] = -1;
        //                         // cout << "No" << endl;
        //                         // t = true;
        //                         // break;
        //                         // cout << it.first << endl;
        //                         // printf("a&b = %d\n", it.second & y);
        //                         v3.push_back(it.first);
        //                         q.push({{it.first, it.second & y}, v3});
        //                     }
        //                     // q.push({it.first, it.second&y});
        //                 }
        //             }
        //         }
        //     }
        //     if(t) break;
            
        // }
        // if(mp[{a, b}]!=1) {
        //     cout << "No" << endl;
        //     mp[{a, b}] = -1;
        //     mp[{b, a}] = -1;
        // }
        // else{
            
        // }
    }
}