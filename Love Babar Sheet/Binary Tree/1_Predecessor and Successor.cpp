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

void travel(TreeNode* root, vector<pair<int,TreeNode*>> & v){

    if(! root) return;
    travel(root->left,v);
    v.push_back({root->val,root});
    travel(root->right,v);

}

void findPreSuc(TreeNode* root, TreeNode*& pre, TreeNode*& suc, int key){
    
    vector<pair<int,TreeNode*>> v;
    travel(root,v);

    if(key < v[0].first){
        pre = NULL;
        suc = v[0].second;
    }else if(key > v[v.size()-1].first){
        pre = v[v.size()-1].second;
        suc = NULL;
    }else{
        int indx1 = 0;
        int indx2 = 0;
        pre = v[0].second;
        suc = v[0].second;
        for(int i=0;i<v.size();i++){
            if(v[indx1].first < v[i].first and v[i].first < key) pre = v[i].second;
            if(v[indx1].first > v[i].first and v[i].first > key) suc = v[i].second;
        }

    }

}

int32_t main(){
    

    return 0;
}