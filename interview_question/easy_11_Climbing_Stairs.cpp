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

int fibo(int n){
    int n1 = 1;
    int n2 = 1;
    while(n--){
        int temp = n1;
        n1 = n2;
        n2 = n2 + temp;
    }
    
    return n2;
}

int climbStairs(int n) {
    if(n==1) return 1;
    return fibo(n-1);
}

int main(){
    
    int n;
    cin >> n;

    cout << climbStairs(n) << endl;
    
    return 0;
}