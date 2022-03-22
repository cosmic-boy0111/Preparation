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

node* sortedArrayToBST(int arr[],int start,int end){

    if(start > end)
        return NULL;


    int mid = start + (end - start)/2;
    node* root = new node(arr[mid]);

    root->left = sortedArrayToBST(arr,start,mid-1);
    root->right = sortedArrayToBST(arr,mid+1,end);

    return root;

}

void preorder(node* root){
    if(root == NULL)
        return ;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){

    int arr[] = {10,20,30,40,50};
    node* root= sortedArrayToBST(arr,0,4);
    preorder(root);
    
    return 0;
}