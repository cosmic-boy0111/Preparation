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


void solve(int n,int one,int zero,string op){

    if(n==0){
        cout << op << endl;
        return;
    }

    string op1 = op;
    string op2 = op;

    op1.push_back('1');
    solve(n-1,one+1,zero,op1);

    if(one>zero){
        op2.push_back('0');
        solve(n-1,one,zero+1,op2);
    }

}


int main(){

    int n;
    cin >> n;
    int one = 0;
    int zero = 0;
    string op = "";

    solve(n,one,zero,op);
    
    
    return 0;
}