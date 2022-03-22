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


bool getBit(int n,int pos){
    return (n & (1<<pos));
}


void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}

int setBit(int n,int pos){
    return (n ^ (1<<pos));
}

int clearBit(int n,int pos){
    if((n>>pos) & 1)
        return (n^(1<<pos));
    return n;
}

int updateBit(int n,int pos,int value){
    int t = clearBit(n,pos);
    return (n | (value << pos));
}


int main(){
    
    cout << getBit(5,2);

    printBinary(5);

    printBinary(updateBit(5,1,1));
    
    
    return 0;
}