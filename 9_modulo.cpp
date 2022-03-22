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
#define pb push_back
#define inc(i,a,b) for(int i=a;i<b;i++)
#define dec(i,a,b) for(int i=a;i>=b;i--)
#define each(x,target) for(auto &x:target)
const int N = 1e6, MOD = 1e9+7;


// 1. (a+b) % m = ((a%m) + (b%m)) % m
// 2. (a*b) % m = ((a%m) * (b%m)) % m
// 3. (a+b) % m = ((a%m) - (b%m) + m) % m // to negelate the -ve values and it dont cause any affect to the evaluation
// 4. (a/b) % m = ((a%m) * (b^-1)%m) % m




/*
given a number N. print its factorial.
constrains
1 <= N <= 100

print ans modulo M
where M = 10^9 + 7

m = very closed to integer maximum
m = it is prime no
m = it gives MMI(MULTIPLICATIVE INVERSE)
*/

int main(){
    
    int n;
    cin >> n;
    long long fact = 1;
    inc(i,2,n+1){
        fact = (fact * i)%MOD;
    }

    cout << fact << endl;
    
    return 0;
}