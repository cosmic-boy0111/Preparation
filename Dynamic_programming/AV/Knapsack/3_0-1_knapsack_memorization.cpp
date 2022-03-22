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

map<pair<int,int>,int> dp;

int knapSack( vector<int> wt, vector<int> val, int n,int w) {
    if(n == 0 or w == 0){
        return 0;
    }

    if(dp.find({n,w}) != dp.end()){
        return dp[{n,w}];
    }

    if(wt[n-1] <= w){
        int choose = val[n-1] + knapSack(wt,val,n-1,w-wt[n-1]);
        int notChoose = knapSack(wt,val,n-1,w);

        return dp[{n,w}] = max(choose,notChoose);
    }

    return dp[{n,w}] = knapSack(wt,val,n-1,w);

}

int32_t main(){
    
    int n , W;
    cin >> n >> W; 
    vector<int> wt;
    vector<int> val;

    for(int i=0;i<n;i++){
        int w,v;
        cin >> w >> v;
        wt.push_back(w);
        val.push_back(v);
    }

    cout << knapSack(wt,val,n,W);
    
    
    return 0;
}