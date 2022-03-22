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

node* searchInBst(node* root,int key){

    if(root == NULL)
        return NULL;

    if(root->val == key){
        return root;
    }

    if(root->val > key){
        return searchInBst(root->left, key);
    }

    return searchInBst(root->right,key);
}

node* inorderSucc(node* root){
    node* curr = root;
    while (curr && curr->left != NULL){
        curr = curr->left;
    }

    return curr;
    
}

node* deleteInBST(node* root,int key){

    if(key < root->val){
        root->left = deleteInBST(root->left,key);
    }else if(key > root->val){
        root->right = deleteInBST(root->right,key);
    }else{
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = inorderSucc(root->right);
        root->val = temp->val;
        root->right = deleteInBST(root->right,temp->val);
    }

    return root;

    

}


void inorder(node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}


int main(){
    
    node* root = new node(4);
    root->left = new node(2);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right = new node(5);
    root->right->right = new node(6);

    node* temp = searchInBst(root,5);

    cout << temp->val << endl;
    inorder(root);
    cout << endl;
    root = deleteInBST(root,2);
    
    inorder(root);



    
    return 0;
}