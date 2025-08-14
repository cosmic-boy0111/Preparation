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

node* makeTree(vector<int>& v){
    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (i < v.size()){
        node* curr = q.front();
        q.pop();
        if(i < v.size() && v[i] != -1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i < v.size() && v[i] != -1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];

void findCeil(node* root, int key, int &ceil){
    if(root == nullptr) return;
    if(root->val == key) {
        ceil == root->val;
        return;
    };
    if(root->val > key){
        ceil = root->val;
        findCeil(root->left, key, ceil);
        return;
    }

    findCeil(root->right, key, ceil);
}

void findFloor(node* root, int key, int &ceil){
    if(root == nullptr) return;
    if(root->val == key) {
        ceil == root->val;
        return;
    };
    if(root->val > key){
        findFloor(root->left, key, ceil);
        return;
    }
    
    ceil = root->val;
    findFloor(root->right, key, ceil);
}
/*
            10
        5       13
    3       611     14
 */

int findCeil2(node* root, int key){
    int ceil = -1;
    while(root){
        if(root->val == key){
            ceil = root->val;
            return ceil;
        }

        if(key > root->val){
            root = root->right;
        }else{
            ceil = root->val;
            root = root->left;
        }
    }

    return ceil;
}

int32_t main(){

    int n, key;
    cin >> n >> key;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    node* root = makeTree(v);
    
    int ans = -1;
    findFloor(root, key, ans);
    cout << ans << endl;

    cout << findCeil2(root, key) << endl;

}