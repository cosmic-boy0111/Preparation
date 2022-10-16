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

void traval(TreeNode* root,vector<pair<int,char>> adj[]){
    if(!root) return;
    if(root->left){
        adj[root->val].push_back({root->left->val,'L'});
        adj[root->left->val].push_back({root->val,'U'});
    }
    if(root->right){
        adj[root->val].push_back({root->right->val,'R'});
        adj[root->right->val].push_back({root->val,'U'});
    }

    traval(root->left,adj);
    traval(root->right,adj);

}

string ans = "";
void solve(vector<pair<int,char>> adj[],vector<int>& vis,int index,int destValue,string temp){
    if(index == destValue){
        if(ans.size() == 0) ans = temp;
        if(ans.size() > temp.size()) ans = temp;

        return;
    }

    vis[index] = 1;
    for(auto &x : adj[index]){
        if(vis[x.first]) continue;
        temp.push_back(x.second);
        solve(adj,vis,x.first,destValue,temp);
        temp.pop_back();
    }

}

string getDirections(TreeNode* root, int startValue, int destValue) {
    int T = 1e5+10;
    vector<pair<int,char>> adj[T];
    traval(root,adj);
    vector<int> vis(T,0);
    solve(adj,vis,startValue,destValue,"");

    return ans;

}

int32_t main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << getDirections(root,3,2);


    return 0;
}