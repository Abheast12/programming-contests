#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
#include<tuple>
#include<cmath>
#include <iomanip>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double c1, c2, r;
    cin >> c1 >> c2 >> r;
    int n;
    cin >> n;
    vector<pair<long double, long double>>points;
    vector<long double>lengths;
    vector<pair<long double, long double>>points2;
    // vector<pair<double, double>>points3;
    for(int i=0; i<n; i++){
        long double x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    long double totdist =0;
    for(int i=0; i<n; i++){
        if(i!=n-1){
            long double ggdist = sqrt((points[i+1].first-points[i].first)*(points[i+1].first-points[i].first)+(points[i+1].second-points[i].second)*(points[i+1].second-points[i].second));
            lengths.push_back(ggdist);
            totdist+=ggdist;
        }
        else{
            long double ggdist = sqrt((points[0].first-points[i].first)*(points[0].first-points[i].first)+(points[0].second-points[i].second)*(points[0].second-points[i].second));
            lengths.push_back(ggdist);
            totdist+=ggdist;
        }
    }
    sort(lengths.begin(), lengths.end());
    long double mid = lengths[n/2];

    for(int i=0; i<n; i++){
        points2.push_back(points[i]);
        // long long ai = (long long)((double)lengths[i]/(double)totdist * 1.8e7);
        
        if(i!=n-1){
            long double curdist = sqrt((points[i+1].first-points[i].first)*(points[i+1].first-points[i].first)+(points[i+1].second-points[i].second)*(points[i+1].second-points[i].second));
            long long ai;
            if(curdist >= mid){
                ai = 5e5;
            }
            else{
                ai = 8e4;
            }
            long double xdif = (points[i+1].first-points[i].first)/(long double)(ai+1);
            long double ydif = (points[i+1].second-points[i].second)/(long double)(ai+1);
            for(int j=0;j<ai; j++){
                points2.push_back({points[i].first+xdif*(j+1), points[i].second+ydif*(j+1)});
            }
        }
        else{
            long double curdist = sqrt((points[0].first-points[i].first)*(points[0].first-points[i].first)+(points[0].second-points[i].second)*(points[0].second-points[i].second));
            long long ai;
            if(curdist >= mid){
                ai = 5e5;
            }
            else{
                ai = 8e4;
            }
            long double xdif = (points[0].first-points[i].first)/(long double)(ai+1);
            long double ydif = (points[0].second-points[i].second)/(long double)(ai+1);
            for(int j=0;j<ai; j++){
                points2.push_back({points[i].first+xdif*(j+1), points[i].second+ydif*(j+1)});
            }
        }
    }
    lengths.clear();
    // cout << points2.size() << endl;
    long double tot1 = 0;
    long double tot2 = 0;
    bool start = false;
    long double prevx, prevy;
    long double startx, starty;
    for(pair<long double, long double>p : points2){
        long double dist1 = sqrt((c1-p.first)*(c1-p.first)+(c2-p.second)*(c2-p.second));
        long double newdist = r*r/dist1;
        long double newx = c1+(p.first-c1)*newdist/dist1;
        long double newy = c2+(p.second-c2)*newdist/dist1;
        // cout << tot1 << " " << tot2 << endl;
        if(start){
            tot1+=prevx*newy;
            tot2+=prevy*newx;
        }
        else{
            start = true;
            startx = newx;
            starty = newy;
        }
        prevx = newx;
        prevy = newy;
        // points3.push_back({newx,newy});
    }
    tot1+=prevx*starty;
    tot2+=prevy*startx;
    long double ans = abs(tot1-tot2)/(long double)2.0;
    cout << setprecision(20) << ans << endl;

}