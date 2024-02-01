#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int n;
    double att, dex, def, hp, minD, maxD;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> att >> dex >> def >> hp >> minD >> maxD;
        double mult = 0.5 + att/50;
        minD*=mult;
        maxD*=mult;
        minD = max(0.1*minD, minD - def);
        maxD = max(0.1*maxD, maxD - def);
        dex = 1.5 + 6.5 * dex/75;
        minD*=dex; maxD*=dex;
        cout << setprecision(10) << hp/maxD << " " << hp/minD << endl;
    }
}