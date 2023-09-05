#include<iostream>
#include<vector>
// #include<math.h>
using namespace std;
vector<int>v;
bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
  
    return true;
}
  
// Function to print primes
void printPrime(int n)
{
    for (int i = 2; i <= n; i++) {
        if (isPrime(i))
            v.push_back(i);
    }
}
int main(){
    printPrime(1000);
    // for(int i=0; i<v.size(); i++){
    //     cout << v[i] << " ";
    // }
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, m;
        cin >> n >> m;
        // int s = sqrt(n);
        if(m==1 || n==1){
            cout << "YES" << endl;
        }
        else if(m>=n){
            cout << "NO" << endl;
        }
        else if(n%2==0 || n%m==0){
            cout << "NO" << endl;
        }
        else{
            bool b = false;
            for(int j=0; j<v.size(); j++){
                if(v[j]>m){
                    cout << "YES" << endl;
                    b = true;
                    break;
                }
                else if(n%v[j] == 0){
                    cout << "NO" << endl;
                    b = true;
                    break;
                }
            }
            if(!b){
                cout << "YES" << endl;
            }
        }
        
        // else cout << "YES" << endl;
    }
}