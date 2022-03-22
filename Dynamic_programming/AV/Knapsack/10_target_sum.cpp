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

int countSum(vector<int> arr,int n,int sum, int cal){

    if(n==0){
        if(cal == sum) return 1;
        return 0;
    }

    if(dp[n][cal]) return dp[n][cal];

    return  dp[n][cal] = countSum(arr,n-1,sum,cal+arr[n-1]) + countSum(arr,n-1,sum,cal-arr[n-1]);
}

// same as count of subset as given difference

int32_t main(){
   
    int n, sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(auto &i:arr)
        cin >> i;
    int cal = 0;
    cout << countSum(arr,n,sum,cal) << endl;
    
    
    return 0;
}