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

const int dp_size = 1e3+10;
int dp[dp_size][dp_size];

int minimumCoins(vector<int> coins,int n,int sum){
    if(sum == 0) return 0;
    if(n ==0 ) return INT_MAX-1;

    if(dp[n][sum]) return dp[n][sum];
    
    if(coins[n-1] <= sum){
        return  dp[n][sum] =  min( 1 +  minimumCoins(coins,n,sum-coins[n-1]) , minimumCoins(coins,n-1,sum) );
    }

    return  dp[n][sum]  = minimumCoins(coins,n-1,sum);
}

int32_t main(){
    
    int n, sum;
    cin >> n >>  sum;
    vector<int> coins(n);
    for(auto &i:coins){
        cin >> i;
    }   

    cout << minimumCoins(coins,n,sum) << endl;

    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i ==0 ) dp[i][j] = INT_MAX-1;
            else if(j==0) dp[i][j] = 0;
            
        }
    }

    for(int i=1;i<=sum;i++){
        if(i%coins[0] == 0){
            dp[1][i] = i/coins[0];
        }else{
            dp[1][i] = INT_MAX-1;
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1] <= j){
                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << dp[n][sum] << endl;
    
    return 0;
}