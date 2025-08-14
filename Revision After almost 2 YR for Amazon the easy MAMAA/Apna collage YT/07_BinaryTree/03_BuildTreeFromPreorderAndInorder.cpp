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
// 1 2 3 4 5
// 0 1 2 3 4
node* buildTree(vector<int>& pre, vector<int>& ino, int &idx, int start, int end){
    if(start > end) return nullptr;
    node* root = new node(pre[idx]);
    int pos = 0;
    for(int i = start; i <= end; i++){
        if(ino[i] == pre[idx]){
            pos = i;
            break;
        }
    }
    idx++;
    root->left = buildTree(pre, ino, idx, start, pos - 1);
    root->right = buildTree(pre, ino, idx, pos + 1, end);

    return root;
}

void preOrder(node* root){
    if(root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> pre(n);
    vector<int> ino(n);
    for(auto& x : pre) cin >> x;
    for(auto& x : ino) cin >> x;
    int idx = 0;
    node* root = buildTree(pre, ino, idx, 0, n - 1);
    preOrder(root);

}