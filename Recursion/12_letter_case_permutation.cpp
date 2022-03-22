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



void solve(string ip,string op){

    if(ip.size()==0){
        cout << op << endl;
        return;
    }

    char c = ip[0];

    ip.erase(ip.begin()+0);

    string op1 = op;
    string op2 = op;

    op1.push_back(char(tolower(c)));
    op2.push_back(char(toupper(c)));

    solve(ip,op1);
    if(!(c>='0' and c<='9'))
        solve(ip,op2);


}


int main(){
    

    // char c;
    // cin >> c;
    // if(c>='a' and c<='z'){
    //     cout << char(c-32) << endl;
    // }else if(c>='A' and c<='Z'){
    //     cout << char(c+32) << endl;
    // }else{
    //     cout << c << endl;
    // }

    string ip;
    cin >> ip;

    string op = "";

    solve(ip,op);

    // char t = 'a';
    // cout << char(tolower(t)) ;
    
    
    
    return 0;
}