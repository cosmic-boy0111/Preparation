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

void func(int n){
    if(n==0) return;
    func(n-1);
    cout << n << endl;
}

int fact(int n){
    if(n==0) return 1;
    return fact(n-1)*n;
}

int main(){


    // func(5);
    int n;
    cin >> n;
    cout << fact(n) << endl;
    
    
    return 0;
}

// number of function calls --> n
// complexity of each function call --> O(1)

// complexity = O(n)