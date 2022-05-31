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


int superEggDropHelper(int k, int n, vector<vector<int>> &dp)  {
    if(k == 1) return n;
    if(n == 0 || n == 1) return n;



    if(dp[n][k] != -1) return dp[n][k];

    int l = 1, r = n, ans = INT_MAX;

    while (l <= r){
        int mid = (l+r)/2;
        int left = dp[mid-1][k-1] == -1 ?  superEggDropHelper(k-1, mid-1, dp) : dp[mid-1][k-1];
        int right = dp[n-mid][k] == -1 ? superEggDropHelper(k,n-mid,dp) : dp[n-mid][k];

        int temp = 1 + max(left,right);

        if(left < right)
            l = mid+1;
        else
            r = mid - 1 ;

        ans = min(ans,temp);


    }

    dp[n][k] = ans;
    return ans;
    

}

int superEggDrop(int k,int n){
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return superEggDropHelper(k,n,dp);
}

int32_t main(){
    
    int e ,f;
    cin >> e >> f;

    cout << superEggDrop(e,f) << endl;
    
    
    return 0;
}