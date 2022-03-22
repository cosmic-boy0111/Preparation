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


bool check(int n,long long pow2){
    if(n < pow2){
        return false;
    }

    if(n > pow2){
        return check(n,pow2*2);
    }

    return true;
}

bool isPowerOfTwo(int n) {
    return check(n,1);
}

int main(){
    
    int n;
    cin >> n;
    
    cout << isPowerOfTwo(n);
    
    return 0;
}