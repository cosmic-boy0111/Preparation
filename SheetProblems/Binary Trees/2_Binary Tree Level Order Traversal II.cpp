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
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int val = 0){
            data = val;
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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if(root == NULL) return {};
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        vector<int> temp;
        while ( q.front() != NULL ){
            TreeNode* t = q.front();
            q.pop();
            temp.push_back(t->data);
            if(t->left != NULL) q.push(t->left);
            if(t->right != NULL) q.push(t->right);
        }
        q.pop();
        if(!q.empty())
            q.push(NULL);
        ans.push_back(temp);
    }

    reverse(ans.begin(),ans.end());
    return ans;
    
}


int32_t main(){
    
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    for(auto &x : levelOrderBottom(root)){
        for(auto & y : x)
            cout << y << " ";
        cout << endl;
    }
    
    
    return 0;
}