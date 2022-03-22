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

node* bstFromPreorder(vector<int>& preorder) {
    stack<node* > st;
    int i = 0;
    node* root = new node(preorder[i++]);
    node* p = root;
    int n = preorder.size();
    while (i < n){

        if(preorder[i] < p->val){
            node* temp = new node(preorder[i++]);
            p->left = temp;
            st.push(p);
            p = temp;
        }else{
            if(preorder[i] > p->val and preorder[i] < (st.empty()?INT_MAX:st.top()->val)){
                node* temp = new node(preorder[i++]);
                p->right = temp;
                p = temp;
            }else{
                p = st.top();
                st.pop();
            }
        }

    }

    return root;
    
}

int main(){
   
    
    
    return 0;
}