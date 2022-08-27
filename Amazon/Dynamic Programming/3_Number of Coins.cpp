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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new ListNode(val); 
}

void display(ListNode* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


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

    if(dp[n][sum]!= -1) return dp[n][sum];
    
    if(coins[n-1] <= sum){
        return  dp[n][sum] =  min( 1 +  minimumCoins(coins,n,sum-coins[n-1]) , minimumCoins(coins,n-1,sum) );
    }

    return  dp[n][sum]  = minimumCoins(coins,n-1,sum);
}


int minCoins(int coins[], int M, int V){
    vector<int> v;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++) v.push_back(coins[i]);
    int ans = minimumCoins(v,N,V);
    return ans == INT_MAX-1 ? -1 : ans;
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}