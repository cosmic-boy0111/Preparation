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


int leftHeight(node* root){
    if(!root) return -1;
    return 1+leftHeight(root->left);
}

int rightHeight(node* root){
    if(!root) return -1;
    return 1+rightHeight(root->right);
}

int countNodes(node* root){
    if(!root) return 0;
    int l = leftHeight(root);
    int r = rightHeight(root);

    return l==r?(1<<l+1)-1:1+countNodes(root->left)+countNodes(root->right);
}


int main(){
    

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);

    int ans = countNodes(root);

    cout << ans << endl;
    
    
    return 0;
}