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

unordered_map<char,int> symbols = {
    {'[',-1},
    {'(',-2},
    {'{',-3},
    {']',1},
    {')',2},
    {'}',3},
};
bool isValid(string s) {
        stack<char> st;

    for(auto &bracket:s){
        if(symbols[bracket]<0){
            st.push(bracket);
        }else{
            if(st.empty()) return false;
            char top = st.top();
            st.pop();
            if(symbols[top] + symbols[bracket]  != 0) return false;
        }
    }

    if(!st.empty()) return false;
    return true;
}

int main(){
    
    cout << isValid("(){}");
    
    return 0;
}