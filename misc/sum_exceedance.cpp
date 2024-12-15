#include<iostream>
#include<cmath>
#include<vector>
#include<random>

using namespace std;

int main(){
    
    double ln2 = log(2);
    vector<double>v(100100);
    for(int i=0; i<100010; i++){    
        double tot = 0;
        int cur = 0;
        while(tot < ln2){
            std::random_device rd; // Non-deterministic seed
            std::mt19937 gen(rd()); // Random number generator
            std::uniform_real_distribution<> dis(0, 1); // Distribution in range [0, 1)

            double randomValue = dis(gen); // Generate random value
            tot += randomValue;
            cur++;
        }
        v[i] = cur;
    }

    double avg= 0;
    for(int i=0; i<100010; i++){
        avg += v[i];
    }
    avg /= 100010;
    cout << avg << endl;
    

}