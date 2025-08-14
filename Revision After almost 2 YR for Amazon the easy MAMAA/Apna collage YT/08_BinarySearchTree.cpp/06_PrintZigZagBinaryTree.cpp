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

void printQue(queue<node*>& q){
    if(q.front() == nullptr) {
        q.pop();
        return;
    }
    node* top = q.front();
    q.pop();
    if(top->left) q.push(top->left);
    if(top->right) q.push(top->right);
    cout << top->val << " ";
    printQue(q);
}

void printQueRev(queue<node*>& q){
    if(q.front() == nullptr) {
        q.pop();
        return;
    }
    node* top = q.front();
    q.pop();
    if(top->left) q.push(top->left);
    if(top->right) q.push(top->right);
    printQueRev(q);
    cout << top->val << " ";
}

void printZigZag(node* root){
    if(root == nullptr) return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    int isFlip = false;
    while(!q.empty()){
        !isFlip ? printQue(q) : printQueRev(q);
        cout << endl;
        if(!q.empty()) q.push(nullptr);
        isFlip = !isFlip;
    }
}

node* buildTree(const vector<int>& arr) {
    if (arr.empty() || arr[0] == -1000)
        return nullptr;

    node* root = new node(arr[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (i < arr.size()) {
        node* current = q.front();
        q.pop();

        // Left child
        if (i < arr.size() && arr[i] != -1000) {
            current->left = new node(arr[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1000) {
            current->right = new node(arr[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int32_t main(){

    vector<int> arr = {0, 2, 4, 1, -1000, 3, -1, 5, 1, -1000, 6, -1000, 8};

    node* root = buildTree(arr);

    printZigZag(root);
}

/*
               0
           /     \
         2         4
       /   \     /   \
      1   null  3    -1
     / \        \      \
    5   1       6        8

*/