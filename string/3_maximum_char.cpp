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
    
    string s = "fashffadfasdf";
    unordered_map<char,int> mp;
    for(auto &x:s){
        mp[x]++;
    }

    char ans = 'a';
    int frq = 0;
    for(auto &x:mp){
        if(x.second > frq){
            frq = x.second;
            ans = x.first;
        }
    }

    cout << ans << " " << frq <<  endl;

    
    
    return 0;
}