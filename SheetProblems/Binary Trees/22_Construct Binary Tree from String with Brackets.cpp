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

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int data = 0){
            val = data;
            left = NULL;
            right = NULL;
        }
};

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int data = 0){
            val = data;
            next = NULL;
        }
};

void insertAtTail(ListNode* &root,int val){
    if(root == NULL){
        root = new ListNode(val);
        return;
    }
    ListNode* temp = root;
    while (temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new ListNode(val); 
}

void display(ListNode* root){
    while (root != NULL){
        cout << root->val << " ";
        root = root->next;
    }

    cout << endl;

}


#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>

vector<int> adj[N];
vector<bool> visited(N,false);

TreeNode* construct(string s){
    if(s.empty()) return NULL;
    stack<TreeNode*> st;
    TreeNode* root = new TreeNode(s[0]-'0');
    st.push(root);
    int i = 1;
    while (!st.empty() and i < s.size()){
        if(s[i] == '('){
            int t = s[i+1]-'0';
            TreeNode* temp = st.top();
            if(temp->left == NULL){
                temp->left = new TreeNode(t);
                st.push(temp->left);
            }else{
                temp->right = new TreeNode(t);
                st.push(temp->right);
            }
        }else if(s[i] == ')'){
            st.pop();
        }

        i++;
    }
    
    return st.top();
}


void show(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    show(root->left);
    show(root->right);
}

int32_t main(){
    


    string s;
    cin >> s;

    show(construct(s));

    
    
    return 0;
}