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


int sum(int n,int a[]){

    if(n<0) return 0;

    return a[n] + sum(n-1,a);
}


int digit_sum(int n){

    if(n==0) return 0;

    return n%10 + digit_sum(n/10);
}

int main(){
    

    int n;
    cin >> n;
    cout << digit_sum(n);

    
    return 0;
}