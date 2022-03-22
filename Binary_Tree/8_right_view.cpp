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


vector<int> ans;
vector<int> ans2;
void rightView(node* root){
    
    if(root == NULL)
        return;

    queue<node* > q;
    q.push(root);
    q.push(NULL);
    ans2.push_back(root->val);
    while (!q.empty()){
        // int n = q.size();
        // for(int i=0;i<n;i++){
        //     node* curr = q.front();
        //     q.pop();
        //     if(i == n-1){
        //         ans.push_back(curr->val);
        //     }
        //     if(curr->left)
        //         q.push(curr->left);
        //     if(curr->right)
        //         q.push(curr->right);
        // }
        node* n = q.front();
        q.pop();
        if(n!=NULL){
            if(q.front() == NULL){
                ans.push_back(n->val);
            }
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }else if(!q.empty()){
            ans2.push_back(q.front()->val);
            q.push(NULL);
        }
    }
    
}


int main(){
    
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    rightView(root);

    // right view 
    for(auto &x:ans){
        cout << x << " ";
    }cout << endl;

    // left view
    for(auto &x:ans2){
        cout << x << " ";
    }

    
    return 0;
}