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

const int T = 1e3;
int dp[T][T];

bool isPossible(vector<int> &arr,int n,int sum){

    if(sum == 0){
        return true;
    }

    if(n==0){
        return false;
    }


    if(dp[n][sum] != -1) return dp[n][sum];


    if(arr[n-1] <= sum){
        return   dp[n][sum] =   isPossible(arr,n-1,sum-arr[n-1]) || isPossible(arr,n-1,sum);
    }

    

    return  dp[n][sum] =  isPossible(arr,n-1,sum);

}

int32_t main(){
    
    for(int i=0;i<T;i++){
        for(int j=0;j<T;j++){
            dp[i][j] = -1;
        }
    }

    int n , sum;
    cin >> n >> sum;

    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    // cout << isPossible(arr,n,sum);

    bool t[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j==0){
                t[i][j] = true;
            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    cout << t[n][sum] << endl;
    
    
    return 0;
}