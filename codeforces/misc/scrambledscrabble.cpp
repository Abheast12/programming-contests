#include<string>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    map<char, int>mp;
    int cons = 0;
    int vow = 0;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
        if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
            vow++;
        }
        else if(s[i]!='Y'){
            cons++;
        }
    }
    if(cons < 2*vow){
        while(cons < 2*vow && mp['Y']>0){
            cons++;
            mp['Y']--;
        }
    }
    else if(cons > 2*vow){
        while(cons > 2*vow && mp['Y']>0){
            if((vow+1)*2>cons){
                break;
            }
            vow++;
            mp['Y']--;
        }
    }
    while(mp['Y']>=3){
        cons+=2;
        vow++;
        mp['Y']-=3;
    }
    cons+=mp['Y'];
    int ans = 0;
    // cout << cons << " " << vow << endl;
    while(cons > 0 && vow > 0){
        
            if(cons>=4 && vow>=1 && cons-4 >= 2*(vow-1) && mp['N']>=2 && mp['G']>=2){
                ans+=5;
                cons-=4;
                mp['N']-=2;
                mp['G']-=2;
                vow--;
            }
            else if(cons>=3 && vow>=1 && (cons-3 >= 2*(vow-1) || (cons-3)%2==0) && mp['N']>=1 && mp['G']>=1){
                ans+=4;
                cons-=3;
                mp['N']--;
                mp['G']--;
                vow--;
            }
            else if(cons>=2 && vow>=1){
                ans+=3;
                cons-=2;
                vow--;
            }
            else break;
        //     if(cons-3 >= 2*(vow-1)){
        //         if(mp['N'] > 0 && mp['G']>0){
        //             ans+=2;
        //             cons-=2;
        //             mp['N']--;
        //             mp['G']--;
        //             vow--;
        //             ans++;
        //             if(mp['N'] > 0 && mp['G']>0){
        //                 if(cons-2 >= 2*vow){
        //                     ans+=2;
        //                     cons-=2;
        //                     mp['N']--;
        //                     mp['G']--;
        //                 }
        //                 else{
        //                     ans++;
        //                     cons--;
        //                 }
        //             }
        //             else{
        //                 ans++;
        //                 cons--;
        //             }
        //         }
        //         else{
        //             ans+=3;
        //             cons-=2;
        //             vow--;
        //         }

        //     }
        //     else{
        //         cons-=2;
        //         vow--;
        //         ans+=3;
        //     }
        // }
        // else break;
    }
    cout << ans << endl;

}