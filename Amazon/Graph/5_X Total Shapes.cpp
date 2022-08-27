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
    {0,-1},{-1,0},{0,1},{1,0}
};

void dfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& vis){
    int n = grid.size();
    int m = grid[0].size();

    if(i < 0 or j < 0 or i >= n or j >= m or vis[i][j] == 1 or grid[i][j] == 'O') return;

    vis[i][j] = 1;

    for(auto &pr : pos){
        int x = i+pr.first;
        int y = j+pr.second;
        dfs(grid,x,y,vis);
    }

}

int xShape(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == 0 and grid[i][j] == 'X'){
                ans ++;
                dfs(grid,i,j,vis);
            }
        }
    }

    return ans;
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }
    
    
    
    return 0;
}