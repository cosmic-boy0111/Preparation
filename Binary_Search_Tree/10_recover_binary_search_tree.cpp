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

void calcPointers(node* root,node* &first,node* &mid,node* &last,node* &prev){
    if(root == NULL)
        return;
    
    calcPointers(root->left,first,mid,last,prev);
    if(prev && root->val < prev->val){
        if(!first){
            first = prev;
            mid = root;
        }else{
            last = root;
        }
    }

    prev = root;
    calcPointers(root->right,first,mid,last,prev);

}

void restoreBST(node* root){
    node* first=NULL, *mid=NULL, *last=NULL, *prev=NULL;

    calcPointers(root, first, mid, last, prev);
    
    if(first && last){
        swap(first->val,last->val);
    }else if(first && mid){
        swap(first->val,mid->val);
    }

}

void inorder(node* root){
    if(root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main(){
    
    node* root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);
    
    inorder(root);
    cout << endl;
    restoreBST(root);
    inorder(root);
    
    return 0;
}