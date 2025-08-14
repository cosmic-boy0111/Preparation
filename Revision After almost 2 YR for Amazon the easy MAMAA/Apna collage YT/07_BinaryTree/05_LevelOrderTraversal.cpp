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

void printLevelOrder(node* root){
    if(root == nullptr) return;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        node* top = q.front();
        q.pop();
        if(top == nullptr && q.empty()) continue;
        else if(top == nullptr){
            q.push(nullptr);
            continue;
        }
        cout << top->val << endl;
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
    }
}

int sumAtK(node* root, int k){
    if(root == nullptr) return -1;
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        if(k == 0){
            int sum = 0;
            while(q.front() != nullptr){
                sum += q.front()->val;
                q.pop();
            }
            return sum;
        }
        node* top = q.front();
        q.pop();
        if(top == nullptr && q.empty()) continue;
        else if(top == nullptr){
            k--;
            q.push(nullptr);
            continue;
        }
        if(top->left) q.push(top->left);
        if(top->right) q.push(top->right);
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

    // printLevelOrder(root);
    cout << sumAtK(root, 2);

}