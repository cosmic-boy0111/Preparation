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

const int M = 1e9+7;


// (A / B) % M = (A * B^-1) % M
//             = ((A%M) * (B^-1)%M) % M


// let a be any number the inverse of i.e a^-1 = a^(m-2) % m

long long binExp(int a,long long b,int m){
    int ans = 1;
    while (b){
        if(b&1){
            ans = (ans*1LL*a)%m;
        }
        a = (a*1LL*a)%m;

        b>>=1;
    }

    return ans;
    
}


// there are n students and k toffees. K < N 
// cout no of ways that each student get 1 toffee only 
// nCk % M , M <= 1e9+7
// N < 10^6 , k < n < 10^6
// n! / ((n-r)! * r!)

const int N = 1e6+10;
int fact[N];

int main(){
    

    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (i*1LL*fact[i-1])%M;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int n,k;
        cin >> n >> k;
        int ans = fact[n];
        int den = ( fact[n-k] * fact[k] )%M;
        ans = (ans * binExp(den,M-2,M))%M;

        cout << ans << endl;

    }
    
    
    
    return 0;
}