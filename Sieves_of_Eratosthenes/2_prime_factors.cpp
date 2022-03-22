#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>
#define pi pair<int,int>
#define mi map<int,int>
#define umi unordered_map<int,int>
#define qi queue<int>
#define vpi vector<pi>
#define vvi vector<vi>
#define ff first
#define ss second 
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;
void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}

int lp[N],hp[N];
vector<bool> isPrime(N,1);



int main(){


    
    // finding lowest and highest prime of any no

    isPrime[0] = isPrime[1] = false;
    inc(i,2,N){
        if(isPrime[i] == true){
            lp[i] = hp[i] = i;
            for(int j=2*i;j<N;j+=i){
                isPrime[j] = false;
                hp[j] = i;
                if(lp[j] == 0){
                    lp[j] = i;
                }
            }
        }
    }

    // for(int i=2;i<=100;i++){
    //     cout << lp[i] << " " << hp[i] << endl;
    // }

    int num;
    cin >> num;

    unordered_map< int , int > prime_factors;

    while (num > 1)
    {
        int prime_factor = hp[num];
        while (num % prime_factor == 0)
        {

            cout << prime_factor << " ";
            num /= prime_factor;
            // prime_factors.push_back(prime_factor);
            // prime_factors[prime_factor] ++;
        }
        
    }
    

   
    
    
    return 0;
}