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

vector<char> ans;

void reverseString(vector<char>& s) {
    if(s.size()==0)   {
        s = ans;
        return;
    }

    ans.push_back(s[s.size()-1]);
    s.pop_back();
    reverseString(s);
}

int main(){
    
    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);
    for(auto x:s){
        cout << x << " ";
    }


    return 0;
}