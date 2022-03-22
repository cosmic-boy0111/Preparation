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

int strStr(string haystack, string needle) {
    
    int h = haystack.size();
    int n = needle.size();

    if(n > h)
        return -1;
    else if(n==0)
        return 0;
    else if(n==h)
    {
        if(haystack==needle)
            return 0;
        return -1;
    }

    for(int i=0;i<h;i++){
        if(h-i < n)
            break;
        string win = haystack.substr(i,n);
        if(win == needle)
            return i;
    }

    return -1;

}

int main(){
    
    cout << strStr("hello","ll");
    
    
    
    return 0;
}