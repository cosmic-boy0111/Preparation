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

/*
            0
        -1      2
    -3      nn      4
    
*/

class BSTIterator {
public:
    stack<node*> stNext;
    stack<node*> stBefore;
    BSTIterator(node* root) {
        node* temp = root;
        while(temp){
            stNext.push(temp);
            temp = temp->left;
        }
        temp = root;
        while(temp){
            stBefore.push(temp);
            temp = temp->right;
        }
    }
    
    node* next() {
        if(!hasNext()) return nullptr;
        node* top = stNext.top();
        stNext.pop();
        node* temp = top->right;
        while ( temp ){
            stNext.push(temp);
            temp = temp->left;
        }
        return top;
    }
    
    bool hasNext() {
        return !stNext.empty();
    }

    node* before() {
        if(!hasBefore()) return nullptr;
        node* top = stBefore.top();
        stBefore.pop();
        node* temp = top->left;
        while ( temp ){
            stBefore.push(temp);
            temp = temp->right;
        }
        return top;
    }
    
    bool hasBefore() {
        return !stBefore.empty();
    }

    vector<node*, node*> twoSum(int key){
        node* left = next();
        node* right = before();
        while (left && right){
            if(left == right) break;
            if(left->val + right->val == key){
                return {left, right};
            }
            if(left->val + right->val > key){
                right = before();
            }else{
                left = next();
            }
        }
        return {nullptr, nullptr};
    }

};

int32_t main(){

    

}