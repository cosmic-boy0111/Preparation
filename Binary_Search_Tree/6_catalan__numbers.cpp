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

int cnt = 0;
unordered_map<int,int> mp;
int catalan(int n){
    cnt ++;
    if(mp.find(n) != mp.end())
        return mp[n];
    if(n <= 0)  
        return 1;

    int res = 0;
    for(int i=0;i<n;i++){
        res += catalan(i) * catalan(n-i-1);
    }

    mp[n] = res;

    return res;
}

// applications 
/*
    1. possible BSTa
    2. brackets combination
    3. possible forest
    4. ways to triangulation
    5. possible paths in matrix
    6. dividing a circle using N chords
    7. dyck words of given length
*/

vector<node* > constructTrees(int start,int end){

    vector<node* > trees;

    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        vector<node* > leftSubtrees = constructTrees(start,i-1);
        vector<node* > rightSubtrees = constructTrees(i+1,end);

        for(int j=0; j<leftSubtrees.size(); j++){
            node* left = leftSubtrees[j];
            for(int k = 0 ; k < rightSubtrees.size(); k++){
                node* right = rightSubtrees[k];
                node* n = new node(i);
                n->left = left;
                n->right = right;

                trees.push_back(n);
            }
        }

    }

    return trees;

}

void preorder(node* root){

    if(root == NULL)
        return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);

}

int main(){
    
    // for(int i=0;i<10;i++){
    //     cout << catalan(i) << " ";
    // }cout << endl;
    // cout << cnt << endl;

    vector<node*> trees = constructTrees(1,3);
    for(auto &x:trees){
        preorder(x);
        cout << endl;
    }
    
    return 0;
}