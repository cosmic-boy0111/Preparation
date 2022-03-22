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

int calculateHeight(node* root){

    if(root == NULL)
        return 0;

    return max(calculateHeight(root->left),calculateHeight(root->right)) + 1;
}

int calcDiameter(node* root){

    if(root == NULL){
        return 0;
    }

    int lHeight = calculateHeight(root->left);
    int rHeight = calculateHeight(root->right);

    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);

    return max(currDiameter,max(lDiameter,rDiameter));

}

int calcDiameterOpt(node* root,int* height){

    if(root == NULL){
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calcDiameterOpt(root->left,&lh);
    int rDiameter = calcDiameterOpt(root->right,&rh);

    int currDiameter = lh+rh+1;
    *height = max(lh,rh)+1;

    return max(currDiameter,max(lDiameter,rDiameter));
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << calculateHeight(root) << endl;
    cout << calcDiameter(root) << endl;

    int height = 0;
    cout << calcDiameterOpt(root,&height);
    
    return 0;
}