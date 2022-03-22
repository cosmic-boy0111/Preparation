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


void printBinary(int num){
    for(int i=10;i>=0;i--){
        cout << ((num>>i)&1);
    }cout << endl;
}

int main(){
   
   // even odd
    // for(int i=0;i<8;i++){
    //     printBinary(i);
    //     if(i&1){
    //         cout << "odd" << endl;
    //     }else{
    //         cout << "even" << endl;
    //     }
    // }

    // divide by 2
    // int n = 5;
    // cout << (n >> 1) << endl;
    // cout << (n << 1) << endl;

/// upper to lower and inverse
    // for(char c = 'A'; c<='E' ; c++){
    //     cout << c << " ";
    //     printBinary(c);
    // }
    // for(char c = 'a'; c<='e' ; c++){
    //     cout << c << " ";
    //     printBinary(c);
    // }

    // cout << char('A' ^ (1<<5)) << endl;
    // cout << char('a' ^ ' ') << endl;


    // cout << char(1<<5) << 't';


// clear LSB

    // printBinary(59);
    // int i = 4;
    // printBinary(59 & ~((1<<i+1)-1));

    // i = 3;
    // printBinary(59 & (1<<(i+1))-1);

// clear msb 

    // 00000111011
    // 00000001111 

    // 00000010000 - 1


// find power of 2 
    int n;
    cin >> n;
    printBinary(n-1);
    printBinary(n);
    printBinary(n & (n-1));




    
    return 0;
}