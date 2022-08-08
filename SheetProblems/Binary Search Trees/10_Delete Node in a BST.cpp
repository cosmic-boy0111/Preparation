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

void solve(vector<int> &v, TreeNode* root){
    if(root == NULL) return ;
    solve(v,root->left);
    v.push_back(root->val);
    solve(v,root->right);
}

TreeNode* generate(vector<int> v, int l,int h){
    if(l > h) return NULL;
    int mid = l + (h - l)/2;
    TreeNode* root = new TreeNode(v[mid]);
    root->left = generate(v,l,mid-1);
    root->right = generate(v,mid+1,h);
    return root;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    vector<int> v;
    solve(v,root);
    bool notFound = true;
    vector<int> ref;
    for(int i=0;i<v.size();i++){
        if(v[i] == key){
            notFound = false;
            continue;
        }
        ref.push_back(v[i]);
    }

    if(notFound) return root;
    root = generate(v,0,v.size()-1);
    return root;

}

int32_t main(){
    

    
    
    
    return 0;
}