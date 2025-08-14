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
        node* next;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

void addElementInBST(node* &root, int n){

    if(root == nullptr) return;

    if(root->val > n){
        if(root->left == nullptr){
            root->left = new node(n);
            return;
        }
        addElementInBST(root->left, n);
        return;
    }
    if(root->right == nullptr){
        root->right = new node(n);
        return;
    }
    addElementInBST(root->right, n);
}

node* buildBST(vector<int>& v){
    node* root = new node(v[0]);
    for(int i = 1; i < v.size(); i++){
        addElementInBST(root, v[i]);
    }
    return root;
}

void inOrder(node* root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->val << endl;
    inOrder(root->right);
}

node* searchBST(node* root, int key){
    if(root == nullptr) return nullptr;
    if(root->val == key) return root;
    if(root->val > key) return searchBST(root->left, key);
    return searchBST(root->right, key);
}

node* getInOdrSucc(node* root){
    node* temp = root;
    while(temp && temp->left != nullptr) temp = temp->left;
    return temp;
}

node* deleteNodeInBST(node* root, int key){
    if(root == nullptr) return nullptr;
    if(root->val > key){
        root->left = deleteNodeInBST(root->left, key);
    }else if(root->val < key){
        root->right = deleteNodeInBST(root->right, key);
    }else{
        if(root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }else if(root->left == nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }
        node* temp = getInOdrSucc(root->right);
        root->val = temp->val;
        root->right = deleteNodeInBST(root->right, temp->val);
    }

    return root;
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    node* root = buildBST(v);
    inOrder(root);
    node* sNode = searchBST(root, 10);
    if(sNode) cout << "found" << endl;
    else cout << "not found" << endl;
    deleteNodeInBST(root, 3);
    inOrder(root);
}