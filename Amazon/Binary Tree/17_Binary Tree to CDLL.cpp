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

TreeNode *bTreeToCList(TreeNode *root){
    if(root == NULL) return NULL;
    if(root->left == NULL and root->right == NULL){
        root->right = root;
        root->left = root;
        return root;
    }

    TreeNode* left = bTreeToCList(root->left);
    TreeNode* right = bTreeToCList(root->right);

    if(left == NULL) {
        TreeNode* tail = right->left;
        right->left->right = NULL;
        right->left = NULL;
        root->right = right;
        right->left = root;
        tail->right = root;
        root->left = tail;
        return root;
    };
    if(right == NULL){
        TreeNode* tail = left->left;
        left->left->right = NULL;
        left->left = NULL;
        tail->right = root;
        root->left = tail;
        root->right = left;
        left->left = root;
        return left;
    };


    TreeNode* tail = left->left;
    left->left->right = NULL;
    left->left = NULL;
    tail->right = root;
    root->left = tail;
    root->right = left;
    left->left = root;


    TreeNode* tail2 = right->left;
    right->left->right = NULL;
    right->left = NULL;

    root->right = right;
    right->left = root;

    tail2->right = left;
    left->left = tail2;

    return left;

}
int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    TreeNode* ans = bTreeToCList(root);
    TreeNode* temp = ans;
    do
    {
        cout << temp->val << " ";
        temp = temp->right;
    } while (temp != ans);
    
    
    
    
    return 0;
}