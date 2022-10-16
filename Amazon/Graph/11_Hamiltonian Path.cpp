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

bool solve(int index,int N,vector<int> adj[],vector<int>& vis){

    vis[index] = 1;
    for(auto &x : adj[index]){
        if(vis[x]) continue;
        if(solve(x,N-1,adj,vis)) return true;
    }

    vis[index] = 0;
    if(N == 0) return true;
    return false;

}

bool check(int N,int M,vector<vector<int>> Edges){
    vector<int> adj[N+1];
    for(auto &x : Edges){
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    vector<int> vis(N+1,0);
    for(int i=1;i<=N;i++){
        if(solve(i,N-1,adj,vis)) return true;
    }

    return false;
}

int32_t main(){
    long long T;
    cin >> T;
    while(T--){
        
    }



    return 0;
}