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



// case 1
void printSubtreesNodes(node* root,int k){
    if(root == NULL || k<0)
        return;
    if(k == 0){
        cout << root->val << " ";
        return;
    }

    printSubtreesNodes(root->left,k-1);
    printSubtreesNodes(root->right,k-1);
}

// case 2
int printNodesAtK(node* root,node* target,int k){
    if(root == NULL)
        return -1;

    if(root == target){
        printSubtreesNodes(root,k);
        return 0;
    }

    int dl = printNodesAtK(root->left,target,k);
    if(dl != -1){
        if(dl + 1 == k){
            cout << root->val << " ";
        }else{
            printSubtreesNodes(root->right,k-dl-2);
        }

        return 1+dl;
    }

    int dr = printNodesAtK(root->right,target,k);
    if(dr != -1){
        if(dr + 1 == k){
            cout << root->val << " ";
        }else{
            printSubtreesNodes(root->left,k-dr-2);
        }

        return 1+dr;
    }

    return -1;
}

int main(){
    
     
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    printNodesAtK(root, root->left, 1);


    
    return 0;
}