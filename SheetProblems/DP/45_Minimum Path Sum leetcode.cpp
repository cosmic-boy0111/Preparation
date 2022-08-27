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


vector<pair<int,int>> dir = {{0,1},{1,0}};
int solve(int i,int j,vector<vector<int>>& mat,int N,int M,vector<vector<int>>& dp){

    if(i == N-1 and j == M-1) return mat[i][j];

    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(auto &pr : dir){
        int x = i + pr.first;
        int y = j + pr.second;
        if(x >= 0 and y >=0 and x < N and y < M)
            ans = min(ans, mat[i][j] + solve(x,y,mat,N,M,dp));
    }

    return dp[i][j] = ans;
}

int minPath(int N, int M, vector<vector<int>> Matrix){

    vector<vector<int>> dp(N+1,vector<int>(M+1,-1));

    return solve(0,0,Matrix,N,M,dp);
}


int minPathSum(vector<vector<int>>& grid) {
    return minPath(grid.size(),grid[0].size(),grid) ;
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}