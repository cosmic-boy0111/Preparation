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


// if value of a <= 1e18 then first do a%=M and proceed

int binExp(int a,int b){
    int ans = 1;
    while (b)
    {
        if(b&1){
            ans = binMul(ans,a);
        }
        a = binMul(a,a);

        b>>=1;
    }

    return ans;
    
}

// log^2(N)

// if value of M <= 1e18 then use binary expo to multiply

long long binMul(long long a,long long b){
    long long ans = 0;
    while (b)
    {
        if(b&1){
            ans = (ans + a)%MOD;
        }
        a = (a+a)%MOD;

        b>>=1;
    }

    return ans;
}


int main(){
    

    
    
    return 0;
}