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

void letterCasePermutation(string in, string out){

    if(in.size() == 0){
        cout << out << endl;
        return; 
    }

    string op1 = out;
    string op2 = out;

    char first = in[0];
    in.erase(0, 1);

    if(first >= 'a' and first <= 'z' || first >= 'A' and first <= 'Z')
    {
        op1.push_back(tolower(first));
        op2.push_back(toupper(first));
        letterCasePermutation(in, op1);
    }else{
        op2.push_back(first);
    }
    
    letterCasePermutation(in, op2);

}

int32_t main(){

    string s;
    cin >> s;

    letterCasePermutation(s, "");

}
/*
                ""  a1B2
            a  1B2       A 1B2
           a1  B2        A1 B2
         a1b 2  a1B 2    A1b 2  A1B 2       

Problem Description: https://leetcode.com/problems/letter-...

Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"] . 
            
*/