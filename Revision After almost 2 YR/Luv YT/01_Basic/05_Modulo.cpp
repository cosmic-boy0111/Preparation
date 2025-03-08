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


/*
// (a + b) % m = ((a % m) + (b % m)) % m;
// (a * b) % m = ((a % m) * (b % m)) % m;
// (a - b) % m = ((a % m) - (b % m) + m) % m; // +m to make value positive
// (a / b) % m = ((a % m) * (b^-1 % m)) % m // b^-1 nultiplicative inverse
*/


/*
Given a number N. Print its factorial.
1 <= N <= 100

print answer modulo M
// Where M = 47
Where M = 10^9 + 7 // very close to the integer maximum value
*/


int32_t main(){

    int n;
    cin >> n;
    int M = 47;
    long long fact = 1;
    for(int i = 2 ; i <= n ; i++){
        fact = (fact * i) % M;
    }

    cout << fact << endl;

}