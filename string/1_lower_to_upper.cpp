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


int main(){
    
    string s = "jbadgaifadffdd";

    // for(int i=0;i<str.size();i++){
    //     str[i] -=32;
    // }

    // cout << str << endl;

    // for(int i=0;i<str.size();i++){
    //     str[i] +=32;
    // }

    // cout << str << endl;

    transform(s.begin(),s.end(),s.begin(), ::toupper);
    cout << s << endl;
    transform(s.begin(),s.end(),s.begin(), ::tolower);
    cout << s << endl;

    
    
    return 0;
}