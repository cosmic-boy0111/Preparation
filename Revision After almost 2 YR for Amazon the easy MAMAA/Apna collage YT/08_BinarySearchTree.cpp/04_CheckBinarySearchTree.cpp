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

void preOrder(node* root){
    if(root == nullptr) return;
    cout << root->val << endl;
    preOrder(root->left);
    preOrder(root->right);
}

/*
          2 (,)
      1(,2)   3(2,)
*/

bool checkBST(node* root, int min, int max){

    if(root == nullptr) return true;
    
    if(!checkBST(root->left, min, root->val) || !checkBST(root->right, root->val, max)){
        return false;
    }

    return root->val > min && root->val < max;
}

int32_t main(){

    int n;
    cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    
    node* root = buildBST(v);
    preOrder(root);
    if(checkBST(root, INT_MIN, INT_MAX)){
        cout << "BST" << endl;
    }else{
        cout << "not BST" << endl;
    }

}