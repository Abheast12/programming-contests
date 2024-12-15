#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    int t;
    int ct=0;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<pair<long long, long long>>v(n);
        vector<pair<pair<long long, long long>, long long>>right(n);
        vector<pair<pair<long long, long long>, long long>>left(n);
        vector<long long>ans(n, 0);
        for(int i=0; i<n; i++){
            long long l,r;
            cin >> l >> r;
            v[i] = {l, r};
            left[i] = {{l, -1*r}, i};
            right[i] = {{r, -1*l}, i};
        }
        vector<int>duplicated(n, 0);
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        priority_queue<pair<long long, long long>>pq;
        for(int i=0; i<right.size(); i++){
            // cout << right[i].first << " " << right[i].second << endl;
            if(!pq.empty() && pq.top().first == right[i].first.first && v[pq.top().second].first < v[right[i].second].first){
                continue; 
            }
            else if(!pq.empty() && pq.top().first == right[i].first.first && v[pq.top().second].first == v[right[i].second].first){
                duplicated[right[i].second] = 1;
                continue;
            }
            else{
                // cout << "here" << right[i].first << " " << right[i].second << endl;
                while(!pq.empty() && v[pq.top().second].first >= v[right[i].second].first){
                    ans[pq.top().second]+= right[i].first.first-pq.top().first;
                    pq.pop();
                }
                pq.push({right[i].first.first, right[i].second});
            }
        }
        // cout << "ans[0]:" << ans[0] << endl;
        while(!pq.empty()){
            pq.pop();
        }

        reverse(left.begin(), left.end());
        for(int i=0; i<(int)left.size(); i++){
            // cout << left[i].first << " " << left[i].second << endl;
            if(!pq.empty() && -1*pq.top().first == left[i].first.first && v[pq.top().second].second > v[left[i].second].second){
                continue; 
            }
            else if(!pq.empty() && -1*pq.top().first == left[i].first.first && v[pq.top().second].second == v[left[i].second].second){
                // pq.pop();
                duplicated[left[i].second] = 1;
                continue;
            }
            else{
                // cout << "here" << left[i].first << " " << left[i].second << endl;
                while(!pq.empty() && v[pq.top().second].second <= v[left[i].second].second){
                    ans[pq.top().second]+= -1*pq.top().first-left[i].first.first;
                    pq.pop();
                }
                pq.push({-1*left[i].first.first, left[i].second});
            }
        }
        while(!pq.empty()){
            pq.pop();
        }
        for(int i=0; i<n; i++){
            ct++;
            // if(ct==3801 && n==20){
            //     for(int j=8; j<12; j++){
            //         cout << v[j].first << "-" << v[j].second << "--";
            //     }
            // }
            if(duplicated[i] == 1){
                cout << 0 << endl;
            }
            else cout << ans[i] << endl;
            
        }
        
        // cout << endl;

    }
}