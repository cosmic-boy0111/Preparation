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

node* flatten(node* &root){
    if(root == nullptr){
        return nullptr;
    }

    node* leftFlat = flatten(root->left);
    node* rightFlat = flatten(root->right);
    root->left = nullptr;
    root->right = leftFlat;

    node* temp = root;
    while (temp->right != nullptr){
        temp = temp->right;
    }
    temp->right = rightFlat;

    return root;
}

void preOrder(node* root){
    if(root == nullptr) return;
    cout << root->val << " ";
    // preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if(root == nullptr) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int32_t main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    inOrder(root);
    cout << endl;
    node* flatRoot = flatten(root);
    preOrder(flatRoot);
    cout << endl;
    
}

/*
                 1
              2    3
            4  5  6 7   
*/