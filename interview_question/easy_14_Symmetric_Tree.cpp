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

vector<vector<int>> temp;

void dfs(node* root,int lvl = 0){

    if(lvl == temp.size()) temp.push_back({});
	if(!root) {
        temp[lvl].push_back(INT_MIN);
        return;
    }
    
    temp[lvl].push_back(root->val);

    dfs(root->left,lvl+1);
    dfs(root->right,lvl+1);

}
        
bool isSymmetric(node* root) {

    dfs(root);

    for(auto x:temp){
        if(x != vector<int>(x.rbegin(),x.rend())) return false;
    }

    return true;
}

int main(){

    node* root = new node(1);
    root->left = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right = new node(2);
    root->right->left = new node(5);
    root->right->right = new node(3);

    bool check = isSymmetric(root);

    cout << check << endl;
    
    return 0;
}