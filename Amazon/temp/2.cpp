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

unordered_map<TreeNode*,TreeNode*> parent;
TreeNode* temp(TreeNode* root,int home){
    if(root == NULL) return NULL;
    if(root->val == home) return root;
    if(root->left) parent[root->left] = root;
    if(root->right) parent[root->right] = root;
    TreeNode* left = temp(root->left,home);
    TreeNode* right = temp(root->right,home);
    if(left) return left;
    return right;
}

int ans = 0;
unordered_map<TreeNode*,bool> vis;
void dfs(TreeNode* root,int k){
    if(k < 0) return;
    if(root == NULL) return;
    vis[root] = true;
    ans += root->val;
    if( parent[root] != NULL and !vis[parent[root]]) dfs(parent[root],k-1);
    if(root->left != NULL and !vis[root->left]) dfs(root->left,k-1);
    if(root->right != NULL and !vis[root->right]) dfs(root->right,k-1);

}

int ladoos(TreeNode* root, int home, int k){
    parent[root] = NULL;
    TreeNode* home_Node = temp(root,home);
    dfs(home_Node,k);

    return ans;
}

int32_t main(){
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(9);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << endl << ladoos(root,9,1);



    return 0;
}