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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data){
            val = data;
            left = NULL;
            right = NULL;
        }
};


vector<TreeNode*> allPossibleFBT(int n) {
    
    if(n%2 == 0){
        return {};
    }

    vector<TreeNode*> ans;
    if(n == 1){
        TreeNode* ri = new TreeNode(0);
        ans.push_back(ri);
    }

    for(int i=1;i<n;i+=2){
        vector<TreeNode*> leftTrees = allPossibleFBT(i);
        vector<TreeNode*> rightTrees = allPossibleFBT(n-i-1);

        for(auto &lt : leftTrees){
            for(auto &rt : rightTrees){
                TreeNode* root = new TreeNode(0);
                root->left = lt;
                root->right = rt;

                ans.push_back(root);
            }
        }
    }

    return ans;

}


int main(){
   
    int n;
    cin >> n;

    vector<TreeNode*> ans  = allPossibleFBT(n);
    
    return 0;
}