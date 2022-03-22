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

vector<string> v;


void solve(int open,int close,string op){


    if(open==0 and close == 0){
        v.push_back(op);
        return;
    }

    if(open != 0){
        string op1 = op;
        op1.push_back('(');
        solve(open-1,close,op1);
    }

    if(close > open and close > 0){
        string op2 = op;
        op2.push_back(')');
        solve(open,close-1,op2);
    }

}


int main(){
    
    int n;
    cin >> n;

    int open = n;
    int close =  n;

    string op = "";

    solve(open,close,op);

    for(auto &x:v){
        cout << x << endl;
    }

    
    return 0;
}