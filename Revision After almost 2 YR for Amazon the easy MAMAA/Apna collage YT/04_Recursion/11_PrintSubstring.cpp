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

void printSubstring(string in, string out, int idx, int lastIdx){

    cout << out << " " << idx << " " << lastIdx << endl;

    if(in.size() == idx){
        cout << out << endl;
        return;
    }

    string op1 = out;
    string op2 = out;

    if(lastIdx + 1 == idx){
        op2.push_back(in[idx]);
        printSubstring(in, op2, idx + 1, idx);
    }
    printSubstring(in, op1, idx + 1, lastIdx);

}

int32_t main(){

    string s;
    cin >> s;

    string out = "";
    printSubstring(s, out, 0, -1);

}