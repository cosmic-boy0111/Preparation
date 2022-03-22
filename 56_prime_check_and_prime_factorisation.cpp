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


int main(){
    
    // int n;
    // cin >> n;
    // bool is_prime = true;

    // for(int i=2;i<n;i++){
    //     if(n%i == 0 ){
    //         is_prime = false;
    //         break;
    //     }
    // }
    // O(n)

    // for(int i=2;i*i<=n;i++){
    //     if(n%i == 0 ){
    //         is_prime = false;
    //         break;
    //     }
    // }

    // cout << is_prime << endl;


    int n;
    cin >> n;
    vector<int> prime_factors;
    for(int i=2;i*i<=n;i++){
        while (n%i==0){
            prime_factors.push_back(i);
            n /= i;
        }
    }

    if(n>1){
        prime_factors.push_back(n);
    }

    each(x,prime_factors){
        cout << x << " ";
    }


    
    
    return 0;
}