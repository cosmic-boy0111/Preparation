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

void traval(TreeNode* root,vector<int> adj[]){
    if(!root) return;
    if(root->left){
        adj[root->val].push_back(root->left->val);
        adj[root->left->val].push_back(root->val);
    }
    if(root->right){
        adj[root->val].push_back(root->right->val);
        adj[root->right->val].push_back(root->val);
    }

    traval(root->left,adj);
    traval(root->right,adj);

}

unordered_map<int,int> mp;

int solve(vector<int> adj[],int index,vector<int>& vis,unordered_set<int>& st,int count){
    if(st.find(index) != st.end()){
        mp[index] = 1;
        
    }
}

int countPairs(TreeNode* root, int distance) {
    
    vector<int> adj[110];
    traval(root,adj);
    unordered_set<int> st;
    for(int i=1;i<110;i++){
        if(adj[i].size() == 1) st.insert(i);
    }
    int ans = 0;
    vector<int> vis(110,0);
    for(auto &x : st){
        mp[x] = 1;
    }


}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }



    return 0;
}