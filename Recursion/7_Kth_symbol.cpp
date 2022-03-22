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

// S1 = "0"
// S2 = "011" 1 
// S3 = "0 1 1 1 0 0 1" 3 
// S4 = "0111001 1 0110001" 

// 1 2 3 4 5 6 7 8 9 10

int solve(int n,int k){
    if(n==1 and k==1){
        return 0;
    }

    int mid = pow(2,n-1)/2;

    
    if(k<=mid)
        return solve(n-1,k);

    return !solve(n-1,k-mid);
}

int main(){    

    int n,k;
    cin >> n >> k;
    cout <<  solve(n,k);


    return 0;
}