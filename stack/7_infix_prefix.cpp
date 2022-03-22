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
void printBinary(int n){
    for(int i=10;i>=0;i--){
        if((n>>i) & 1) cout << 1;
        else cout << 0;
    }cout << endl;
}
class node{
    public:
        int val;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};


int prec(char c){
    if(c=='^'){
        return 3;
    }else if(c=='*' || c=='/'){
        return 2;
    }else if(c=='+' || c=='-'){
        return 1;
    }

    return -1;
}

string infixToPostfix(string s){
    stack<int> st;
    string res = "";
    for(int i=0;i<s.size();i++){
        char c = s[i];
        if((c >= 'a' and c<='z') || (c >= 'A' and c<='Z')){
            res.push_back(c);
        }else if(c == '('){
            st.push(c);
        }else if(c == ')'){
            while ( !st.empty() and st.top() != '('){
                res.push_back(st.top());
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }else{
            while (!st.empty() and prec(st.top()) > prec(c)){
                res.push_back(st.top());
                st.pop();
            }

            st.push(c);
            
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
    
}


int main(){
    
    string s = "(a-b/c)*(a/k-l)";

    reverse(s.begin(),s.end());

    string newStr = "";
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            newStr.push_back(')');
        }else if(s[i] == ')'){
            newStr.push_back('(');
        }else{
            newStr.push_back(s[i]);
        }
    }

    string res = infixToPostfix(newStr);
    reverse(res.begin(),res.end());

    cout << res << endl;

    
    
    
    return 0;
}