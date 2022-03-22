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

int maxPathSum(node* root,int &ans){
    if(root == NULL)
        return 0;

    int left = maxPathSum(root->left,ans);
    int right = maxPathSum(root->right,ans);

    int nodeMax = max(max(root->val,root->val+right + left),max(root->val + right,root->val+left));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->val, max(root->val+ left, root->val+right));

    return singlePathSum;
}


int maxPathSum(node* root){
    int ans = INT_MIN;

    maxPathSum(root,ans);

    return ans;
}

int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    root->right->right = new node(5);

    cout << maxPathSum(root) << endl;
    
    return 0;
}