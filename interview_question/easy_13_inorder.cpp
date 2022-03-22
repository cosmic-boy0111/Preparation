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
void printBinary(int n){for(int i=10;i>=0;i--){if((n>>i) & 1){cout << 1;}else{cout << 0;}}cout << endl;}


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

void inorder(node* root,vector<int>& ans){

    if(root == NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);

}

vector<int> inorderTraversal(node* root) {
    vector<int> ans;

    inorder(root,ans);

    return ans;
}

int main(){
    

    node* root = new node(1);
    root->right = new node(2);
    root->right->left = new node(3);

    vector<int> ans = inorderTraversal(root);

    for(auto &x:ans){
        cout << x << " ";
    }
    
    return 0;
}