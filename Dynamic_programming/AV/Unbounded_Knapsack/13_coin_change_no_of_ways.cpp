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

const int t = 1e3+10;
int dp[t][t];

int countWays(vector<int> coins, int n, int sum){

    if(sum == 0) return 1;

    if(n==0) return 0;

    if(dp[n][sum]) return dp[n][sum];

    if(coins[n-1] <= sum){
        return  dp[n][sum] =  countWays(coins,n,sum-coins[n-1]) + countWays(coins,n-1,sum);
    }

    return  dp[n][sum] =  countWays(coins,n-1,sum);

}

int32_t main(){
    
    int n , sum;
    cin >> n >> sum;
    vector<int> coins(n);

    for(auto &i:coins)
        cin >> i;

    // cout << countWays(coins,n,sum) << endl;
    int dp[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1] <= j){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    cout << dp[n][sum] << endl;



    
    return 0;
}