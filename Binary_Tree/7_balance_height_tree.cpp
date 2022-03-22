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

int height(node* root){

    if(root == NULL)
        return 0;

    return max(height(root->left),height(root->right)) + 1;
}

bool isBalance(node* root){

    if(root == NULL){
        return true;
    }

    if(isBalance(root->left) == false){
        return false;
    }
    if(isBalance(root->right) == false){
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return abs(lh-rh) <= 1;
}

bool isBalanceOpt(node* root,int* height){
    
    if(root == NULL){
        return true;
    }
    int lh = 0 , rh = 0;
    if(isBalanceOpt(root->left, &lh) == false){
        return false;
    }
    if(isBalanceOpt(root->right, &rh) == false){
        return false;
    }

    *height = max(lh,rh) + 1;

    return abs(lh-rh) <= 1;
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << isBalance(root) << endl;
    int height = 0;
    cout << isBalanceOpt(root,&height) << endl;
    
    return 0;
}