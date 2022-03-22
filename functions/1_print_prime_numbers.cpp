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

bool isPrime(int x){
    for(int i=2;i<sqrt(x);i++){
        if(x%i == 0)
            return false;
    }

    return true;
}

int main(){
    

    int a,b;
    cin >> a >> b;
    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            cout << i << " ";
        }
    }
    
    
    return 0;
}