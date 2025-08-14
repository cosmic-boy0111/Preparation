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
struct nodeData {
    int min;
    int max;
    bool isBST;
    int sizeOfLBST;
    int subTreeSize;
    
    nodeData() {
        min = INT_MIN;
        max = INT_MAX;
        isBST = true;
        sizeOfLBST = 0;
        subTreeSize = 0;
    }
};

nodeData findLargestBST(node* root){
    if(root == nullptr){
        return nodeData();
    }

    nodeData left = findLargestBST(root->left);
    nodeData right = findLargestBST(root->right);

    nodeData rootData;
    rootData.isBST = left.isBST && right.isBST && root->val > (left.max == INT_MAX ? INT_MIN : left.max) && root->val < (right.min == INT_MIN ? INT_MAX: right.min);
    rootData.subTreeSize = 1 + left.subTreeSize + right.subTreeSize;
    rootData.sizeOfLBST = rootData.isBST ? rootData.subTreeSize : max(left.sizeOfLBST, right.sizeOfLBST);
    rootData.min = min(root->val, min(
        (left.min == INT_MIN ? INT_MAX : left.min) , 
        (right.min == INT_MIN ? INT_MAX: right.min )
    ));
    rootData.max = max(root->val, max(
        (left.max == INT_MAX ? INT_MIN : left.max) , 
        (right.max == INT_MAX ? INT_MIN : right.max )
    ));

    return rootData;
}

int32_t main(){

    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(6);
    root->left->left = new node(2);
    root->left->right = new node(4);

    nodeData ans = findLargestBST(root);
    cout << ans.sizeOfLBST << endl;

}