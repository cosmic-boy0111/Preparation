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

node* buildTree(vector<int>& pos, vector<int>& ino, int& idx, int start, int end){
    if(start > end) return nullptr;
    node* root = new node(pos[idx]);
    int pivote = 0;
    for(int i = start; i<=end; i++){
        if(ino[i] == pos[idx]){
            pivote = i;
            break;
        }
    }
    idx--;

    root->right = buildTree(pos, ino, idx, pivote + 1, end);
    root->left = buildTree(pos, ino, idx, start, pivote - 1);

    return root;
}

void preOrder(node* root){
    if(root == nullptr) return;
    preOrder(root->left);
    preOrder(root->right);
    cout << root->val << " ";
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> pos(n);
    vector<int> ino(n);
    for(auto& x : pos) cin >> x;
    for(auto& x : ino) cin >> x;
    int idx = n - 1;
    node* root = buildTree(pos, ino, idx, 0, n-1);
    preOrder(root);
}