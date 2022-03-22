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

void generate(string &s,int open,int close){

    if(open==0 and close == 0){
        v.push_back(s);
        return;
    }


    if(open > 0){
        s.push_back('(');
        generate(s,open-1,close);
        s.pop_back();
    }

    if(close > 0 and open < close){
        s.push_back(')');
        generate(s,open,close-1);
        s.pop_back();
    }

}


int main(){

    int n;
    cin >> n;
    string s = "";
    generate(s,n,n);
    
    for(auto x:v){
        cout << x << endl;
    }
    
    
    return 0;
}