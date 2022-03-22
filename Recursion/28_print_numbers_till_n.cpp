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

void increasing(int n){
    if(n==0){
        return;
    }

    increasing(n-1);
    cout << n << " ";
}

void decreasing(int n){
    if(n==0){
        return;
    }
    
    cout << n << " ";
    decreasing(n-1);
}


int main(){
    
    int n;
    cin >> n;

    increasing(n);
    cout << endl;
    decreasing(n);



    return 0;
}