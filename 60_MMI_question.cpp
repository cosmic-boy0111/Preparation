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
const int N = 1e5+10, M= 1e9+7;
int fact[N];

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



int main(){

    fact[0] = 1;
    for(int i=1;i<N;i++){
        fact[i] = (fact[i-1]*1LL*i)%M;
    }

    long long T;
    cin >> T;
    while(T--){
        int n,k;
        cin >> n >> k;

        int ans = fact[n];
        ans = (ans * 1LL * fact[k]) % M;

        int den = (fact[k-n]*1LL*fact[n])%M;
        ans = (ans * 1LL * binExp(den,M-2,M))%M;

        cout << ans << endl;


    }
    
    
    
    return 0;
}