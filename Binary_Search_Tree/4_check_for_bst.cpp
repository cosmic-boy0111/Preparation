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


bool isBST(node* root,node* min = NULL,node* max = NULL){

    if(root == NULL)
        return true;

    if(min != NULL and root->val <= min->val){
        return false;
    }
    if(max != NULL and root->val >= max->val){
        return false;
    }

    bool leftValid = isBST(root->left,min,root);
    bool rightValid = isBST(root->right,root,max);

    return leftValid && rightValid;

}


int main(){
    

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    /*
             1
            / \
           2   3

    */
    cout << isBST(root,NULL,NULL) << endl;

    return 0;
}