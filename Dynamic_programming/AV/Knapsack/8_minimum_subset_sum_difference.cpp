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


bool isSubset(int arr[],int n,int sum,vector<vector<int>>& dp){
    if(sum ==0 )
        return true;

    if(n==0)
        return false;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    if(arr[n-1] <= sum)
        return dp[n][sum] = isSubset(arr,n-1,sum-arr[n-1],dp) || isSubset(arr,n-1,sum,dp);

    return dp[n][sum] = isSubset(arr,n-1,sum,dp);
    
}


int32_t main(){


    int n;
    cin >> n;
    int arr[n];
    int sum = 0;

    

    for(int i=0;i<n;i++){
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

    vector<int> ansArray;
    for(int i=0;i<=sum;i++){
        if(isSubset(arr,n,i,dp)){
            ansArray.push_back(i);
        }
    }

    int ans = INT_MAX;
    for(auto & x : ansArray)
        cout << x << " ";
    cout << endl;
    for(int i=0;i<ansArray.size()/2;i++){
        ans = min(ans,sum-2*ansArray[i]);
    }

    cout << ans << endl;
        
    
    return 0;
}