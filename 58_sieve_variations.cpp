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
// const int N = 1e6, MOD = 1e9+7;

const int N = 1e7+10;
vector<bool> isPrime(N,1);
vector<int> lp(N,0),hp(N,0);

const int M = 1e5+10;
vector<int> divisors[M];
int sum[M];

int main(){

    // fnding divisors

    for(int i=2;i<M;i++){
        for(int j=i;j<M;j+=i){
            divisors[j].push_back(i);
            sum[j] += i;
        }
    }

    for(int i=2;i<10;i++){
        each(x,divisors[i]){
            cout << x << " ";
        }cout << endl;
    }

    
    // finding lowest and highest prime of any no

    // isPrime[0] = isPrime[1] = false;
    // inc(i,2,N){
    //     if(isPrime[i] == true){
    //         lp[i] = hp[i] = i;
    //         for(int j=2*i;j<N;j+=i){
    //             isPrime[j] = false;
    //             hp[j] = i;
    //             if(lp[j] == 0){
    //                 lp[j] = i;
    //             }
    //         }
    //     }
    // }

    // // for(int i=2;i<=100;i++){
    // //     cout << lp[i] << " " << hp[i] << endl;
    // // }

    // int num;
    // cin >> num;

    // unordered_map< int , int > prime_factors;

    // while (num > 1)
    // {
    //     int prime_factor = hp[num];
    //     while (num % prime_factor == 0)
    //     {
    //         num /= prime_factor;
    //         // prime_factors.push_back(prime_factor);
    //         prime_factors[prime_factor] ++;
    //     }
        
    // }

    // // log(N);

    // each(x,prime_factors){
    //     cout << x.first << " " << x.second << endl;
    // }
    




    
    
    
    return 0;
}