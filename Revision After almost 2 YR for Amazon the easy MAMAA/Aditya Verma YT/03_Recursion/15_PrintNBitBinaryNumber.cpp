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

void printNbitBinary(int in, string out, int zero, int one){

    if(in == 0){
        cout << out << endl; 
        return;
    }

    if(out.size() == 0){
        out.push_back('1');
        printNbitBinary(in-1, out, zero, one+1);
        return;
    }

    string op1 = out;
    string op2 = out;
    op1.push_back('1');
    op2.push_back('0');

    printNbitBinary(in-1, op1, zero, one+1);
    if(zero+1 < one + in){
        printNbitBinary(in-1, op2, zero+1, one);
    }


}

int32_t main(){

    int n;
    cin >> n;

    printNbitBinary(n, "", 0 , 0);

}

/*

Problem Description: https://practice.geeksforgeeks.org/pr...

Given a positive integer N, print all N bit binary numbers having more 1’s than 0’s for any prefix of the number.

Input:
2
2
3
Output:
11 10
111 110 101 . 

                           ""  3
                  1 2                 0 2
            11 1     10 1           01 1     00 1
    111 0  110 0  101 0  100 0   011 0  010 0    001 0  000 0    

                1 - 1
                0 - 1
                t - 1

                1 - 2
                0 - 0
                t - 1

*/