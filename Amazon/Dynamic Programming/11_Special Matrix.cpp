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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};

int dp[510][510];
int solve(int i,int j,int n,int m,vector<vector<int>>& path){

    if( i > n || j > m) return 0;
    if(path[i][j] == 0) return 0;
    if(i == n and  j == m) return 1;

    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = solve(i+1,j,n,m,path) + solve(i,j+1,n,m,path);


}

int FindWays(int n, int m, vector<vector<int>>blocked_cells){
    vector<vector<int>> path(n,vector<int>(m,1));
    for(auto &x : blocked_cells){
        path[x[0]-1][x[1]-1] = 0;
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(0,0,n-1,m-1,path);

    return ans;

}

int32_t main(){
    
    int n , m , k;
    cin >> n >> m >> k;
    vector<vector<int>> b(k,vector<int>(2));
    for(auto &x : b){
        cin >> x[0] >> x[1];
    }
    
    cout << FindWays(n,m,b);


    return 0;
}