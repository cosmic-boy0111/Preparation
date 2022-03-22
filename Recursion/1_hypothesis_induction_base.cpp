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


void print(int n){

    if(n==0){
        return;
    }

    print(n-1);

    cout << n << " ";
}


int fact(int n){

    if(n==1){
        return 1;
    }

    int temp = fact(n-1);

    return (n*temp);
    
}


int main(){

    print(5);
    cout << endl;
    cout << fact(5) << endl;
    
    return 0;
}