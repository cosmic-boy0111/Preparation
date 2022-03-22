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

int postfixEvaluation(string s){
    stack<int> st;

    for(int i=0;i<s.size();i++){
        if(s[i]>='0' and s[i]<='9'){
            st.push(s[i]-'0');
        }else{
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1+op2);
                break;

            case '-':
                st.push(op1-op2);
                break;

            case '*':
                st.push(op1*op2);
                break;

            case '/':
                st.push(op1/op2);
                break;

            case '^':
                st.push(pow(op1,op2));
                break;
            
            default:
                break;
            }
        }
    }

    return st.top();
}


int main(){
    

    cout << postfixEvaluation("46+2/5*7+");
    
    return 0;
}