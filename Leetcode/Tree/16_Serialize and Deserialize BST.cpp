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

vector<pair<int,int>> pos = {
    {0,-1},{-1,0},{0,1},{1,0},
    {-1,-1},{-1,1},{1,1},{1,-1}
};


void travel(TreeNode* root ,string &s){
    if(! root) return;
    s.append(to_string(root->val) + '#');
    travel(root->left,s);
    travel(root->right,s);
}

string serialize(TreeNode* root) {
    string ans = "";
    travel(root,ans);
    return ans;
}


  
stack<int> st;
unordered_map<int,int> mp;

TreeNode* solve(int start, int end){
    if(start > end)
        return NULL;
    if(start == end){
        TreeNode* n = new TreeNode(st.top());
        st.pop();
        return n;
    }
    int t = st.top();
    st.pop();
    int i = mp[t];
    TreeNode* root = new TreeNode(t);
    root->left = solve(start,i-1);
    root->right = solve(i+1,end);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for(int i=preorder.size()-1;i>=0;i--)
        st.push(preorder[i]);
    for(int i=0;i<inorder.size();i++)
        mp[inorder[i]] = i;
    return solve(0,inorder.size()-1);
    
}


TreeNode* deserialize(string data) {
    vector<int> preorder;
    string temp = "";
    for(auto &x : data){
        if(x == '#'){
            preorder.push_back(stoi(temp));
            temp = "";
            continue;
        }
        temp.push_back(x);
    }

    vector<int> inorder = preorder;
    sort(inorder.begin(),inorder.end());


    return buildTree(preorder,inorder);

}

int32_t main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    cout << serialize(root) << endl;
    TreeNode* t = deserialize(serialize(root));




    return 0;
}