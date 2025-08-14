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

void inorderVec(node* root, vector<node*>& v){
    if(!root) return;
    inorderVec(root->left, v);
    v.push_back(root);
    inorderVec(root->right, v);
}

void recover(node* root){
    vector<node*> v;
    inorderVec(root, v);
    node* first = nullptr;
    node* second = nullptr;
    int i = 0;
    for(; i < v.size() - 1; i++){
        if(v[i]->val > v[i+1]->val){
            first = v[i];
        }
        if(first) break;
    }
    for(int j = v.size() - 1; j > i; j--){
        if(v[j]->val < v[j-1]->val){
            second = v[j];
        }
        if(second) break;
    }
    swap(first->val, second->val);
}

void inorder(node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int32_t main(){

    node* root = new node(5);
    root->left = new node(4);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(3);

    inorder(root);
    cout << endl;
    recover(root);
    inorder(root);

}