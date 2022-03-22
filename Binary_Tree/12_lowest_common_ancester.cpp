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
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

bool getPath(node* root,int key,vector<int> &path){

    if(root == NULL)
        return false;

    path.push_back(root->val);
    if(root->val == key)
        return true;
    
    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(node* root,int n1,int n2){
    vector<int> path1,path2;

    if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
        return -1;
    }

    int pc;
    for(pc=0 ; pc < path1.size() && path2.size() ; pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc-1];
}

node* LCA2(node* root,int n1,int n2){

    if(root == NULL)
        return NULL;

    if(root->val == n1 || root->val == n2){
        return root;
    }

    node* left = LCA2(root->left,n1,n2);
    node* right = LCA2(root->right,n1,n2);

    if(left != NULL and right != NULL){
        return root;
    }

    if(left == NULL and right == NULL){
        return NULL;
    }

    if(left != NULL){
        return LCA2(root->left,n1,n2);
    }

    return LCA2(root->right,n1,n2);



}

int main(){
    

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    
    int n1 = 7;
    int n2 = 6;
    int lca = LCA(root,n1,n2);
    node* lca2 = LCA2(root,n1,n2);
    cout << lca2->val << endl;
    
    return 0;
}