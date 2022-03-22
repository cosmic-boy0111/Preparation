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

node* constructMaximumBinaryTree(vector<int>& nums) {
    stack<node*> st;
    node* root = NULL;
    int maxVal = -1;
    for(int i=0;i<nums.size();i++){
        node* temp = NULL;
        while (!st.empty() and st.top()->val < nums[i]){
            temp = st.top();
            st.pop();
        }

        node* n = new node(nums[i]);
        if(st.empty()){
            n->left = temp;
        }else{
            st.top()->right = n;
            n->left = temp;
        }
        
        if(maxVal < n->val ){
            maxVal = n->val;
            root = n;
        }
        st.push(n);

    }

    return root;
}

int main(){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v)
        cin >> i;

    node* root = constructMaximumBinaryTree(v);
    
    return 0;
}