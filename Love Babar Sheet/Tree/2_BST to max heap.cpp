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

struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
};

TreeNode* newTreeNode(int data){
    TreeNode* n = new TreeNode();
    n->val = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

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

void Travel(TreeNode* root,vector<int>& v){
    if(root == NULL) return;
    Travel(root->left,v);
    v.push_back(root->val);
    Travel(root->right,v);
}

TreeNode* solve(vector<int>& v,int start, int end){
    if(start == end) {
        return newTreeNode(v[start]);
    }
    int mid = (end + start) / 2;
    TreeNode* root = newTreeNode(v[end]);
    root->left = solve(v,start,mid-1);
    root->right = solve(v,mid,end-1);
    return root;
}

void convertToMaxHeapUtil(TreeNode* &root){
    vector<int> v;
    Travel(root,v);
    root = solve(v,0,v.size()-1);
}  


void postOrder(TreeNode* root){
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int32_t main(){
    
    TreeNode* root = newTreeNode(4);
    root->left = newTreeNode(2);
    root->left->left = newTreeNode(1);
    root->left->right = newTreeNode(3);
    root->right = newTreeNode(6);
    root->right->left = newTreeNode(5);
    root->right->right = newTreeNode(7);

    // postOrder(root);
    convertToMaxHeapUtil(root);
    postOrder(root);



    return 0;
}