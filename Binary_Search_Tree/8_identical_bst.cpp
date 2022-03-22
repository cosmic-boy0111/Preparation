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


bool isIdentical(node* root1,node* root2){

    if(root2 == NULL and root2 == NULL) {
        return true;
    }else if(root1 == NULL || root2 == NULL){
        return false;
    }else{
        bool c1 = root1->val == root2->val;
        bool c2 = isIdentical(root1->left,root2->left);
        bool c3 = isIdentical(root1->right,root2->right);

        if (c1 and c2 and c3){
            return true;
        }

        return false;
    }
}

int main(){
    
    node* root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);

    node* root2 = new node(2);
    root2->left = new node(1);
    root2->right = new node(3);

    if(isIdentical(root1,root2)){
        cout << "BSTs are identical" << endl;
    }else{
        cout << "not identical" << endl;
    }
    
    return 0;
}