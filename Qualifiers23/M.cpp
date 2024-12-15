#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    for(int i=0;i<t; i++){
        int n, k;
        cin >> n >> k;
        vector<pair<long long, long long>>v;
        for(int j=0; j<n; j++){
            long long x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        int start = 0, end = k;
        int a = n-1;
        long long ans = 0;
        long long pans = 0;
        long long suml = 0;
        long long sumr = 0;
        for(int j=0; j<k; j++){
            suml+=v[j].first*v[j+1].second;
            sumr+=v[j].second*v[j+1].first;
        }
        int last = 0;
        // ans = (double)(abs(suml-sumr))/(double)2;
        // cout << suml << " " << sumr << endl;
        for(int j=0; j<n; j++){
            start%=n;
            end%=n;
            long long left = 1, right = n-k-1;
            while(left<=right){
                long long mmid = (left+right)/2;
                long long mid = end + mmid;
                mid%=n;
                // cout << mid << endl;
                long long lmid = (mid-1+n)%n;
                long long rmid = (mid+1)%n;
 
                long long suml1 = suml+v[mid].first*v[start].second+v[end].first*v[mid].second;
                long long sumr1 = sumr+v[mid].second*v[start].first+v[end].second*v[mid].first;
                long long tans = (abs(suml1-sumr1));
                bool tt = false;
                if(lmid!=start){
                    long long suml1 = suml+v[lmid].first*v[start].second+v[end].first*v[lmid].second;
                    long long sumr1 = sumr+v[lmid].second*v[start].first+v[end].second*v[lmid].first;
                    if(tans < (abs(suml1-sumr1))){
                        tt=true;
                        ans = max(ans, abs(suml1-sumr1));
                        right = mmid-1;
                     
                    }
                }
                if(rmid!=end){
                    long long suml1 = suml+v[rmid].first*v[start].second+v[end].first*v[rmid].second;
                    long long sumr1 = sumr+v[rmid].second*v[start].first+v[end].second*v[rmid].first;
                    if(tans < (abs(suml1-sumr1))){
                        tt=true;
                        ans = max(ans, abs(suml1-sumr1));
                        left = mmid+1;
                      
                    }
                }
                if(!tt){
                    ans = max(ans, tans);
                    break;
                }
            }
            start++;
            end++;
            start%=n;
            end%=n;
            int starte = (n+start-1)%n;
            suml -= v[starte].first*v[start].second;
            sumr -= v[starte].second*v[start].first;
            int ende = (n+end-1)%n;
            suml += v[ende].first*v[end].second;
            sumr += v[ende].second*v[end].first;
        }
        v.clear();
        long double anss = (long double)ans/(long double)2;
        cout << fixed << setprecision(10) << anss << endl;
    }
}