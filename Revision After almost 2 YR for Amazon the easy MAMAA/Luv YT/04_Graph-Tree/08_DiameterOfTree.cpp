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
        node* next;
        node* prev;
        node* left;
        node* right;

        node(int data = 0){
            val = data;
            next = NULL;
            prev = NULL;
            left = NULL;
            right = NULL;
        }
};

node* makeTree(vector<int>& v){
    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);

    int i = 1;
    while (i < v.size()){
        node* curr = q.front();
        q.pop();
        if(i < v.size() && v[i] != -1){
            curr->left = new node(v[i]);
            q.push(curr->left);
        }
        i++;
        if(i < v.size() && v[i] != -1){
            curr->right = new node(v[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

#define minHeapInt priority_queue<int,vector<int>,greater<int>>
#define maxHeapInt priority_queue<int,vector<int>>
#define minHeapPair priority_queue<pi,vector<pi>,greater<pi>>
#define maxHeapPair priority_queue<pi,vector<pi>>


vector<int> adj[N];
bool vis[N];
int depth[N];

void dfs(int vertex, int par = -1){
    // enterring vertex
    for(auto& x : adj[vertex]){
        if(x == par) continue;
        // entering the child
        depth[x] = depth[vertex] + 1;
        dfs(x, vertex);
        // leaving the child
    }
    // leaving the vertex
}

int32_t main(){

    int n , m;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int x , y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1);

    int max_depth_node;
    int mx_depth = -1;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx_depth){
            max_depth_node = i;
            mx_depth = depth[i];
        }
        depth[i] = 0;
    }

    dfs(max_depth_node);
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx_depth){
            max_depth_node = i;
            mx_depth = depth[i];
        }
    }
    cout << mx_depth << endl;
}