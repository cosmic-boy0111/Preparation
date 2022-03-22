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
    
    printBinary(13);
    int a = 13;
    int i = 3;

    if(a & (1<<i)){
        cout << "Set" << endl;
    }else{
        cout << "Not Set" << endl;
    }
// set
    printBinary(a | (1<<1));
// unset
    printBinary( a & (~(1<<3)));




    printBinary(a ^ (1<<3));


    int cnt = 0;
    for(int i=31;i>=0;i--){
        if(a & (1<<i)){
            cnt ++ ;
        }
    }
    
    cout << cnt << endl;

    cout << __builtin_popcount(a) << endl ;
    
    return 0;
}