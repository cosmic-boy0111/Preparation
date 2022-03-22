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
 
const int T = 1e3+10;
int dp[T][T];


int calculate_max(string x,string y,int x_size,int y_size){
    if(x_size ==0 || y_size ==0)
        return 0;

    if(dp[x_size][y_size] != -1) return dp[x_size][y_size];

    if(x[x_size-1] == y[y_size-1])
        return dp[x_size][y_size] = 1+calculate_max(x,y,x_size-1,y_size-1);

    return dp[x_size][y_size] = max(calculate_max(x,y,x_size-1,y_size),calculate_max(x,y,x_size,y_size-1));
}


int32_t main(){
    
    inc(i,0,T){
        inc(j,0,T)
            dp[i][j] = -1;
    }

    string x;
    string y;

    cin >> x >> y;

    cout << calculate_max(x,y,x.size(),y.size());
    
    
    return 0;
}