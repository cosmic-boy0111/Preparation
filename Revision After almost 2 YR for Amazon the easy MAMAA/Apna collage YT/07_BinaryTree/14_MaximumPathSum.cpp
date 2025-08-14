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
        node* next;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            left = NULL;
            right = NULL;
        }
};

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];
int maxSum = INT_MIN;
int maxPathSum(node* root){
    if(root == nullptr) return 0;
    int nodeVal = root->val;
    int leftMax = maxPathSum(root->left);
    int rightMax = maxPathSum(root->right);
    int totalVal = nodeVal + leftMax + rightMax;
    int pathMax = max(nodeVal, max(totalVal, max(leftMax + root->val, rightMax + root->val)));
    maxSum = max(maxSum, pathMax);
    return root->val + max(leftMax, rightMax);
}

int32_t main(){

    // node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    
    node* root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    maxPathSum(root);
    cout << maxSum << endl;
}