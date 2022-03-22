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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    int isBST;
};


Info largetsBST(node* root){

    if(root == NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }

    if(root->left == NULL and root->right == NULL) {
        return {1,root->val,root->val,1,true};
    }

    Info leftInfo = largetsBST(root->left);
    Info rightInfo = largetsBST(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);
    if(leftInfo.isBST and rightInfo.isBST and leftInfo.max < root->val and rightInfo.min > root->val){
        curr.min = min(leftInfo.min,min(rightInfo.min,root->val));
        curr.max = max(leftInfo.min,max(rightInfo.max,root->val));
        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans,rightInfo.ans);
    curr.isBST = false;

    return curr;

}   



int main(){
    

    node* root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    Info t = largetsBST(root);
    cout << t.ans << endl;

    return 0;
}