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


void printLevelOrder(node* root){
    if(root == NULL)
        return;

    queue<node* > q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* n = q.front();
        q.pop();
        if(n != NULL){
            cout << n->val << " ";
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }else if(!q.empty())
            q.push(NULL);
    }
    
}

int sumAtK(node* root,int k){
    if(root == NULL)
        return -1;

    queue<node* > q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty()){
        node* n = q.front();
        q.pop();
        if(n != NULL){
            if(level == k){
                sum += n->val;
            }
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }

    return sum;
    
}


int main(){
    

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // printLevelOrder(root);

    cout << sumAtK(root,2);


    
    return 0;
}