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


int search(int inorder[],int start,int end,int curr){
    for(int i=start; i<=end ; i++){
        if(inorder[i] == curr){
            return i;
        }
    }

    return -1;
}


node* builtTree(int preorder[],int inorder[],int start,int end){
    static int idx = 0;

    if(start > end)
        return NULL;

    int curr = preorder[idx];
    idx++;
    node* n = new node(curr);
    if(start == end)
        return n;
    int pos = search(inorder,start,end,curr);

    n->left = builtTree(preorder,inorder,start,pos-1);
    n->right = builtTree(preorder,inorder,pos+1,end);

    return n;
}   

void inorderPrint(node* root){

    if(root == NULL)
        return;

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main(){
    
    int preorder[] = {1,2,4,3,5};
    int inorder[] = {4,2,1,5,3};


    node* root =  builtTree(preorder,inorder,0,4);
    inorderPrint(root);


    
    return 0;
}