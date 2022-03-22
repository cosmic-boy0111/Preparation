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

// gcd -----> minimum pow elements
// lcm ------> max --/-- --/--

/*
    given two ele a b
    (a*b)/GCD = LCM

*/


int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    
    cout << gcd(4,12) << endl;
    cout << gcd(18,12) << endl;

    cout << (4*6)/gcd(4,6) << endl;

    cout << __gcd(12,18) << endl;
    
    
    return 0;
}