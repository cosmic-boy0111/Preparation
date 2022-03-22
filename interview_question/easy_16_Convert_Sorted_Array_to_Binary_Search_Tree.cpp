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

        node(int data,node* leftNode,node* rightNode){
            val = data;
            left = leftNode;
            right = rightNode;
        }
};


void preorder(node* root) {
    if(root == NULL) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

node* build(vector<int> nums,int l,int r){
    if(l > r){
        return NULL;
    }
    int m = l + (r-l)/2;
    return  new node(nums[m],build(nums,l,m-1),build(nums,m+1,r));
}


node* sortedArrayToBST(vector<int>& nums) {
    return build(nums,0,nums.size()-1);
}

int main(){
    
    vector<int> nums = {-10,-3,0,5,9};

    node* root = sortedArrayToBST(nums);

    preorder(root);


    
    return 0;
}