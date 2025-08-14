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

int height(node* root){
    if(root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isHeightBalance(node* root){
    if(root == nullptr) return true;

    int lHeight = height(root->left);
    int rHeight = height(root->right);
    bool isBal = abs(lHeight - rHeight) <= 1;
    bool left = isHeightBalance(root->left);
    bool right = isHeightBalance(root->right);

    return isBal && left && right;
}

bool checkHeightBalance(node* root, int& height){

    if(root == nullptr){
        height = 0;
        return true;
    }

    int lh = 0, rh = 0;
    if(!checkHeightBalance(root->left, lh)) return false;
    if(!checkHeightBalance(root->right, rh)) return true;
    height = 1 + max(lh, rh);

    return abs(lh - rh) <= 1;
}

int32_t main(){

    node* root = new node(1);
    root->left = new node(2);
    // root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);

    int height = 0;
    cout << checkHeightBalance(root, height) << endl;
}

/*
                 1
              2    3
            4  5    
*/  