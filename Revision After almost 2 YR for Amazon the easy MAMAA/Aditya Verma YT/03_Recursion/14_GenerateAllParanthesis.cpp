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

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

void generateAllParanthesis(int op, int cl, string out){

    if(cl < op){
        return;
    }

    if(op == 0 and cl == 0){
        cout << out << endl;
        return;
    }
    
    if(out.size() == 0){
        out.push_back('(');
        generateAllParanthesis(op-1, cl, out);
        return;
    }

    string op1 = out;
    string op2 = out;

    if(op > 0){
        op1.push_back('(');
        generateAllParanthesis(op-1, cl, op1);
    }

    if(cl > 0){
        op2.push_back(')');
        generateAllParanthesis(op, cl-1, op2);
    }

}

int32_t main(){

    int n;
    cin >> n;

    generateAllParanthesis(3, 3, "");

}

/*
Problem Description: https://www.interviewbit.com/problems...

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" . 


                          ""  op=3 cl=3
                            |
                        "(" op=2 cl=3
            ((  op=1 cl=3          () op=2 cl=2
((( op=0 cl=3    (() op=1 cl=2   ()( op=1 cl=2  ()) op=2 cl=1                             

                        
*/