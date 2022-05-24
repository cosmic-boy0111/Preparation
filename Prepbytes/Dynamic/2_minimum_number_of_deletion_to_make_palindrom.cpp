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
vector<bool> visited(N,false);

// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

int32_t main(){
    

    string x;
    cin >> x;

    string y = x;
    reverse(y.begin(),y.end());

    int n = x.size();
    

    int dp[n+1][n+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else    
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }

    cout << x.size() -  dp[n][n] << endl;
    
    
    return 0;
}