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

void zigzagTraversal(node* root){

    if(root == NULL)
        return;

    stack<node* > currLevel;
    stack<node* > nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty()){
        node* temp = currLevel.top();
        currLevel.pop();
        if(temp){
            cout << temp->val << " ";
        
            if(leftToRight){
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }else{
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }

        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel,nextLevel);
        }
    }
    

}

int main(){
    
    node* root = new node(12);
    root->left = new  node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);

    zigzagTraversal(root);
    
    return 0;
}