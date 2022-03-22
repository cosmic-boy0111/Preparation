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


node* LCA(node* root,int n1,int n2){

    if(root == NULL)
        return NULL;

    if(root->val == n1 || root->val == n2){
        return root;
    }

    node* left = LCA(root->left,n1,n2);
    node* right = LCA(root->right,n1,n2);

    if(left != NULL and right != NULL){
        return root;
    }
    if(left == NULL and right == NULL){
        return NULL;
    }

    if(left != NULL)
        return LCA(root->left,n1,n2);
    
    return LCA(root->right,n1,n2);


}

int findDist(node* root,int k,int dist){
    if(root == NULL)
        return -1;

    if(root->val == k)
        return dist;

    int left = findDist(root->left, k, dist+1);


    if(left != -1)
        return left;
    
    return findDist(root->right, k, dist+1);

}

int dist(node* root,int n1,int n2){
    node* lca = LCA(root,n1,n2);

    int d1 = findDist(lca,n1,0);
    int d2 = findDist(lca,n2,0);

    return d1+d2;
}


int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << dist(root,4,5);
    
    return 0;
}