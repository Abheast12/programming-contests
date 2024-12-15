#include<iostream>
#include<vector>
using namespace std;
int dp[850][850];
int a[850];
int solve(int l, int r, int cur){
    if(l>r){
        return 0;
    }
    if(l==r){
        if(cur!=a[l]){
            return 1;
        }
        else return 0;
    }
    else{
        int lb = -1;
        int rb = -1;
        int res = 0;
        for(int i=l+1; i<=r; i++){
            if(a[i]!=a[l] && lb==-1){
                lb = i;
            }
            if(a[i]==a[l] && lb!=-1){
                rb = i-1;
                // if(cur==0){
                //     cout << lb << " " << rb << endl;
                // }
                res+=solve(lb, rb, a[l]);
                lb = -1;
                rb = -1;
            }
        }
        if(lb!=-1){
            rb = r;
            res+=solve(lb, rb, a[l]);
        }
        int res2 = 2109;
        if(a[l]!=a[r]){
            lb = -1;
            rb = -1;
            res2=0;
            for(int i=l; i<r; i++){
                if(a[i]!=a[r] && lb==-1){
                    lb = i;
                }
                if(a[i]==a[r] && lb!=-1){
                    rb = i-1;
                    res2+=solve(lb, rb, a[r]);
                    lb = -1;
                    rb = -1;
                }
            }
            if(lb!=-1){
                rb = r-1;
                res2+=solve(lb, rb, a[r]);
            }
        }
        if(a[l] !=cur){
            res++;
        }
        if(a[r] !=cur){
            res2++;
        }
        // cout << l << " " << r << " " << res << " " << res2 << endl;
        return min(res, res2);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int ans = solve(0, n-1, 0);
    cout << ans << endl;
    
}
