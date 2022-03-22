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

void fib(int n){
    int t1 = 0;
    int t2 = 1;
    for(int i=1;i<=n;i++){
        cout << t1 << " ";
        int temp = t1;
        t1 = t2;
        t2 = temp + t2;
    }

    return;
}

int main(){
    

    int n;
    cin >> n;

    fib(n);
    
    
    return 0;
}