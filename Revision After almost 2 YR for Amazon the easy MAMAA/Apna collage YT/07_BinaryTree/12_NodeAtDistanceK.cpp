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

// case 1 
void printTheNodeAtKDistance(node* root, int k){
    if(root == nullptr || k < 0){
        return;
    }
    if(k == 0){
        cout << root->val << endl;
        return;
    }
    printTheNodeAtKDistance(root->left, k-1);
    printTheNodeAtKDistance(root->right, k-1);
}

// case 2;
int printAtKNodes(node* root, node* target, int k){
    if(root == nullptr){
        return -1;
    }
    if(root == target){
        printTheNodeAtKDistance(root, k);
        return 1;
    }
    int dl = printAtKNodes(root->left, target, k);
    if(dl != -1){
        if(dl == k){
            cout << root->val << endl;
        }else{
            printTheNodeAtKDistance(root->right, k - dl - 1);
        }
        return dl + 1;
    }
    int dr = printAtKNodes(root->right, target, k);
    if(dr != -1){
        if(dr == k){
            cout << root->val << endl;
        }else{
            printTheNodeAtKDistance(root->left, k - dr - 1);
        }
        return dr + 1;
    }

    return -1;
}

int printAtNodesMy(node* root, node* target, int k){
    if(root == nullptr){
        return -1;
    }
    if(root == target){
        printTheNodeAtKDistance(root, k);
        return 1;
    }

    int fl = printAtNodesMy(root->left, target, k);
    if(fl != -1){
        if(fl == k){
            cout << root->val << endl;
        }else{
            printTheNodeAtKDistance(root->right, k - fl - 1);
        }
        return fl + 1;
    }
    int fr = printAtNodesMy(root->right, target, k);
    if(fr != -1){
        if(fr == k){
            cout << root->val << endl;
        }else{
            printTheNodeAtKDistance(root->left, k - fr - 1);
        }
        return fr + 1;
    }

    return -1;
}

int32_t main(){

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    printAtKNodes(root, root->left->left, 2);

}