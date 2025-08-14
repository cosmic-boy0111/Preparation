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

bool findThePath(node* root, node* target, vector<node*> &vec){
    if(root == nullptr) return false;
    vec.push_back(root);

    if(root == target){
        return true;
    }

    if(findThePath(root->left, target, vec) || findThePath(root->right, target, vec)){
        return true;
    }

    vec.pop_back();
    return false;
}

int LCA(node* root, node* target1, node* target2){
    if(root == nullptr) return -1;
    vector<node*> path1 , path2;
    if(!findThePath(root, target1, path1) || !findThePath(root, target2, path2)){
        return -1;
    }

    int i = 0;
    int common = -1;
    while ( i < min(path1.size(), path2.size())){
        if(path1[i]->val != path2[i]->val) break;
        common = path1[i]->val;
        i++;
    }
    
    return common;
}

node* LCA2(node* root, int n1, int n2){
    if(root == nullptr) return nullptr;
    if(root->val == n1 || root->val == n2) return root;
    node* leftLCA = LCA2(root->left, n1, n2);
    node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA && rightLCA) return root;
    if(leftLCA) return leftLCA;
    return rightLCA;
}

int32_t main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // vector<node*> vec;
    // cout << LCA(root, root->left->left, root->left->right);
    node* ans = LCA2(root, 4, 6);
    cout << ans->val << endl;

}
/*
                        1
                    2       3
                4     5    
*/